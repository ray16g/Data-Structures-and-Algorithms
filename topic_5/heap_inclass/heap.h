#ifndef HEAP_H
#define HEAP_H

template<typename T>
struct Heap
{
    // destructor
    virtual ~Heap() { }
    
    /** add an item to the heap */
    virtual void add(const T&) = 0;

    /** Remove the extrema item from the heap 
     * throws runtime error if the heap is empty
    */
    virtual void remove() = 0;

    /** get the extrema item from the heap withour removing it 
     * throws runtime error if the heap is empty
    */
    virtual T get() const = 0;

    /** return true if empty or false otherwise */
    virtual bool empty() const = 0;
    
    /** clear the heap of its contents */
    virtual void clear() = 0;
};

#endif /* HEAP_H */
