#include <iostream>

int main(int argc, char const *argv[])
{
    int a{20};
    int* b{&a};
    int** c{&b};

    std::cout << a << " " << b << " " << c << " " << *c  << " " << **c <<  std::endl;

    return 0;
}
