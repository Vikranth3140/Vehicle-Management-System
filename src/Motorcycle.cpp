#include "Motorcycle.hpp"

Motorcycle::Motorcycle(const std::string& brand, int year, bool hasSidecar)
    : Vehicle(brand, year), hasSidecar(hasSidecar) {}

void Motorcycle::displayInfo() const {
    Vehicle::displayInfo();
    std::cout << "Has sidecar: " << (hasSidecar ? "Yes" : "No") << std::endl;
}

void Motorcycle::updateInfo() {
    Vehicle::updateInfo();
    std::cout << "Has sidecar (1 for yes, 0 for no): ";
    std::cin >> hasSidecar;
}