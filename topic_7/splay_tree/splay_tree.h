#include "binary_tree_node.h"

#ifndef SPLAY_TREE
#define SPLAY_TREE

template<typename T>
class SplayTree
{

    SplayTree() : head{nullptr}, count{0} {}

    ~SplayTree() {}

public:
    void add(const T& item)
    {
        if(head == nullptr) head = new BinaryTreeNode<T>(item); return;

        

        ++count;
    }

    void remove(const T& item)
    {

        --count;
    }

    bool contains(const T& item)
    {
        
    }

    size_t size() const
    {
        return count;
    }

    bool empty() const
    {
        return count == 0;
    }

private:
    BinaryTreeNode<T>* head;
    size_t count;

    // right rotation
    BinaryTreeNode<T>* zig(BinaryTreeNode<T>* n)
    {
        BinaryTreeNode<T>* t = n->lchild;
        n->lchild = t->rchild;
        t->lchild = n;
        return t;
    }

    // left rotation
    BinaryTreeNode<T>* zag(BinaryTreeNode<T>* n)
    {
        BinaryTreeNode<T>* t = n->rchild;
        n->rchild = t->lchild;
        t->rchild = n;
        return t;
    }

    BinaryTreeNode<T>* search(BinaryTreeNode<T>* n)
    {
        if(n == nullptr) return;
    }

};

#endif