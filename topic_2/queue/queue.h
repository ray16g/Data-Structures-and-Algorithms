#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
struct Queue 
{
    virtual ~Queue() {}

    /* Adds an item to the back of the queue */
    virtual void enqueue(const T&) = 0;

    /* Removes an item from the queue */
    virtual void dequeue() = 0;

    /* Returns but does not remove the item at the front of the queue */
    virtual T front() const = 0;

    /* Returns true if the queue is empty, else returns false */
    virtual bool empty() const = 0;

    /* Empties the queue */
    virtual void clear() = 0;
};

#endif