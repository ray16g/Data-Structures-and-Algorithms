#include <stdexcept>

#include "list.h"

#ifndef LINKED_LIST
#define LINKED_LIST

template<typname T>
struct Node
{
    T item;
    Node<T>* next;
};

template<typename T>
class LinkedList : public List<T>
{
public:

    List() : head{nullptr}, size{1} {}

    /** virtual destructor */
    ~List() { }

    /** Add an item to the list 
     * Param1: the item to add */
    void add(const T& item) 
    {
        if(empty())
        {
            head = new Node<T>(item, nullptr);
            tail = head;
        }
        else
        {
            tail->next = new Node<T>(item,nullptr);
            tail = tail->next;
        }
        ++size;
    }

    /** Add an item to the list at a certain position
     * Param1: the item to add
     * Param2: the position (1 <= p <= n + 1) in which to insert the item 
     * Throws: std::out_of_range error if param1 is out of range */ 
    void add(const T& item, size_t pos) 
    {
        if(pos > size + 1 || pos < 1) throw std::runtime_error("Attempted to call add with position out of range");

        if(pos == size + 1)
        {
            add(item);
        }
        else if(pos == 1)
        {
            head = new Node<T>(item, head);
        }
        else
        {
            size_t i = 1;
            Node<T>* tmp{head};
            while(i < pos - 1)
            {
                tmp = tmp->next;
                ++i;
            }

            tmp->next = new Node<T>(item, tmp->next);
        }
        ++size;
    }
    
    /** Rempove and return an item at a certain position 
     * Param1: the poisition of the item to remove and return (1 <= p <= n) */
    T remove(size_t pos) {}

    /** Replace an item in the list at a certain position
     * Param1: The item to add to the list
     * Param2: The position of the item that gets replaced (1 <= p <= n)
     * Throws: std::out_of_range error if param1 is out of range */ 
    void replace(const T& item, size_t pos) {}

    /** Returns the item at a certain position but does not remove it
     * Param1: the position of the item to be returned (1 <= p <= n) 
     * Return: the item at the position
     * Throws: std::out_of_range error if param1 is out of range */ 
    T at(size_t pos) const {}

    /** Check for containment of an item
     * Param1: the search term
     * Return: true if the list contains the item or false otherwise */
    bool contains(const T& item) const {}

    /** Returns the quantity of items stored in the list */
    size_t size() const { return size; }

    /** Test of the list is empty  
     * Return true if the list is empty or false otherwise */
    bool empty() const { return size == 0; }

    /** Clear the list */
    void clear() {}

private:
    Node<T>* head;
    Node<T>* tail;
    size_t length;


};


#endif /* LINKED_LIST */
