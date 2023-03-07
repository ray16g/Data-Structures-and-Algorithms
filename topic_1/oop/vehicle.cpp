#include "./vehicle.h"

Vehicle::Vehicle(const std::string& color, const std::string& type, const std::string& powerSource) 
    : color{color}, powerSource{powerSource} {
    if(type.empty()) throw "";

    this->type = type;
} 
Vehicle::Vehicle() : Vehicle("","","") {}

void Vehicle::setType(const std::string& type) {
    if(type.empty()) throw "";

    this->type = type;
}
std::string Vehicle::getType() const {
    return type;
}