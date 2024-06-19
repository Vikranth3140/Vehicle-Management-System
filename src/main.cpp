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
    int id = vms.generateNextId();
    std::cout << "\nEnter Car Details:\n";
    std::cout << "------------------\n";
    std::cout << "Brand: ";
    std::cin >> brand;
    std::cout << "Year: ";
    std::cin >> year;
    std::cout << "Number of doors: ";
    std::cin >> numDoors;
    vms.addVehicle(std::make_unique<Car>(id, brand, year, numDoors));
    std::cout << "\nCar added successfully with ID: " << id << "\n";
}

void addMotorcycle(VehicleManagementSystem& vms) {
    std::string brand;
    int year;
    bool hasSidecar;
    int id = vms.generateNextId();
    std::cout << "\nEnter Motorcycle Details:\n";
    std::cout << "-------------------------\n";
    std::cout << "Brand: ";
    std::cin >> brand;
    std::cout << "Year: ";
    std::cin >> year;
    std::cout << "Has sidecar (1 for yes, 0 for no): ";
    std::cin >> hasSidecar;
    vms.addVehicle(std::make_unique<Motorcycle>(id, brand, year, hasSidecar));
    std::cout << "\nMotorcycle added successfully with ID: " << id << "\n";
}

void addTruck(VehicleManagementSystem& vms) {
    std::string brand;
    int year;
    double loadCapacity;
    int id = vms.generateNextId();
    std::cout << "\nEnter Truck Details:\n";
    std::cout << "--------------------\n";
    std::cout << "Brand: ";
    std::cin >> brand;
    std::cout << "Year: ";
    std::cin >> year;
    std::cout << "Load capacity (in tons): ";
    std::cin >> loadCapacity;
    vms.addVehicle(std::make_unique<Truck>(id, brand, year, loadCapacity));
    std::cout << "\nTruck added successfully with ID: " << id << "\n";
}

void removeVehicle(VehicleManagementSystem& vms) {
    int id;
    std::cout << "\nEnter Vehicle ID to Remove:\n";
    std::cout << "---------------------------\n";
    std::cout << "ID: ";
    std::cin >> id;
    if (vms.removeVehicle(id)) {
        std::cout << "\nVehicle removed successfully.\n";
    } else {
        std::cout << "\nVehicle not found.\n";
    }
}

void searchVehicle(VehicleManagementSystem& vms) {
    int id;
    std::cout << "\nEnter Vehicle ID to Search:\n";
    std::cout << "---------------------------\n";
    std::cout << "ID: ";
    std::cin >> id;
    Vehicle* vehicle = vms.searchVehicle(id);
    if (vehicle) {
        std::cout << "\n";
        vehicle->displayInfo();
    } else {
        std::cout << "\nVehicle not found.\n";
    }
}

void updateVehicle(VehicleManagementSystem& vms) {
    int id;
    std::cout << "\nEnter Vehicle ID to Update:\n";
    std::cout << "---------------------------\n";
    std::cout << "ID: ";
    std::cin >> id;
    if (vms.updateVehicle(id)) {
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
            std::cout << "Thank You!\nExiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

        std::cout << "\n";
    } while (choice != 8);

    return 0;
}