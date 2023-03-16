#include "bsearch.h"
#include "..\..\common\test.h"

int main(int argc, char const *argv[])
{
    int array[]{1,2,3,4,5,6,7};

    equals<int>(0, bsearch(array,0, 6, 1), "Test for 1");
    equals<int>(3, bsearch(array,0, 6, 4), "Test for 4");
    equals<int>(6, bsearch(array,0, 6, 7), "Test for 7");
    equals<int>(-1, bsearch(array,0, 6, 100), "Test for 100");

    return 0;
}

int bsearch(const int array[], int start, int end, int term)
{
    if(start > end) return -1;

    int mid{(start + end) >> 1};

    if(array[mid] == term) return mid;

    if(array[mid] > term) return bsearch(array, start, mid - 1, term);

    return bsearch(array, mid + 1, end, term);
}