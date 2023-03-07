#include <string>

#include "vehicle.h"

#ifndef SCOOTER_H
#define SCOOTER_H

class Scooter : public Vehicle {
public:
    Scooter(); 
    Scooter(const std::string&, const std::string&, const std::string&);

    std::string getId() const;


private:
    std::string vin;
 
};

#endif