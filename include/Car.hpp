#ifndef CAR_HPP
#define CAR_HPP

#include "Vehicle.hpp"

class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(int id, const std::string& brand, int year, int numDoors);

    void displayInfo() const override;
    void updateInfo() override;
};

#endif // CAR_HPP