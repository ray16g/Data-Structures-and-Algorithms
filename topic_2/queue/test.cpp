#include "..\..\common\test.h"
#include "array_queue.h"
#include "linked_queue.h"
#include "queue.h"

void testMultiAdd()
{
    Queue<int>* q{new ArrayQueue<int>()};

    for (size_t i = 1; i < 100; ++i)
        q->enqueue(i);

    for (size_t i = 1; i < 100; ++i)
    {
        equals<int>(i, q->front(), "Dequeue Multi Items");
        q->dequeue();
    }
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

    for (size_t i = 1; i < 10; ++i)
        q->enqueue(i);
    
    q->clear();

    equals<bool>(true, q->empty(), "TestClear");

    testMultiAdd();

    return 0;
}
