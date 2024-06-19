#include "Car.hpp"

Car::Car(const std::string& brand, int year, int numDoors)
    : Vehicle(brand, year), numDoors(numDoors) {}

void Car::displayInfo() const {
    Vehicle::displayInfo();
    std::cout << "Number of doors: " << numDoors << std::endl;
}

void Car::updateInfo() {
    Vehicle::updateInfo();
    std::cout << "Enter new number of doors: ";
    std::cin >> numDoors;
}