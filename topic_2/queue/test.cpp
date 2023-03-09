#include "..\..\common\test.h"
#include "linked_queue.h"
#include "queue.h"

void testMultiAdd()
{
    Queue<int>* q{new LinkedQueue<int>()};

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
    
    Queue<int>* q{new LinkedQueue<int>()};
    
    equals<bool>(true, q->empty(), "TestEmpty");

    q->enqueue(1);

    equals<bool>(false, q->empty(), "TestEnqueue");

    equals<int>(1, q->front(), "TestFront");

    q->dequeue();

    equals<bool>(true, q->empty(), "TestDequeue");

    testMultiAdd();

    return 0;
}
