#include <stdexcept>
#ifndef STACK_H
#define STACK_H

template <typename U>
struct Node
{
    U item;
    Node<U> *next;
};

template <typename T>
class Stack
{

public:
    ~Stack()
    {
        while (!empty())
            pop();
    }

    bool empty() { return (head == nullptr); }
    void push(const T &item) { head = new Node<T>{item, head}; }

    void pop()
    {
        if (empty())
            throw std::runtime_error("operation on empty stack");

        Node<T> *tmp{head};
        head = head->next;
        delete tmp;
    }

    T peek()
    {
        if (empty())
            throw std::runtime_error("operation on empty stack");
        return head->item;
    }

private:
    Node<T> *head{nullptr};
};

#endif