#include "vehicle.h"
#include "car.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Vehicle v("Blue", "Car", "Gas Engine");
    Car c("Blue", "Gas Engine", "0310531");
    std::cout << c.getVin();
    return 0;
}
