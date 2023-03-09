#include <iostream>
#include "array_bag.h"
#include "linked_bag.h"

int main(int argc, char const *argv[])
{
    LinkedBag<int> ab;

    for (size_t i = 0; i < 100; ++i)
    {
        ab.add(i);
    }

    for(size_t i = 20; i < 30; ++i) {
        ab.remove(i);
    }
    
    while(ab.size() > 0)
    {
        int item {ab.grab()};
        std::cout << item << " ";
        std::cout << ab.remove(item) << std::endl;
    }
    std::cout << ab.size();


    return 0;
}
