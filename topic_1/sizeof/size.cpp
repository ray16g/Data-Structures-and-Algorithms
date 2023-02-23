#include <iostream>
#include <cstdint>

enum class Status {
    ALIVE,
    DEAD,
    JAILED
};

void printSize(int b[], size_t size) {
    std::cout << sizeof(b) << std::endl;
}

int main(int argc, char const *argv[])
{
    uint64_t l;

    Status s{Status::ALIVE};
    std::cout << (s == Status::ALIVE) << std::endl;

    int a[50];
    //printSize(a, sizeof(a) / sizeof(int));
    return 0;
}
