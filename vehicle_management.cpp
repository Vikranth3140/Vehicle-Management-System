#include <algorithm>
#include <iostream>
#include <memory>
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

    virtual std::string getBrand() const {
        return brand;
    }

    virtual int getYear() const {
        return year;
    }

    virtual void updateInfo() {
        std::cout << "Enter new brand: ";
        std::cin >> brand;
        std::cout << "Enter new year: ";
        std::cin >> year;
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
    }

    void updateInfo() override {
        Vehicle::updateInfo();
        std::cout << "Enter new number of doors: ";
        std::cin >> numDoors;
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
    void updateInfo() override {
        Vehicle::updateInfo();
        std::cout << "Has sidecar (1 for yes, 0 for no): ";
        std::cin >> hasSidecar;
    }
};

// Derived class for Trucks
class Truck : public Vehicle {
private:
    double loadCapacity;

public:
    Truck(const std::string& brand, int year, double loadCapacity)
        : Vehicle(brand, year), loadCapacity(loadCapacity) {}

    void displayInfo() const override {
        Vehicle::displayInfo();
        std::cout << "Load capacity: " << loadCapacity << " tons" << std::endl;
    }

    void updateInfo() override {
        Vehicle::updateInfo();
        std::cout << "Enter new load capacity: ";
        std::cin >> loadCapacity;
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

    void removeVehicle(const std::string& brand, int year) {
        vehicles.erase(std::remove_if(vehicles.begin(), vehicles.end(),
                                      [&brand, year](const std::unique_ptr<Vehicle>& vehicle) {
                                          return vehicle->getBrand() == brand && vehicle->getYear() == year;
                                      }),
                       vehicles.end());
    }

    void displayVehicles() const {
        if (vehicles.empty()) {
            std::cout << "No vehicles in the system.\n";
            return;
        }
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

    void updateVehicle(const std::string& brand, int year) {
        for (auto& vehicle : vehicles) {
            if (vehicle->getBrand() == brand && vehicle->getYear() == year) {
                vehicle->updateInfo();
                return;
            }
        }
        std::cout << "Vehicle not found.\n";
    }
};

void showMenu() {
    std::cout << "Vehicle Management System\n";
    std::cout << "1. Add Car\n";
    std::cout << "2. Add Motorcycle\n";
    std::cout << "3. Add Truck\n";
    std::cout << "4. Remove Vehicle\n";
    std::cout << "5. Display Vehicles\n";
    std::cout << "6. Search Vehicle\n";
    std::cout << "7. Update Vehicle\n";
    std::cout << "8. Exit\n";
}

int main() {
    VehicleManagementSystem vms;
    int choice;

    do {
        showMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string brand;
            int year, numDoors;
            std::cout << "Enter brand: ";
            std::cin >> brand;
            std::cout << "Enter year: ";
            std::cin >> year;
            std::cout << "Enter number of doors: ";
            std::cin >> numDoors;
            vms.addVehicle(std::make_unique<Car>(brand, year, numDoors));
            break;
        }
        case 2: {
            std::string brand;
            int year;
            bool hasSidecar;
            std::cout << "Enter brand: ";
            std::cin >> brand;
            std::cout << "Enter year: ";
            std::cin >> year;
            std::cout << "Has sidecar (1 for yes, 0 for no): ";
            std::cin >> hasSidecar;
            vms.addVehicle(std::make_unique<Motorcycle>(brand, year, hasSidecar));
            break;
        }
        case 3: {
            std::string brand;
            int year;
            double loadCapacity;
            std::cout << "Enter brand: ";
            std::cin >> brand;
            std::cout << "Enter year: ";
            std::cin >> year;
            std::cout << "Enter load capacity (in tons): ";
            std::cin >> loadCapacity;
            vms.addVehicle(std::make_unique<Truck>(brand, year, loadCapacity));
            break;
        }
        case 4: {
            std::string brand;
            int year;
            std::cout << "Enter brand to remove: ";
            std::cin >> brand;
            std::cout << "Enter year to remove: ";
            std::cin >> year;
            vms.removeVehicle(brand, year);
            break;
        }
        case 5:
            vms.displayVehicles();
            break;
        case 6: {
            std::string brand;
            std::cout << "Enter brand to search: ";
            std::cin >> brand;
            Vehicle* vehicle = vms.searchVehicle(brand);
            if (vehicle) {
                vehicle->displayInfo();
            } else {
                std::cout << "Vehicle not found.\n";
            }
            break;
        }
        case 7: {
            std::string brand;
            int year;
            std::cout << "Enter brand to update: ";
            std::cin >> brand;
            std::cout << "Enter year to update: ";
            std::cin >> year;
            vms.updateVehicle(brand, year);
            break;
        }
        case 8:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}