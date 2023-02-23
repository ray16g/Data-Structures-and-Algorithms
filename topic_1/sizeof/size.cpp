#include <iostream>

void printSize(int b[], size_t size) {
    std::cout << sizeof(b) << std::endl;
}

int main(int argc, char const *argv[])
{
    int a[50];
    printSize(a, sizeof(a) / sizeof(int));
    return 0;
}
