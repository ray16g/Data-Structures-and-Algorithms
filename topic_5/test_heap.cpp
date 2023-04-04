#include "heap.h"
#include "array_heap.h"

#include "../common/test.h"

int main(int argc, char const *argv[])
{
    Heap<int>* heap {new ArrayHeap<int>(
        [] (const int& l, const int& r) {return l <= r;}
    )};
    return 0;
}
