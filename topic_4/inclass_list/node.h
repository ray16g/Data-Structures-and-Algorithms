#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node
{
    T item;
    Node<T>* next;
};

#endif