#include <cstddef>
#include <functional>
#include <stdexcept>

#include "set.h"

#ifndef HASH_SET_H
#define HASH_SET_H

#define DEFAULT_SIZE 271
#define SCALING_FACTOR 2
#define LOAD_FACTOR 0.75
#define PROBING_LIMIT 27

enum ProbeType
{
    LINEAR,
    QUADRATIC
};

enum Status
{
    EMPTY,
    FREE,
    USED
};

template<typename T>
class HashSet : public Set<T>
{

    using Hasher = std::function<size_t(const T&)>;

public:
    HashSet(Hasher hasher) : HashSet(hasher, LINEAR) { }
    HashSet(Hasher hasher, ProbeType probeType) : hasher{hasher}, probeType{probeType}, count{0}, 
        currentSize{DEFAULT_SIZE}, store{new T[DEFAULT_SIZE]}, status{new Status[DEFAULT_SIZE]{}}
        {}

    ~HashSet() { delete[] store; delete[] status; }

    /** adds an item to the set. 
     *  throws an runtime error if the item already a member
    */
    void add(const T& item)
    {
        if(count >= currentSize * LOAD_FACTOR) resize();

        int idx{probe(item)};

        if(idx == -1) throw std::runtime_error("probing exhausted");

        if(status[idx] == USED) throw std::runtime_error("item already exists");

        store[idx] = item;
        status[idx] = USED;
        ++count;
    }

    /** removes the item from the set
     *  throws a runtime error if the item is not a member
    */
    T remove(const T& item)
    {
        int idx{probe(item)};

        if(idx == -1 || status[idx] != USED) 
            throw std::runtime_error("item is not a member");

        status[idx] = FREE;

        --count;

        return store[idx];
    }

    /** returns true if the set is empty or false otherwise */
    bool empty() const
    {
        return count == 0;
    }

    /** returns true if the item is a member or false otherwise */
    bool contains(const T& item) const
    {
        int idx{probe(item)};

        if(status[idx] == USED) return true;

        return false;
    }

    /** returns the number of members in the set */
    size_t size() const
    {
        return count;
    }

private:
    T* store;
    Status* status;
    size_t currentSize;
    size_t count;
    Hasher hasher;
    ProbeType probeType;

    size_t f(const size_t i) const 
    {
        switch (probeType)
        {
        case LINEAR:
            return i;
            break;
        
        default:
            return i*i;
            break;
        }
    }

    size_t probe(const T& item) const
    {
        int freeIdx{-1};
        size_t hashcode{hasher(item)};

        for (size_t i = 0; i < PROBING_LIMIT; ++i)
        {
            int idx{(hashcode + f(i)) % currentSize};
            if(freeIdx == -1 && status[idx] != USED) freeIdx = idx;

            if(status[idx] == EMPTY)
                break;

            if(status[idx] == USED && store[idx] == item)
                return idx;

        }

        return freeIdx;
    }

    void resize()
    {
        size_t oldSize{currentSize};
        T* oldStore{store};
        Status* oldStatus{status};
        count = 0;

        currentSize *= SCALING_FACTOR;

        store = new T[currentSize];
        status = new Status[currentSize]{};

        for (size_t i = 0; i < oldSize; ++i)
        {
            if(oldStatus[i] == USED)
                add(oldStore[i]);
        }

        delete[] oldStore;
        delete[] oldStatus;
    }
};

#endif /* HASH_SET_H */
