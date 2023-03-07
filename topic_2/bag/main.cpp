#include <iostream>
#include "array_bag.h"

int main(int argc, char const *argv[])
{
    ArrayBag<int> ab(10);

    for (size_t i = 0; i < 100; ++i)
    {
        ab.add(i);
    }
    
    while(ab.size() > 0)
    {
        int item {ab.grab()};
        std::cout << item << " ";
        std::cout << ab.remove(item) << std::endl;
    }


    return 0;
}
