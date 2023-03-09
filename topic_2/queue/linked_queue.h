#include <stdexcept>

#include "queue.h"

#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE

template<typename T>
struct Node {
    T item;
    Node<T>* next;
};

template<typename T>
class LinkedQueue : public Queue<T> {

public:
    LinkedQueue() : head{nullptr}, tail{nullptr} { }
    ~LinkedQueue() { clear(); }
    /* Adds an item to the back of the queue */
    void enqueue(const T& item) 
    {
        Node<T>* tmp = new Node<T>{item, nullptr};
        if(tail == nullptr)
        {
            tail = tmp;
            head = tail;
        } 
        else 
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    /* Removes an item from the queue */
    void dequeue() 
    {
        if(empty()) throw std::runtime_error("front on empty queue");

        Node<T>* tmp{head};
        head = head->next;
        delete tmp;
    }

    /* Returns but does not remove the item at the front of the queue */
    T front() const 
    {
        if(empty()) throw std::runtime_error("front on empty queue");
        return head->item;
    }

    /* Returns true if the queue is empty, else returns false */
    bool empty() const { return head == nullptr; }

    /* Empties the queue */
    void clear() 
    {
        Node<T>* it{head};

        while(it != nullptr)
        {
            head = head->next;
            delete it;
            it = head;
        }
    }

private:
    Node<T>* head;
    Node<T>* tail;
};

#endif