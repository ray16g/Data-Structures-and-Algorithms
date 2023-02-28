#include <iostream>
#include "stack.h"

int main(int argc, char const *argv[])
{
    Stack<int> stack;

    for (size_t i = 0; i < 90; ++i) {
        stack.push(i);
    }
    for (size_t i = 0; i < 90; ++i) {
        std::cout << stack.peek() << " ";
        stack.pop();
    }


    std::cout << std::endl;
    
    return 0;
}
