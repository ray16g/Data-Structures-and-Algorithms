#include "heap.h"
#include "array_heap.h"

#include "priority_queue.h"

#include "../test.h"


void testMaxHeap(Heap<int>* heap)
{
    equals<bool>(true, heap->empty(), "Empty on empty maxheap");
    heap->add(5);
    equals<int>(5, heap->get(), "Add 5 to maxheap");
    equals<bool>(false, heap->empty(), "Empty() on non-empty maxheap");

    heap->add(3);
    equals<int>(5, heap->get(), "Added 3 to maxheap");
    heap->add(7);
    equals<int>(7, heap->get(), "Add 7 to maxheap");

    heap->remove();
    equals<int>(5, heap->get(), "Removed 7 from maxheap");
    
    for (size_t i = 1; i <= 50; i++)
    {
        heap->add(i);
    }
    equals<int>(50, heap->get(), "Added 1-50 to maxheap");
    for (size_t i = 0; i < 10; i++)
    {
        heap->remove();
    }
    equals<int>(40, heap->get(), "Removed 10 items from maxheap");
    heap->clear();
    equals<bool>(true, heap->empty(), "Empty on cleared maxheap");
}

void testMinHeap(Heap<int>* heap)
{
    equals<bool>(false, heap->empty(), "Empty() on non-empty minheap");
    equals<int>(-15, heap->get(), "get() on minheap");
    heap->remove();
    equals<int>(-5, heap->get(), "remove() on minheap");
}

void testPriorityQueue(PriorityQueue<int>* pq)
{
    for (size_t i = 1; i <= 100; i++)
    {
        pq->enqueue(i);
    }
    equals<int>(100, pq->front(), "Added 1-100 to Priority Queue");
    for (size_t i = 0; i < 10; i++)
    {
        pq->dequeue();
    }
    equals<int>(90, pq->front(), "Removed 10 items from maxheap");

}

int main(int argc, char const *argv[])
{
    Heap<int>* maxHeap {new ArrayHeap<int>(
        [] (const int& l, const int& r) { return l > r; } // heap | l = parent, r = child
    )};
    testMaxHeap(maxHeap);

    int arr[10] = {1,3,4,6,2,5,-15,10,9,-5};

    Heap<int>* minHeap {new ArrayHeap<int>(
        [] (const int& l, const int& r) { return l < r; } // heap | l = parent, r = child
    , arr, 10)};

    testMinHeap(minHeap);

    PriorityQueue<int>* pq {new PriorityQueue<int>(
        [] (const int& l, const int& r) { return l > r; } // heap | l = parent, r = child
    )};

    testPriorityQueue(pq);

    return 0;
}
