#include <iostream>
#include <array>
#include <vector>

int main(int argc, char const *argv[])
{

    std::array<int, 5> a{1,2,3,4,5};
    std::vector<int> v(100);

    for(int& i : a) std::cout << i++ << " ";

    std::cout << std::endl;

    for(size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << " ";
    }

    std::cout << std::endl;
    
    /* int n{10};
    for(size_t i{0}, j{1}, tmp; n >= 0; --n, tmp = j, j = j += i, i = tmp) {
        std::cout << i << ' ';
    }

    std::cout << std::endl; */

    return 0;
}
