#include "Vehicle.hpp"

Vehicle::Vehicle(int id, const std::string& brand, int year) : id(id), brand(brand), year(year) {}

Vehicle::~Vehicle() {}

void Vehicle::displayInfo() const {
    std::cout << "ID: " << id << "\nBrand: " << brand << "\nYear: " << year << std::endl;
}

int Vehicle::getId() const {
    return id;
}

void Vehicle::updateInfo() {
    std::cout << "Enter new brand: ";
    std::cin >> brand;
    std::cout << "Enter new year: ";
    std::cin >> year;
}