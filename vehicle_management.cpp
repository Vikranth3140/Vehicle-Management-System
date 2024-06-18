#include <iostream>
#include <string>
#include <vector>
#include <memory>

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

// Vehicle Management System
class VehicleManagementSystem {
private:
    std::vector<std::unique_ptr<Vehicle>> vehicles;

public:
    void addVehicle(std::unique_ptr<Vehicle> vehicle) {
        vehicles.push_back(std::move(vehicle));
    }

    void removeVehicle(const std::string& brand) {
        vehicles.erase(std::remove_if(vehicles.begin(), vehicles.end(),
                                      [&brand](const std::unique_ptr<Vehicle>& vehicle) {
                                          return vehicle->getBrand() == brand;
                                      }),
                       vehicles.end());
    }

    void displayVehicles() const {
        for (const auto& vehicle : vehicles) {
            vehicle->displayInfo();
            std::cout << "----------------------" << std::endl;
        }
    }

    Vehicle* searchVehicle(const std::string& brand) const {
        for (const auto& vehicle : vehicles) {
            if (vehicle->getBrand() == brand) {
                return vehicle.get();
            }
        }
        return nullptr;
    }
};