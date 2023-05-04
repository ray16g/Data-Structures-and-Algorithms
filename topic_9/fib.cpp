#include <iostream>

#include<unordered_map>

uint32_t recursiveCalls;

uint64_t fib(uint32_t n)
{
    static std::unordered_map<uint32_t, uint64_t> map;

    ++recursiveCalls;

    if (n <= 1) return n;
    

    if(map.find(n) != map.end()) return map[n];



    map[n] = fib(n - 1) + fib(n - 2);

    return map[n];
}

int main(int argc, char const *argv[])
{
    recursiveCalls = 0;
    std::cout << "fib(50) = " << fib(50) << " and had " << recursiveCalls << " recursive calls\n"; 
    return 0;
}
