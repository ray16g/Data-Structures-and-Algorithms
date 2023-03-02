#include <string>
#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle
{
public:
    Vehicle();
    Vehicle(const std::string&, const std::string&, const std::string&);

    void setType(const std::string&);
    std::string getType();


private:
    std::string color;
    std::string type;
    std::string powerSource;

};

#endif