#include"set.h"
#include"hash_set.h"
#include"test.h"

int main(int argc, char const *argv[])
{
    Set<int>* set{new HashSet<int>([](int i) { return i; } , Prober::LINEAR)};

    equals<bool>(true, set->empty(), "Set is empty");
    set->add(5);
    equals<bool>(false, set->empty(), "Set is not empty");
    equals<int>(1, set->size(), "Set size is 1");
    equals<bool>(true, set->contains(5), "Added 5 to set, contains 5");
    equals<bool>(false, set->contains(6), "Contains 6");
    set->add(10);
    equals<bool>(true, set->contains(10), "Added 10 to set, contains 10");
    equals<int>(2, set->size(), "Set size is 2");
    set->remove(10);
    equals<bool>(false, set->contains(10), "Removed 10 from set, does not contain 10");
    equals<int>(1, set->size(), "Set size is 1");
    return 0;
}
