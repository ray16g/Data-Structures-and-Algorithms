#include <iostream>
#include "./stack.h"

int main(int argc, char const *argv[])
{
    Stack<int, 100> stack;

    try {
        for (size_t i = 0; i < 90; ++i) {
            stack.push(i);
        }
    } catch(const FullStackError) {
        std::cout << "Attempted to add a value to a full stack\n";
    }
    
    for (size_t i = 0; i < 90; ++i) {
        std::cout << stack.peek() << " ";
        stack.pop();
    }


    std::cout << std::endl;
    
    return 0;
}
