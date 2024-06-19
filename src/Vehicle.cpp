#include "Vehicle.hpp"

Vehicle::Vehicle(const std::string& brand, int year) : brand(brand), year(year) {}

Vehicle::~Vehicle() {}

void Vehicle::displayInfo() const {
    std::cout << "Brand: " << brand << "\nYear: " << year << std::endl;
}

std::string Vehicle::getBrand() const {
    return brand;
}

int Vehicle::getYear() const {
    return year;
}

void Vehicle::updateInfo() {
    std::cout << "Enter new brand: ";
    std::cin >> brand;
    std::cout << "Enter new year: ";
    std::cin >> year;
}