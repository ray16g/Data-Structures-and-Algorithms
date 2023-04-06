#include <stdexcept>
#include <functional>

#include "heap.h"

#ifndef ARRAY_HEAP_H
#define ARRAY_HEAP_H

// #define COMPARATOR std::function<bool(const T&, const T&)>
#define DEFAULT_SIZE 128
#define SCALING_FACTOR 2

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
    ArrayHeap(COMPARATOR comparator, const T* array, size_t size)
        : currentSize{size << 1}, store{new T[size << 1]}, count{size}, comparator{comparator} 
    {
        for(size_t i{1}; i < size; ++i)
            store[i + 1] = array[i];
        heapify();
    }

    // destructor
    ~ArrayHeap() { delete[] store; }
    
    /** add an item to the heap */
    void add(const T& item)
    {
        count++;
        if(currentSize < count)
            resize();
        
        store[count] = item;
        upheap(count >> 1); // up heap on parent
    }

    /** Remove the extrema item from the heap 
     * throws runtime error if the heap is empty
    */
    void remove()
    {
        if(empty()) throw std::runtime_error("remove() on empty heap");

        T root = store[1];
        store[1] = store[count];
        count--;
        if(count != 0)
            downheap(1);
    }

    /** get the extrema item from the heap without removing it 
     * throws runtime error if the heap is empty
    */
    T get() const
    {
        if(empty()) throw std::runtime_error("get() on empty heap");

        return store[1];
    }

    /** return true if empty or false otherwise */
    bool empty() const
    {
        return count == 0;
    }
    
    /** clear the heap of its contents */
    void clear()
    {
        delete[] store;

        store = new T[DEFAULT_SIZE];
        count = 0;
    }

private:
    T* store;
    size_t currentSize;
    size_t count;
    COMPARATOR comparator;

    bool compare(int idx1, int idx2)
    {
        return comparator(store[idx1], store[idx2]);
    }

    void swap(int pos1, int pos2)
    {
        T temp = store[pos1];
        store[pos1] = store[pos2];
        store[pos2] = temp;
    }

    void upheap(const int pos) 
    {
        if(pos == 0) 
            return;

        int leftChild{pos << 1};
        int rightChild{(pos << 1) + 1};

        if(leftChild <= count)
        {
            if(compare(leftChild, pos))
            {
                swap(pos, leftChild);
                upheap(pos >> 1);
            }
        }
        if(rightChild <= count)
        {
            if(compare(rightChild, pos))
            {
                swap(pos, rightChild);
                upheap(pos >> 1);
            }
        }
    } 

    void downheap(const int pos)
    {
        if(pos > count)
            return;
        
        int leftChild{pos << 1};
        int rightChild{(pos << 1) + 1};

        if(leftChild <= count)
        {
            if(compare(leftChild, pos))
            {
                swap(pos, leftChild);
                downheap(leftChild);
            }
        }
        if(rightChild <= count)
        {
            if(compare(rightChild, pos))
            {
                swap(pos, rightChild);
                downheap(rightChild);
            }
        }
    }

    void heapify()
    {
        size_t idx{(count - 1) >> 1};
        idx += (((count - 1) & 1)) ? 1 : 0;

        for(size_t i{idx}; i > 0; --i)
        {
            upheap(i);
        }
    }

    void resize()
    {
        size_t newSize{ currentSize * SCALING_FACTOR };
        T* newStore{new T[newSize]};
        
        for (size_t i = 0; i < count; ++i) 
            newStore[i] = store[i];
        
        delete[] store;

        currentSize = newSize;
        store = newStore;
    }
};

#endif /* ARRAY_HEAP_H */
