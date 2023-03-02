#include <iostream>

int main(int argc, char const *argv[])
{
    for (size_t i = 1; i < argc; ++i)
    {
        std::cout << argv[i] << std::endl;
    }
    
    return 0;
}
