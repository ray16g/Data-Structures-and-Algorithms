#include "heap.h"
#include "array_heap.h"
#include "test.h"

int values[]{1,2,3,4,5,6,7,8,9,10};
int valuesSize{sizeof(values) / sizeof(values[0])};
int value{55};

/** add an item to the heap */
void testAdd(Heap<int>*);

/** remove the extrema item from the heap
 *  throws runtime error if the heap is empty
*/
void testRemove(Heap<int>*);

/** get the extrema item from the heap without removing it 
 *  throws runtime error if the heap is empty
*/
void testGet(Heap<int>*);

/** returns true if heap is empty or false otherwise*/
void testEmpty(Heap<int>*);

bool maxComparator(const int& l, const int& r)
{
    return l > r;
}

bool minComparator(const int& l, const int& r)
{
    return l < r;
}
int main(int argc, char const *argv[])
{
    
    Heap<int>* heap {new ArrayHeap<int>(
        maxComparator
    )};

    /** add an item to the heap */
    testAdd(heap);
    heap->clear();
    /** remove the extrema item from the heap
     *  throws runtime error if the heap is empty
    */
    testRemove(heap);
    heap->clear();
    /** get the extrema item from the heap without removing it 
     *  throws runtime error if the heap is empty
    */
    testGet(heap);
    heap->clear();
    /** returns true if heap is empty or false otherwise*/
    testEmpty(heap);
    heap->clear();


    return 0;
}

/** add an item to the heap */
void testAdd(Heap<int>* heap)
{
    for(const int& i : values)
        heap->add(i);
    heap->add(value);
    equals<bool>(false, heap->empty(), "testAdd: heap not empty after add");
}

/** remove the extrema item from the heap
 *  throws runtime error if the heap is empty
*/
void testRemove(Heap<int>* heap)
{
    heap->add(value);
    heap->remove();

    equals<bool>(true, heap->empty(), "testRemove: removed last item in heap");
}

/** get the extrema item from the heap without removing it 
 *  throws runtime error if the heap is empty
*/
void testGet(Heap<int>* heap)
{
    for(const int& i : values)
        heap->add(i);
    
    for (size_t i = valuesSize; i > 0; --i)
    {
        equals<bool>(true, i == heap->get(), "testGet: get values in correct order");
        heap->remove();
    }
    
}

/** returns true if heap is empty or false otherwise*/
void testEmpty(Heap<int>* heap)
{
    equals<bool>(true, heap->empty(), "testEmpty on empty heap");
}