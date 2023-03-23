#include <iostream>

#include ".\..\..\topic_1\stack2\stack.h"

template<typename T>
struct BinaryNode 
{
    T item{};
    BinaryNode<T>* leftChild{nullptr};
    BinaryNode<T>* rightChild{nullptr};
};

template<typename T>
void printDft(BinaryNode<T>* root)
{
    if(root == nullptr) return;

    std::cout << root->item << " ";

    printDft(root->leftChild);
    printDft(root->rightChild);

    std::cout << std::endl;
}

template<typename T>
void printDft(BinaryNode<T>* root, int)
{
    Stack<BinaryNode<T>*> stack;
    stack.push(root);

    while(!stack.empty())
    {
        BinaryNode<T>* tmp{stack.peek()};

        stack.pop();

        if(tmp->rightChild != nullptr)
            stack.push(tmp->rightChild);

        if(tmp->leftChild != nullptr)
            stack.push(tmp->leftChild);

        std::cout << tmp->item << " ";
    }
    std::cout << std::endl;
}

size_t max(size_t left, size_t right)
{
    return (left > right) ? left : right;
}

template<typename T>
size_t height(BinaryNode<T>* root)
{
    if(root == nullptr)
        return 0;
    
    return 1 + max(height<T>(root->leftChild), height<T>(root->rightChild));
}

int main(int argc, char const *argv[])
{
    BinaryNode<char>* root{nullptr};

    BinaryNode<char>* D{new BinaryNode<char>{'D'}};
    BinaryNode<char>* F{new BinaryNode<char>{'F'}};
    BinaryNode<char>* B{new BinaryNode<char>{'B', D}};
    BinaryNode<char>* C{new BinaryNode<char>{'C', nullptr, F}};
    BinaryNode<char>* A{new BinaryNode<char>{'A', B, C}};
    root = A;

    printDft(root);
    printDft(root, 0);

    std::cout << height(root);

    return 0;
}

