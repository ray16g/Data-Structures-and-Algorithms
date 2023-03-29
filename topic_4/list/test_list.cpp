// who:  
// what: Test Linked List
// why:  Topic 2: List ADT
// when: 

#include <iostream>

#include "test.h"
#include "list.h"
#include "linked_list.h"

int main(int argc, char const *argv[])
{
    LinkedList<int>* list = new LinkedList<int>();

    equals<bool>(true, list->empty(), "Empty list is empty");

    for(int i{1}; i <= 9; ++i)
        list->add(i);
    
    for(int i{10}; i <= 15; ++i)
        list->add(i, i);

    equals<bool>(false, list->empty(), "List is not empty");
    equals<bool>(15, list->size(), "List is size 15");
    equals<bool>(true, list->contains(5), "List contains 5");
    equals<bool>(false, list->contains(20), "List does not contain 20");
    equals<int>(5, list->at(5), "List at 5 is 5");
    
    list->replace(5,10);

    equals<int>(5, list->at(10), "List at 10 was replaced by 5");
    equals<int>(5, list->remove(10), "Removed item at 10");
    equals<bool>(14, list->size(), "List is size 14 after removal");
    equals<int>(11, list->at(10), "Item at 10 is now 11");

    list->clear();

    equals<bool>(true, list->empty(), "List is empty after clear");

    return 0;
}
