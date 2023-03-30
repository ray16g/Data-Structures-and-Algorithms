// who:  Raymond Huang
// what: Test Linked List
// why:  Topic 2: List ADT
// when: 2023-03-28

#include <iostream>

#include "test.h"
#include "list.h"
#include "linked_list.h"

int main(int argc, char const *argv[])
{
    List<double>* list = {new LinkedList<double>()};
    equals<bool>(true, list->empty(), "Test empty on empty list");
    equals<size_t>(0, list->size(), "test size == 0 on empty list");
    try
    {
        list->clear();
        std::cout << "SUCCESS: No exception on clear" << std::endl;
    }
    catch(const std::exception&)
    {
        std::cout << "ERROR: Exception on clear" << std::endl;
    }

    for(size_t i = 1.0; i <= 10; i++)
        list->add(i);
    
    equals<bool>(false, list->empty(), "Test not empty on adding items (1 - 10)");
    equals<size_t>(10, list->size(), "test size == 10 on list");

    equals<bool>(true, list->contains(1.0), "Test contains 1");
    equals<bool>(true, list->contains(10.0), "Test contains 10");
    equals<bool>(true, list->contains(5.0), "Test contains 5");
    equals<bool>(false, list->contains(11.0), "Test does not contains 11");

    equals<double>(1.0, list->at(1), "Test contains 1");
    equals<double>(10.0, list->at(10), "Test contains 10");
    equals<double>(5.0, list->at(5), "Test contains 5");

    try
    {
        list->at(11);
        std::cout << "ERROR: test at does not throw out of range exception" << std::endl;

    }
    catch(const std::out_of_range)
    {
        std::cout << "SUCCESS: test at throws out of range exception" << std::endl;

    }
    catch(const std::exception&)
    {
        std::cout << "ERROR: test at throws different exception" << std::endl;
    }
    
    return 0;
}
