#include <stdexcept>

#include "list.h"
#include "node.h"

#ifndef LINKED_LIST
#define LINKED_LIST

template<typename T>
class LinkedList : public List<T>
{
public:
    /** constructor */
    LinkedList() : head{nullptr}, tail{nullptr}, count{0} {}

    /** destructor */
    ~LinkedList() { clear(); }

    /** Add an item to the list 
     * Param1: the item to add */
    void add(const T& item) 
    {
        Node<T>* newNode{new Node<T>{item, nullptr}};

        if(empty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }

        ++count;
    }

    /** Add an item to the list at a certain position
     * Param1: the item to add
     * Param2: the position (1 <= p <= n + 1) in which to insert the item 
     * Throws: std::out_of_range error if param1 is out of range */ 
    void add(const T& item, size_t pos) 
    {
        if(pos < 1 || pos > count + 1)
            throw std::out_of_range("index out of range");

        if(pos == 1)
        {
            head = new Node<T>{item, head};
            if(tail == nullptr)
                tail = head;
            ++count;
        }
        else if(pos == count + 1)
        {
            add(item);
        }
        else
        {
            Node<T>* prev{nodeAt(pos-1)};
            prev->next = new Node<T>{item, prev->next};
            ++count;
        }
    }
    
    /** Rempove and return an item at a certain position 
     * Param1: the poisition of the item to remove and return (1 <= p <= n) */
    T remove(size_t) 
    {
        return T{};
    }

    /** Replace an item in the list at a certain position
     * Param1: The item to add to the list
     * Param2: The position of the item that gets replaced (1 <= p <= n)
     * Throws: std::out_of_range error if param1 is out of range */ 
    void replace(const T&, size_t) {}

    /** Returns the item at a certain position but does not remove it
     * Param1: the position of the item to be returned (1 <= p <= n) 
     * Return: the item at the position
     * Throws: std::out_of_range error if param1 is out of range */ 
    T at(size_t pos) const 
    {
        if(pos < 1 || pos > count) 
            throw std::out_of_range("index out of range");

        int i;
        Node<T>* it{head};

        for(i = 1; i < pos; ++i)
            it = it->next;

        return it->item;
    }

    /** Check for containment of an item
     * Param1: the search term
     * Return: true if the list contains the item or false otherwise */
    bool contains(const T& item) const 
    {

        Node<T>* it{head};

        while(it != nullptr)
        {
            if(it->item == item) 
                return true;
            it = it->next;
        }

        return false;
    }

    /** Returns the quantity of items stored in the list */
    size_t size() const 
    {
        return count;
    }

    /** Test of the list is empty  
     * Return true if the list is empty or false otherwise */
    bool empty() const 
    {
        return head == nullptr;
    }

    /** Clear the list */
    void clear() 
    {
        Node<T>* tmp{head};

        while(!empty())
        {
            head = head->next;
            delete tmp;
            tmp = head;
        }

        tail = nullptr;
        count = 0;
    }
    
private:
    Node<T>* head;
    Node<T>* tail;
    size_t count;

    Node<T>* nodeAt(size_t pos)
    {
        Node<T>* it{head};

        while(pos > 1)
        {
            it = it->next;
            --pos;
        }

        return it;
    }
};


#endif /* LINKED_LIST */
