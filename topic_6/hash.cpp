#include <iostream>

#define ARRAY_SIZE 524287

union b32
{
    int i;
    float f;

};

int min(int l, int r)
{
    return (l < r ? l : r);
}

int hashcode(const std::string& k)
{
    int code{0};

    for (size_t i = 0; i < min(15, k.size()); i++)
        code = code * 10 + k[i];
    

    return code;
}

int hashcode(int k) { return k; }

int hashcode(long long k) 
{
    return static_cast<int>((k >> 32) ^ k);
}

int hashcode(float k)
{
    return *reinterpret_cast<int*>(&k);
}

int hashcode(double k)
{
    return hashcode(*reinterpret_cast<long long*>(&k));
}

int compress(int hc)
{
    return (hc & ~(1 << 31)) % ARRAY_SIZE;
} 

int main(int argc, char const *argv[])
{
    // std::cout << hashcode(25ll) << std::endl;
    std::cout << hashcode("nbvnbvnbnbvjhgmmmmmmmmmmmmmmmm") << std::endl;
    return 0;
}
