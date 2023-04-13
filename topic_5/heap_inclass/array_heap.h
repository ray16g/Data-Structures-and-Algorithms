#include <stdexcept>
#include <functional>

#include "heap.h"

#ifndef ARRAY_HEAP_H
#define ARRAY_HEAP_H

// #define COMPARATOR std::function<bool(const T&, const T&)>
#define DEFAULT_SIZE 128
#define SCALING_FACTOR 2
#define ROOT 1

template<typename T>
class ArrayHeap : public Heap<T>
{
public:
using COMPARATOR = std::function<bool(const T&, const T&)>;

    ArrayHeap(COMPARATOR comparator) : ArrayHeap<T>(comparator, DEFAULT_SIZE) { }

    ArrayHeap(COMPARATOR comparator, size_t initialSize) 
        : currentSize{initialSize}, store{new T[initialSize]}, count{0}, comparator{comparator}
    { }

    /** creates a atore that is 2x the size of the array provided 
     * all elements from the provided array are copied into store
     * call heapify on store
    */
    ArrayHeap(COMPARATOR comparator, const T array, size_t size) 
        : currentSize{size << 1}, store{new T[size << 1]}, count{size}, comparator{comparator}
    { 
        for (size_t i = 0; i < count; ++i)
            store[i + 1] = array[i];
        heapify();
        
    }

    // destructor
    ~ArrayHeap() { delete[] store; }
    
    /** add an item to the heap */
    void add(const T& item)
    {
        if(count >= currentSize) 
            resize();
        
        store[++count] = item;

        upheap(count >> 1);
    }

    /** Remove the extrema item from the heap 
     * throws runtime error if the heap is empty
    */
    void remove()
    {
        if(empty()) throw std::runtime_error("remove on empty heap");

        store[ROOT] = store[count--];
        downheap(ROOT);
    }

    /** get the extrema item from the heap withour removing it 
     * throws runtime error if the heap is empty
    */
    T get() const
    {
        if(empty()) throw std::runtime_error("get on empty heap");

        return store[ROOT];
    }

    /** return true if empty or false otherwise */
    bool empty() const
    {
        return count == 0;
    }
    
    /** clear the heap of its contents */
    void clear()
    {
        count = 0;
    }

private:
    T* store;
    size_t currentSize;
    size_t count;
    COMPARATOR comparator;

    void upheap(size_t parent) 
    {
        size_t extrema{};
        if(parent < ROOT) return;

        extrema = getExtrema(parent);
        if(extrema != parent)
        {
            swap(parent, extrema);
            upheap(parent >> 1);
        }
    } 

    void downheap(size_t parent)
    {
        if(isLeaf(parent)) return;

        size_t extrema = getExtrema(parent);
        if(extrema != parent)
        {
            swap(parent, extrema);
            downheap(extrema);
        }
    }

    void heapify()
    {
        size_t lastNonLeaf{ (count - 1) >> 1};
        lastNonLeaf += ((count - 1) & 1);

        for (size_t i = lastNonLeaf; i >= ROOT; --i)
        {
            downheap(i);
        }
        
    }

    void resize()
    {

    }

    void swap(size_t l, size_t r)
    {
        T temp{store[l]};
        store[l] = store[r];
        store[r] = temp;
    }

    size_t getExtrema(size_t parent)
    {
        size_t extrema{parent};
        size_t lc{parent << 1};
        size_t rc{lc + 1};

        if(lc <= count)
            extrema = compare(extrema, lc);

        if(rc <= count)
            extrema = compare(extrema, rc);

        return extrema;
    }

    size_t compare(size_t l, size_t r)
    {
        return comparator(store[l], store[r]) ? l : r;
    }

    bool isLeaf(size_t parent)
    {
        return ((parent << 1) > count);
    }
};

#endif /* ARRAY_HEAP_H */
