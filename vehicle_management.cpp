#include <iostream>
#include <string>
#include <vector>

// Base class
class Vehicle {
protected:
    std::string brand;
    int year;

public:
    Vehicle(const std::string& brand, int year)
        : brand(brand), year(year) {}

    virtual void displayInfo() const {
        std::cout << "Brand: " << brand << "\nYear: " << year << std::endl;
    }

    virtual ~Vehicle() {}
};

// Derived class for Cars
class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(const std::string& brand, int year, int numDoors)
        : Vehicle(brand, year), numDoors(numDoors) {}

    void displayInfo() const override {
        Vehicle::displayInfo();
        std::cout << "Number of doors: " << numDoors << std::endl;
    }
};

// Derived class for Motorcycles
class Motorcycle : public Vehicle {
private:
    bool hasSidecar;

public:
    Motorcycle(const std::string& brand, int year, bool hasSidecar)
        : Vehicle(brand, year), hasSidecar(hasSidecar) {}

    void displayInfo() const override {
        Vehicle::displayInfo();
        std::cout << "Has sidecar: " << (hasSidecar ? "Yes" : "No") << std::endl;
    }
};

// Main function to demonstrate the Vehicle Management System
int main() {
    // Creating a vector to store Vehicle pointers
    std::vector<Vehicle*> vehicles;

    // Adding vehicles to the system
    vehicles.push_back(new Car("Toyota", 2020, 4));
    vehicles.push_back(new Motorcycle("Harley-Davidson", 2018, true));

    // Displaying vehicle information
    for (const auto& vehicle : vehicles) {
        vehicle->displayInfo();
        std::cout << "----------------------" << std::endl;
    }

    // Cleaning up dynamically allocated memory
    for (auto& vehicle : vehicles) {
        delete vehicle;
    }

    return 0;
}