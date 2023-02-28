#include <iostream>

#define COUT std::cout

namespace std {
struct Point {
    double x;
    double y;
};

Point* createPoint(double const x, double const y) {
    return new Point{x,y};
}

} // namespace msac
using std::Point;
using std::createPoint;

int main(int argc, char const *argv[])
{
    Point* p{createPoint(5,6)};

    int* b{new int[20]};
    int c[10]{1,2,3,4,5};

    double d = (*p).x;

    delete p; p = nullptr;

    return 0;
}
