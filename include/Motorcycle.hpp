#ifndef MOTORCYCLE_HPP
#define MOTORCYCLE_HPP

#include "Vehicle.hpp"

class Motorcycle : public Vehicle {
private:
    bool hasSidecar;

public:
    Motorcycle(int id, const std::string& brand, int year, bool hasSidecar);

    void displayInfo() const override;
    void updateInfo() override;
};

#endif // MOTORCYCLE_HPP