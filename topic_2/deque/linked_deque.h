#include "deque.h"

#ifndef LINKED_DEQUE_H
#define LINKED_DEQUE_H

template<typename T>
struct Node
{
    T item;
    Node<T>* prev;
    Node<T>* next;
};

template<typename T>
class LinkedDeque : public Deque<T>
{
public:

    LinkedDeque() : head{nullptr}, tail{nullptr} { }
    ~LinkedDeque() { clear(); }

    void pushFront(const T& item)
    {
        head = new Node<T>(item, nullptr, head);
        if(tail == nullptr) tail = head;
    }
    
    void pushBack(const T& item) 
    {
        Node<T>* tmp{new Node<T>{item, tail, nullptr}};
        if(empty())
        {
            head = tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    void popFront() 
    {
        Node<T>* tmp{head};
        if(empty()) throw "";

        head = head->next;
        if(head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;
        
        delete tmp;
    }
    void popBack() 
    {
        Node<T>* tmp{tail};
        if(empty()) throw "";

        tail =  tail->prev;
        if(tail == nullptr)
        {
            head = nullptr;
        }
        else
        {
            tail->next = nullptr;
        }
        delete tmp;

    }

    T getFront() const 
    {
        if(empty()) throw "";
        return head->item;
    }

    T getBack() const 
    {
        if(empty()) throw "";
        return tail->item;
    }

    bool empty() const 
    {
        return head == nullptr;
    }

    void clear() 
    {
        Node<T>* tmp{};
        while(tmp != nullptr)
        {
            head = head->next;
            delete tmp;
            tmp = head;
        }
        head = tail = nullptr;
    }

private:
    Node<T>* head;
    Node<T>* tail;
};


#endif