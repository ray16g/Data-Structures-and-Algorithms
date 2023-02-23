#include <iostream>

int main(int argc, char const *argv[])
{
    int a{25};
    int b{30};

    int* ptr{&a};

    std:: cout << *ptr << " " << *(ptr - 1) << " " << *(ptr + 1) <<  std::endl;


    return 0;
}
