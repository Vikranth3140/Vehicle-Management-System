#include "Truck.hpp"

Truck::Truck(const std::string& brand, int year, double loadCapacity)
    : Vehicle(brand, year), loadCapacity(loadCapacity) {}

void Truck::displayInfo() const {
    Vehicle::displayInfo();
    std::cout << "Load capacity: " << loadCapacity << " tons" << std::endl;
}

void Truck::updateInfo() {
    Vehicle::updateInfo();
    std::cout << "Enter new load capacity: ";
    std::cin >> loadCapacity;
}