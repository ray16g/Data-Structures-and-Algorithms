#include"set.h"
#include"hash_set.h"
#include"test.h"

int main(int argc, char const *argv[])
{
    Set<int>* set{new HashSet<int>([](int i) { return i; } , Prober::LINEAR)};

    set->add(5);
    equals<bool>(true, set->contains(5), "Added 5 to set, contains 5");
    equals<bool>(false, set->contains(6), "Contains 6");

    return 0;
}
