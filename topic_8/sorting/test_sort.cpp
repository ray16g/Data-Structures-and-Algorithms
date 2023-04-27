#include <iostream>

#include "sort.h"

void printArray(int array[], size_t count)
{
    std::cout << "[ ";
    for (size_t i = 0; i < count; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "]\n";
}

int main(int argc, char const *argv[])
{
    int array[]{8,1,3,5,9,4,13,15};
    size_t count = sizeof(array)/sizeof(array[0]);

    printArray(array, count);

    Sort<int>::selectSort(array, count, [] (int a, int b) { return a > b; });

    printArray(array, count);

    return 0;
}
