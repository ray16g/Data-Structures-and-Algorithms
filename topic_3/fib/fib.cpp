#include <iostream>
#include <cstdint>

#include "fib.h"

int main(int argc, char const *argv[])
{
    std::cout << fib(10) << std::endl;    
    return 0;
}

// uint64_t fib(uint32_t n) 
// {
//     if(n <= 1) return n;

//     return fib(n - 1) + fib(n - 2);
// }

uint64_t fib(uint32_t n)
{
    uint32_t l{0};
    uint32_t r{1};
    uint32_t tmp;
    int c{0};

    for(; c < n; tmp = l, l += r, r = tmp, ++c);

    return l;
}
