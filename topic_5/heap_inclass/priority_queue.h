#include <functional>
#include "array_heap.h"

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

template<typename T>
class PriorityQueue
{
public:
    PriorityQueue(std::function<bool(const T&, const T&)> comparator)
       : queue{ArrayHeap<T>(comparator)} { }

    void enqueue(const T& item) { heap.add(item); }
    void dequeue() 
    {
        try
        {
            heap.remove()
        }
        catch(const std::runtime_error&)
        {
            throw std::runtime_error("Dequeue on empty queue");
        }
    }   
    T front() 
    {
        try
        {
            return heap.get()
        }
        catch(const std::runtime_error&)
        {
            throw std::runtime_error("Front on empty queue");
        }
    }
    bool empty() { return heap.empty(); }
    void clear() { heap.clear(); }
private:
    ArrayHeap<T> heap;
};

#endif /* PRIORITY_QUEUE_H */
