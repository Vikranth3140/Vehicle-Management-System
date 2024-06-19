#ifndef TRUCK_HPP
#define TRUCK_HPP

#include "Vehicle.hpp"

class Truck : public Vehicle {
private:
    double loadCapacity;

public:
    Truck(int id, const std::string& brand, int year, double loadCapacity);

    void displayInfo() const override;
    void updateInfo() override;
};

#endif // TRUCK_HPP