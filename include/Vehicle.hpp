#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <iostream>
#include <string>

class Vehicle {
protected:
    std::string brand;
    int year;

public:
    Vehicle(const std::string& brand, int year);
    virtual ~Vehicle();

    virtual void displayInfo() const;
    virtual std::string getBrand() const;
    virtual int getYear() const;
    virtual void updateInfo();
};

#endif // VEHICLE_HPP