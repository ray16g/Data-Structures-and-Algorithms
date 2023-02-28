#include <iostream>

struct Point {
    double x;
    double y;
};

Point* createPoint(const double x, const double y) {
    return new Point{x,y};
}


int main(int argc, char const *argv[])
{
    Point* p{nullptr};

    int* b{new int[20]};
    int c[10]{1,2,3,4,5};
    p = createPoint(3.15,2.17);

    delete p; p = nullptr;

    return 0;
}
