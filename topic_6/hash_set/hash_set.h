#include <cstddef>
#include <functional>
#include <stdexcept>

#include "set.h"

#ifndef HASH_SET_H
#define HASH_SET_H

#define DEFAULT_SIZE 271
#define PROBING_ATTEMPTS 27
#define SCALING_FACTOR 2

enum class Prober { LINEAR, QUADRATIC };

enum class State { Empty, Free, Used };

template<typename T>
struct Entry
{
    T item;
    State state;
};

template<typename T>
class HashSet : public Set<T>
{
    using HASHER = std::function<size_t(const T&)>;
    using COMPARATOR = std::function<bool(Entry<T>)>;
public:
    HashSet(HASHER hasher) : HashSet(hasher, Prober::LINEAR) { }
    HashSet(HASHER hasher, Prober prober) 
        : currentSize{DEFAULT_SIZE}, count{0}, hasher{hasher}, store{new Entry<T>[DEFAULT_SIZE]}, prober{prober} { }


    /** adds an item to the set. 
     *  throws an runtime error if the item already a member
    */
    void add(const T& item)
    {
        if(contains(item)) throw std::runtime_error("add on HashSet with existing member");

        // if size() > currentSize * 0.75
        if(size() > (currentSize >> 1 + currentSize >> 2)) resize();

        int idx{probe(hasher(item) % currentSize, [=](Entry<T> entry) { return entry.state == State::Empty || entry.state == State::Free; })};

        if(idx > 0)
        {
            Entry<T> entry = new Entry<T>{item, State::Used};
            store[idx] = entry;
            ++count;
        }
            
    }

    /** removes the item from the set
     *  throws a runtime error if the item is not a member
    */
    T remove(const T& item)
    {
        int idx{probe(hasher(item) % currentSize, [=](Entry<T> entry) { return entry.state == State::Used && entry.item == item; })};

        if(idx < 0) throw std::runtime_error("Remove on item that is not a member of set");

        store[idx].state = State::Free;
        --count;

        return item;
    }

    /** returns true if the set is empty or false otherwise */
    bool empty() const
    {
        return count == 0;
    }

    /** returns true if the item is a member or false otherwise */
    bool contains(const T& item) const
    {
        int idx{probe(hasher(item) % currentSize, [=](Entry<T> entry) { return entry.state == State::Used && entry.item == item; })};

        return idx > 0;
    }

    /** returns the number of members in the set */
    size_t size() const
    {
        return count;
    }

private:
    Entry<T>* store;
    size_t currentSize;
    size_t count;
    HASHER hasher; 
    Prober prober;

    int probe(const T& key, COMPARATOR comparator)
    {
        switch (prober)
        {
        case Prober::LINEAR:
            return linearProbe(key, comparator);
        default:
            return quadraticProbe(key, comparator);
        }
    }

    int linearProbe(size_t hcode, COMPARATOR comparator)
    {
        int idx;
        for(int i = 0; i < PROBING_ATTEMPTS; ++i)
        {
            idx = (hcode + i) % currentSize;
            if(comparator(store[idx])) 
                return idx;
        }
        return -1;
    }

    int quadraticProbe(size_t hcode, COMPARATOR comparator)
    {
        int idx;
        for(int i = 0; i < PROBING_ATTEMPTS; ++i)
        {
            idx = (hcode + i * i) % currentSize;
            if(comparator(store[idx])) 
                return idx;
        }
        return -1;
    }

    void resize()
    {
        size_t newSize{ currentSize * SCALING_FACTOR };
        Entry<T>* newStore{new Entry<T>[newSize]};
        
        for (size_t i = 0; i < count; ++i) 
            newStore[i] = store[i];
        
        delete[] store;

        currentSize = newSize;
        store = newStore;
    }
};

#endif /* HASH_SET_H */
