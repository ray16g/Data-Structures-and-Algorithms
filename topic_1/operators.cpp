#include <iostream>

union VariableType {
    double d;
    unsigned long long ull;
};

int main(int argc, char const *argv[])
{
    bool p{true};
    int i{};
    int j{};
    unsigned long long ull{};

    VariableType v{25};

    std::cout << "double: " << v.d << std::endl << "ull = " << v.ull << std::endl;

    i = (p) ? 25 : 16;
    ((p) ? i : j) = 55;
    // std::cout << ((p) ? 25 : 16) << std::endl;
    
    ull = static_cast<unsigned long long>(j);

    return 0;
}
