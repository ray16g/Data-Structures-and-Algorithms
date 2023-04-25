#include<iostream>
#include<cstdlib>

static std::string hort[]
{
    "HEADS",
    "TAILS"
};

int main(int argc, char const *argv[])
{
    while (true)
    {
        std::cin.get();
        system("cls");
        std::cout << hort[rand() & 1] << std::endl;
    }
    return 0;
}

