#include <iostream>
#include "board.h"

int main(int argc, char const *argv[])
{
    Board b{0x876543210ul, 0};
    std::cout << b << std::endl;

    b.move(3);
    std::cout << b << std::endl;
    return 0;
}
