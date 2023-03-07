#include "car.h"

Car::Car(const std::string& color, const std::string& powerSource, const std::string& vin) 
    : Vehicle(color, "Car", powerSource) {
    if(vin.empty()) throw "";

    this->vin = vin;
}
Car::Car() : Car("", "", "00000000") {}

std::string Car::getId() const { return vin; }