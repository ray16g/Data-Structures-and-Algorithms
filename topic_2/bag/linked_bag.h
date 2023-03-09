#include <stdexcept>

#include "bag.h"

#ifndef LINKED_BAG_H
#define LINKED_BAG_H


template<typename T>
struct Node {
    T item;
    Node<T>* next;
};

template<typename T>
class LinkedBag : public Bag<T> {

public:
    LinkedBag() : head{nullptr}, count{0} {}
    ~LinkedBag() { }

   // adds an item to the bag
    void add(const T& item) {
        head = new Node<T>{item, head};
        ++count;
    }

    // removes an item from the bag and returns it
    // throws a runtime exception if the bag is empty or the item is not in the bag
    T remove(const T& item) {
        Node<T>* tmp{getNode(item)};
        T rtnItem;

        if(tmp == nullptr) throw std::runtime_error("remove on empty bag");

        rtnItem = tmp->item;

        tmp->item = head->item;
        tmp = head;
        head = head->next;
        delete tmp;
        --count;

        return rtnItem;
    }

    // returns the count of items in the bag
    size_t size() const { return count; }

    // returns an arbitrary item from the bag
    // throws a runtime exception if the bag is empty
    T grab() const {
        if(count == 0) throw std::runtime_error("grabbed on empty bag");
        return head->item;
    }

    // returns true if the bag contains the item or false otherwise
    bool contains(const T& item) const {
        return getNode(item) != nullptr;
    }

private:
    Node<T>* head;    
    size_t count;

    Node<T>* getNode(const T& item) const {
        Node<T>* it{head};
        while(it != nullptr) {
            if(it->item == item) break;
            it = it->next;
        }
        return it;
    }

};

#endif
