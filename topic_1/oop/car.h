#include <string>

#include "vehicle.h"

#ifndef CAR_H
#define CAR_H

class Car : public Vehicle {
public:
    Car(); 
    Car(const std::string&, const std::string&, const std::string&);

    std::string getId() const;


private:
    std::string vin;
 
};

#endif