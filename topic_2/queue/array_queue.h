#include <stdexcept>
#include <iostream>

#include "queue.h"

#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#define DEFAULT_SIZE 128
#define SCALING_FACTOR 2

template<typename T>
class ArrayQueue : public Queue<T>
{

public:

    ArrayQueue() : size{DEFAULT_SIZE}, first{0}, back{0}, count{0}, store{new T[DEFAULT_SIZE]}  {}

    ~ArrayQueue() { delete[] store; }

    /* Adds an item to the back of the queue */
    void enqueue(const T& item) 
    {
        if(back + first >= size)
            resize();

        if(back >= size)
            back = 0;

        count++;
        store[back++] = item; 
    }

    /* Removes an item from the queue */
    void dequeue() 
    {
        if(empty()) throw std::runtime_error("Attempted dequeue on empty queue");

        first++;
        count--;
        if(first >= size) 
            first = 0;
    }

    /* Returns but does not remove the item at the front of the queue */
    T front() const 
    { 
        if(empty()) throw std::runtime_error("Attempted front on empty queue");

        return store[first]; 
    }

    /* Returns true if the queue is empty, else returns false */
    bool empty() const { return count == 0; }
 
    /* Empties the queue */
    void clear() 
    {
        delete[] store;

        store = new T[DEFAULT_SIZE];
        first, back, count = 0;
    }

private:

    void resize() 
    {
        size_t newSize{ size * SCALING_FACTOR };
        T* newStore{new T[newSize]};
        
        for (size_t i = 0; i < count; ++i) 
            newStore[i] = store[(first + i) % size];
        
        delete[] store;

        size = newSize;
        back = first + back;
        first = 0;
        store = newStore;
    }

    size_t size;    // size of array
    size_t first;   // points to the front element
    size_t back;    // points to the next available space in the back
    size_t count;   // amount of elements in queue, used for empty() and resize()
    T* store;       // array to store elementes
};

#endif