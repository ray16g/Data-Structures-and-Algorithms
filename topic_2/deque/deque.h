#ifndef DEQUE_H
#define DEQUE_H

template<typename T>
struct Deque
{
    virtual ~Deque() {};
    virtual void pushFront(const T&) = 0;
    virtual void pushBack(const T&) = 0;
    virtual void popFront() = 0;
    virtual void popBack() = 0;
    virtual T getFront() const = 0;
    virtual T getBack() const = 0;
    virtual bool empty() const = 0;
    virtual void clear() = 0;
};

#endif