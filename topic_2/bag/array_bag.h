#include "bag.h"

#include <stdexcept>

#ifndef ARRAY_BAG_H
#define ARRAY_BAG_H

#define DEFAULT_SIZE 128
#define SCALING_FACTOR 2

template<typename T>
class ArrayBag : Bag<T> 
{
public:

    ~ArrayBag() { delete[] store; }

    ArrayBag() : ArrayBag(DEFAULT_SIZE) {}

    ArrayBag(const size_t initialSize) : count{0}, currentSize{initialSize}, store{new T[initialSize]} {}

    // adds an item to the bag
    void add(const T& item) 
    {
        if(count == currentSize) resize();

        store[count++] = item;
    }

    // removes an item from the bag and returns it
    // throws a runtime exception if the bag is empty or the item is not in the bag
    T remove(const T& item) 
    {
        int ptr{contains(item,0)};

        if(ptr < 0) throw std::runtime_error("remove on bag; item does not exist");
        T rtnItem = store[ptr];
        store[ptr] = store[--count];

        return rtnItem;
    }

    // returns the count of items in the bag
    size_t size() const
    {
        return count;
    }

    // returns an arbitrary item from the bag
    // throws a runtime exception if the bag is empty
    T grab() const
    {
        if(count == 0) throw std::runtime_error("grab on an empty bag");

        return store[0];
    }

    // returns true if the bag contains the item or false otherwise
    bool contains(const T& item) const 
    {
        if(contains(item, 0) > -1) return true; 
        return false;
    }
private:
    T* store;
    size_t currentSize;
    size_t count;

    int contains(const T& item, size_t ptr) const 
    {
        if(store[ptr] == item) return ptr;

        if (ptr == count) return -1;
        
        return contains(item, ptr + 1);
    }

    void resize()
    {
        currentSize *= SCALING_FACTOR;
        T* newStore{new T[currentSize]};
        
        for (size_t i = 0; i < count; ++i) 
            newStore[i] = store[i];
        
        delete[] store;

        store = newStore;
    }

};

#endif