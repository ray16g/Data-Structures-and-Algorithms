#include <iostream>
#include <vector>

#include "car.h"
#include "scooter.h"

void printVehicles(const std::vector<Vehicle*>& vehicles, const size_t ptr) {

    if(ptr == vehicles.size()) return;

    std::cout << vehicles[ptr]->getId() << std::endl;
    printVehicles(vehicles, ptr + 1);

}

int main(int argc, char const *argv[])
{
    std::vector<Vehicle*> vehicles {
        new Car("Blue", "Gas Engine", "A135532JJS352"),
        new Scooter("Pastel Blue", "Gas Engine", "B9435890235")
    };

    printVehicles(vehicles, 0);
    
    return 0;
}
