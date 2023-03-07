#include "scooter.h"

Scooter::Scooter(const std::string& color, const std::string& powerSource, const std::string& vin) 
    : Vehicle(color, "Scooter", powerSource) {
    if(vin.empty()) throw "";

    this->vin = vin;
}
Scooter::Scooter() : Scooter("", "", "00000000") {}

std::string Scooter::getId() const { return vin; }