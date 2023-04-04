#include "heap.h"
#include <stdexcept>
#include <functional>

#ifndef ARRAY_HEAP
#define ARRAY_HEAP

#define COMPARATOR std::function<bool(const T&, const T&)>
#define DEFAULT_SIZE 128
#define SCALING_FACTOR 2

template<typename T>
class ArrayHeap : public Heap<T>
{
public:
    ArrayHeap(COMPARATOR comparator) : ArrayHeap<T>(comparator, DEFAULT_SIZE) {}

    ArrayHeap(COMPARATOR comparator, size_t initialSize) 
        : currentSize{initialSize}, store{new T[initialSize]}, count{0}, comparator{comparator}  {}    

    /** creates a store that is 2x the size of the array provided
     * all elements from the provided array are copied into store
     * call heapify on store
    */
    ArrayHeap(COMPARATOR comparator, const T* array, size_t size)
        : currentSize{size << 1}, store{new T[size << 1]}, count{size}, comparator{comparator} 
        {
            for(int i{0}; i < size; ++i)
                store[i] = array[i];

            heapify();
        }


    /** destructor */
    ~ArrayHeap() {}

    /** add an item to the heap */
    void add(const T& item) {}

    /** remove the extrema item from the heap
     *  throws runtime error if the heap is empty
    */
    void remove(const T& item) {}

    /** get the extrema item from the heap without removing it 
     *  throws runtime error if the heap is empty
    */
    T get(const T& item) const 
    {
        return T{};
    }

    /** returns true if heap is empty or false otherwise*/
    bool empty() const 
    {
        return false;
    }

    /** clears the heap of its contents */
    void clear() {}

private:
    T* store;
    size_t currentSize;
    size_t count;
    COMPARATOR comparator;

    void upheap() {}

    void downheap() {}

    void heapify() {}

    void resize() {}

};

#endif