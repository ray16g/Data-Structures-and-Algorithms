#include"set.h"
#include"hash_set.h"

int main(int argc, char const *argv[])
{
    Set<int>* set{new HashSet<int>([](int i) { return i; } , Prober::LINEAR)};

    set->add(5);

    return 0;
}
