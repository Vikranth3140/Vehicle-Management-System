#include <iostream>
#include <memory>
#include <cstdlib>
#include "VehicleManagementSystem.hpp"
#include "Car.hpp"
#include "Motorcycle.hpp"
#include "Truck.hpp"
#include "Utils.hpp"

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void showMenu() {
    std::cout << "\n==============================\n";
    std::cout << "Vehicle Management System\n";
    std::cout << "==============================\n";
    std::cout << "1. Add Car\n";
    std::cout << "2. Add Motorcycle\n";
    std::cout << "3. Add Truck\n";
    std::cout << "4. Remove Vehicle\n";
    std::cout << "5. Display Vehicles\n";
    std::cout << "6. Search Vehicle\n";
    std::cout << "7. Update Vehicle\n";
    std::cout << "8. Exit\n";
    std::cout << "==============================\n";
    std::cout << "Enter your choice: ";
}

void addCar(VehicleManagementSystem& vms) {
    std::string brand;
    int year, numDoors;
    std::cout << "\nEnter Car Details:\n";
    std::cout << "------------------\n";
    std::cout << "Brand: ";
    std::cin >> brand;
    std::cout << "Year: ";
    std::cin >> year;
    std::cout << "Number of doors: ";
    std::cin >> numDoors;
    vms.addVehicle(std::make_unique<Car>(brand, year, numDoors));
    std::cout << "\nCar added successfully.\n";
}

void addMotorcycle(VehicleManagementSystem& vms) {
    std::string brand;
    int year;
    bool hasSidecar;
    std::cout << "\nEnter Motorcycle Details:\n";
    std::cout << "-------------------------\n";
    std::cout << "Brand: ";
    std::cin >> brand;
    std::cout << "Year: ";
    std::cin >> year;
    std::cout << "Has sidecar (1 for yes, 0 for no): ";
    std::cin >> hasSidecar;
    vms.addVehicle(std::make_unique<Motorcycle>(brand, year, hasSidecar));
    std::cout << "\nMotorcycle added successfully.\n";
}

void addTruck(VehicleManagementSystem& vms) {
    std::string brand;
    int year;
    double loadCapacity;
    std::cout << "\nEnter Truck Details:\n";
    std::cout << "--------------------\n";
    std::cout << "Brand: ";
    std::cin >> brand;
    std::cout << "Year: ";
    std::cin >> year;
    std::cout << "Load capacity (in tons): ";
    std::cin >> loadCapacity;
    vms.addVehicle(std::make_unique<Truck>(brand, year, loadCapacity));
    std::cout << "\nTruck added successfully.\n";
}

void removeVehicle(VehicleManagementSystem& vms) {
    std::string brand;
    int year;
    std::cout << "\nEnter Vehicle Details to Remove:\n";
    std::cout << "--------------------------------\n";
    std::cout << "Brand: ";
    std::cin >> brand;
    std::cout << "Year: ";
    std::cin >> year;
    if (vms.removeVehicle(brand, year)) {
        std::cout << "\nVehicle removed successfully.\n";
    } else {
        std::cout << "\nVehicle not found.\n";
    }
}

void searchVehicle(VehicleManagementSystem& vms) {
    std::string brand;
    std::cout << "\nEnter Brand to Search:\n";
    std::cout << "----------------------\n";
    std::cout << "Brand: ";
    std::cin >> brand;
    Vehicle* vehicle = vms.searchVehicle(brand);
    if (vehicle) {
        std::cout << "\n";
        vehicle->displayInfo();
    } else {
        std::cout << "\nVehicle not found.\n";
    }
}

void updateVehicle(VehicleManagementSystem& vms) {
    std::string brand;
    int year;
    std::cout << "\nEnter Vehicle Details to Update:\n";
    std::cout << "--------------------------------\n";
    std::cout << "Brand: ";
    std::cin >> brand;
    std::cout << "Year: ";
    std::cin >> year;
    if (vms.updateVehicle(brand, year)) {
        std::cout << "\nVehicle updated successfully.\n";
    } else {
        std::cout << "\nVehicle not found.\n";
    }
}

int main() {
    clearScreen();

    VehicleManagementSystem vms;
    int choice;

    do {
        showMenu();
        std::cin >> choice;

        std::cout << "\n";
        switch (choice) {
        case 1:
            addCar(vms);
            break;
        case 2:
            addMotorcycle(vms);
            break;
        case 3:
            addTruck(vms);
            break;
        case 4:
            removeVehicle(vms);
            break;
        case 5:
            vms.displayVehicles();
            break;
        case 6:
            searchVehicle(vms);
            break;
        case 7:
            updateVehicle(vms);
            break;
        case 8:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

        std::cout << "\n";
    } while (choice != 8);

    return 0;
}