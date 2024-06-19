#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <iostream>
#include <string>

class Vehicle {
protected:
    int id;
    std::string brand;
    int year;

public:
    Vehicle(int id, const std::string& brand, int year);
    virtual ~Vehicle();

    virtual void displayInfo() const;
    int getId() const;
    virtual void updateInfo();
};

#endif // VEHICLE_HPP