#include "splay_tree.h"
#include "test.h"

int main(int argc, char const *argv[])
{
    SplayTree<int> *st = new SplayTree<int>([](const int &a, const int &b)
                                            { return a > b; });

    equals<bool>(st->empty(), true, "SplayTree is empty");
    equals<int>(st->size(), 0, "SplayTree size is 0");

    st->add(5);
    st->add(10);
    st->add(3);
    st->add(15);
    st->add(2);
    st->add(30);
    st->add(50);

    equals<bool>(st->empty(), false, "SplayTree is not empty");
    equals<int>(st->size(), 7, "SplayTree size is 7");
    equals<bool>(st->contains(50), true, "SplayTree contains 50");
    equals<bool>(st->contains(5), true, "SplayTree contains 5");

    st->remove(5);

    equals<bool>(st->contains(5), false, "SplayTree does not contain 5");
    equals<bool>(st->contains(50), true, "SplayTree contains 50");
    equals<int>(st->size(), 6, "SplayTree size is 6");

    delete st;

    return 0;
}
