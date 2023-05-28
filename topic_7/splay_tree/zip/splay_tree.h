#include "binary_tree_node.h"
#include<functional>

#ifndef SPLAY_TREE
#define SPLAY_TREE

template<typename T>
class SplayTree
{
    using Comparator = std::function<bool(const T&, const T&)>;

public:

    SplayTree(Comparator comparator) : head{nullptr}, count{0}, comparator{comparator} {}

    ~SplayTree() {
        while(!empty())
        {
            remove(head->item);
        }

    }

    void add(const T& item)
    {
        ++count;
        if(head == nullptr) {
            head = new BinaryTreeNode<T>(item); 
            return;
        }

        head = addNode(head, item);
    }

    void remove(const T& item)
    {
        if(head == nullptr) return;

        head = containsNode(head, item);

        if(head->item == item)
        {
            head = removeNode(head, item);
        }

        --count;
    }

    bool contains(const T& item)
    {
        if(head == nullptr) return false;

        head = containsNode(head, item);
        return head->item == item;
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
    Comparator comparator;

    // right rotation
    BinaryTreeNode<T>* zig(BinaryTreeNode<T>* n)
    {
        BinaryTreeNode<T>* t = n->lchild;
        n->lchild = t->rchild;
        t->rchild = n;
        return t;
    }

    // left rotation
    BinaryTreeNode<T>* zag(BinaryTreeNode<T>* n)
    {
        BinaryTreeNode<T>* t = n->rchild;
        n->rchild = t->lchild;
        t->lchild = n;
        return t;
    }

    BinaryTreeNode<T>* addNode(BinaryTreeNode<T>* n, const T& item)
    {
        if(n == nullptr) return new BinaryTreeNode<T>(item);


        if(comparator(item, n->item))
        {
            n->rchild = addNode(n->rchild, item);
            n = zag(n);
        }
            

        if(comparator(n->item, item))
        {
            n->lchild = addNode(n->lchild, item);
            n = zig(n);
        }

        return n;
    }

    BinaryTreeNode<T>* removeNode(BinaryTreeNode<T>* n, const T& item)
    {
        if(n->lchild == nullptr)
            return n->rchild;

        if(n->rchild == nullptr)
            return n->lchild;

        // Since (item > left, then containsNode(left, item) will bring maximum of left subtree to root)
        BinaryTreeNode<T>* newHead = containsNode(n->lchild, item);
        newHead->rchild = n->rchild;

        delete n;
        
        return newHead;
    }

    BinaryTreeNode<T>* containsNode(BinaryTreeNode<T>* n, const T& item)
    {
        if(n == nullptr)
            return n;

        if(comparator(item, n->item))
        {
            n->rchild = containsNode(n->rchild, item);
            if(n->rchild != nullptr)
                n = zag(n);
        }
            
        if(comparator(n->item, item))
        {
            n->lchild = containsNode(n->lchild, item);
            if(n->lchild != nullptr)
                n = zig(n);
        }

        return n;

    }
};

#endif