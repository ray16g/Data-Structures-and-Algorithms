#include <iostream>

union b32
{
    int i;
    float f;

};

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


int main(int argc, char const *argv[])
{
    // std::cout << hashcode(25ll) << std::endl;
    std::cout << hashcode(25.0) << std::endl;
    return 0;
}
