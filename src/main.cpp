#include <iostream>
#include <memory>
#include "VehicleManagementSystem.hpp"
#include "Car.hpp"
#include "Motorcycle.hpp"
#include "Truck.hpp"
#include "Utils.hpp"

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