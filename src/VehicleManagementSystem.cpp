#include "VehicleManagementSystem.hpp"
#include <algorithm> // Include this header for std::remove_if

void VehicleManagementSystem::addVehicle(std::unique_ptr<Vehicle> vehicle) {
    vehicles.push_back(std::move(vehicle));
}

bool VehicleManagementSystem::removeVehicle(const std::string& brand, int year) {
    auto it = std::remove_if(vehicles.begin(), vehicles.end(),
                             [&brand, year](const std::unique_ptr<Vehicle>& vehicle) {
                                 return vehicle->getBrand() == brand && vehicle->getYear() == year;
                             });
    if (it != vehicles.end()) {
        vehicles.erase(it, vehicles.end());
        return true;
    }
    return false;
}

void VehicleManagementSystem::displayVehicles() const {
    if (vehicles.empty()) {
        std::cout << "No vehicles in the system.\n";
        return;
    }
    for (const auto& vehicle : vehicles) {
        vehicle->displayInfo();
        std::cout << "----------------------" << std::endl;
    }
}

Vehicle* VehicleManagementSystem::searchVehicle(const std::string& brand) const {
    for (const auto& vehicle : vehicles) {
        if (vehicle->getBrand() == brand) {
            return vehicle.get();
        }
    }
    return nullptr;
}

bool VehicleManagementSystem::updateVehicle(const std::string& brand, int year) {
    for (auto& vehicle : vehicles) {
        if (vehicle->getBrand() == brand && vehicle->getYear() == year) {
            vehicle->updateInfo();
            return true;
        }
    }
    return false;
}