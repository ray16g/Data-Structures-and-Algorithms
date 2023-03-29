#include <iostream>

#include "array_queue.h"
#include "queue.h"

template<typename T>
void equals(const T& expected, const T& actual, const std::string& testMsg) 
{  
    std::cout << (expected == actual ? "SUCCESS: " : "FAILED: ")  << testMsg << std::endl;
}

int main(int argc, char const *argv[])
{
    
    Queue<int>* q{new ArrayQueue<int>()};
    
    equals<bool>(true, q->empty(), "TestEmpty");

    q->enqueue(1);

    equals<bool>(false, q->empty(), "TestEnqueue");

    equals<int>(1, q->front(), "TestFront");

    q->dequeue();

    equals<bool>(true, q->empty(), "TestDequeue");

    q->enqueue(1);
    
    q->clear();

    equals<bool>(true, q->empty(), "TestClear");

    for (size_t i = 1; i < 100; ++i)
        q->enqueue(i);

    for (size_t i = 1; i < 100; ++i)
    {
        equals<int>(i, q->front(), "Dequeue Multi Items");
        q->dequeue();
    }

    return 0;
}
