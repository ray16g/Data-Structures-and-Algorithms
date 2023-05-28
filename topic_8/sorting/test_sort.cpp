#include <iostream>
#include <algorithm>

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
    int array[]{8, 1, 3, 5, 9, 4, 13, 15, 12};
    int array2[]{8, 1, 3, 5, 9, 4, 13, 15, 12};
    size_t count = sizeof(array) / sizeof(array[0]);

    std::cout << "The unsorted array: ";
    printArray(array, count);

    std::cout << "The 5th smallest element in the array is " << Sort<int>::selection(array, count, 4) << std::endl;
    std::cout << "The 8th smallest element in the array is " << Sort<int>::selection(array, count, 7) << std::endl;

    Sort<int>::quickSort(array, count);
    std::cout << "The sorted array using quick sort: ";
    printArray(array, count);

    Sort<int>::mergeSort(array2, count);
    std::cout << "The sorted array using merge sort: ";
    printArray(array2, count);

    return 0;
}