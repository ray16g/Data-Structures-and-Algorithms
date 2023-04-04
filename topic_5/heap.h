#ifndef HEAP_H
#define HEAP_H

template<typename T>
struct Heap
{
    /** destructor */
    virtual ~Heap() {}

    /** add an item to the heap */
    virtual void add(const T&) = 0;

    /** remove the extrema item from the heap
     *  throws runtime error if the heap is empty
    */
    virtual void remove(const T&) = 0;

    /** get the extrema item from the heap without removing it 
     *  throws runtime error if the heap is empty
    */
    virtual T get(const T&) const = 0;

    /** returns true if heap is empty or false otherwise*/
    virtual bool empty() const = 0;

    /** clears the heap of its contents */
    virtual void clear() = 0;
};

#endif
