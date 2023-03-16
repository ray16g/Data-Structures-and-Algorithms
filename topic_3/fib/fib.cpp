#include <iostream>
#include <cstdint>

#include "fib.h"

int main(int argc, char const *argv[])
{
    std::cout << fib(10) << std::endl;    
    return 0;
}

uint64_t fib(uint32_t n) 
{
    if(n <= 1) return n;

    return fib(n - 1) + fib(n - 2);
}
