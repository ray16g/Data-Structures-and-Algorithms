#include <stdexcept>

#include "list.h"

#ifndef LINKED_LIST
#define LINKED_LIST

template<typename T>
struct Node
{
    T item;
    Node<T>* next;
};

template<typename T>
class LinkedList : public List<T>
{
public:

    LinkedList() : head{nullptr}, tail{nullptr}, length{1} {}

    /** virtual destructor */
    ~LinkedList() { }

    /** Add an item to the list 
     * Param1: the item to add */
    void add(const T& item) 
    {
        Node<T>* tmp = new Node<T>{item, nullptr};

        if(empty())
        {
            head = tmp;
            tail = head;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
            
        }
        ++length;
    }

    /** Add an item to the list at a certain position
     * Param1: the item to add
     * Param2: the position (1 <= p <= n + 1) in which to insert the item 
     * Throws: std::out_of_range error if param1 is out of range */ 
    void add(const T& item, size_t pos) 
    {
        if(pos > length + 1 || pos < 1) throw std::out_of_range("add out of range");

        if(pos == length + 1)
        {
            add(item);
        }
        else if(pos == 1)
        {
            head = new Node<T>{item, head};
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

            tmp->next = new Node<T>{item, tmp->next};
        }
        ++length;
    }
    
    /** Rempove and return an item at a certain position 
     * Param1: the poisition of the item to remove and return (1 <= p <= n) */
    T remove(size_t pos) 
    {
        if(pos > length || pos < 1) throw std::out_of_range("remove out of range");

        T ret;

        if(pos == length)
        {
            Node<T>* tmp{head};
            while(tmp->next != tail)
                tmp = tmp->next;
            
            ret = tmp->next->item;
            delete tmp->next; 
            tail = tmp;

        }
        else if(pos == 1)
        {
            Node<T>* tmp{head};
            ret = head->item;
            head = head->next;
            delete tmp;
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

            Node<T>* delTmp{tmp->next};
            ret = delTmp->item;
            tmp->next = delTmp->next;
            delete delTmp;
        }
        --length;
        return ret;
    }

    /** Replace an item in the list at a certain position
     * Param1: The item to add to the list
     * Param2: The position of the item that gets replaced (1 <= p <= n)
     * Throws: std::out_of_range error if param1 is out of range */ 
    void replace(const T& item, size_t pos) 
    {
        if(pos > length || pos < 1) throw std::out_of_range("replace out of range");
        
        size_t i = 1;
        Node<T>* tmp{head};

        while(i < pos)
        {
            tmp = tmp->next;
            ++i;
        }

        tmp->item = item;
    }

    /** Returns the item at a certain position but does not remove it
     * Param1: the position of the item to be returned (1 <= p <= n) 
     * Return: the item at the position
     * Throws: std::out_of_range error if param1 is out of range */ 
    T at(size_t pos) const 
    {
        if(pos > length || pos < 1) throw std::out_of_range("at out of range");

        size_t i = 1;
        Node<T>* tmp{head};

        while(i < pos)
        {
            tmp = tmp->next;
            ++i;
        }

        return tmp->item;
    }

    /** Check for containment of an item
     * Param1: the search term
     * Return: true if the list contains the item or false otherwise */
    bool contains(const T& item) const 
    {
        Node<T>* tmp{head};

        while(tmp != nullptr)
        {
            if(tmp->item == item) return true;

            tmp = tmp->next;
        }
        return false;
    }

    /** Returns the quantity of items stored in the list */
    size_t size() const { return length; }

    /** Test of the list is empty  
     * Return true if the list is empty or false otherwise */
    bool empty() const { return head == nullptr; }

    /** Clear the list */
    void clear() 
    {
        Node<T>* tmp{head};

        while(head != nullptr) 
        {
            head = head->next;
            delete tmp;
            tmp = head;
        }

        length = 0;
    }

private:
    Node<T>* head;
    Node<T>* tail;
    size_t length;


};


#endif /* LINKED_LIST */
