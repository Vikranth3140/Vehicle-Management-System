#include "VehicleManagementSystem.hpp"
#include <algorithm> // Include this header for std::remove_if

void VehicleManagementSystem::addVehicle(std::unique_ptr<Vehicle> vehicle) {
    vehicles.push_back(std::move(vehicle));
}

bool VehicleManagementSystem::removeVehicle(int id) {
    auto it = std::remove_if(vehicles.begin(), vehicles.end(),
                             [id](const std::unique_ptr<Vehicle>& vehicle) {
                                 return vehicle->getId() == id;
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

Vehicle* VehicleManagementSystem::searchVehicle(int id) const {
    for (const auto& vehicle : vehicles) {
        if (vehicle->getId() == id) {
            return vehicle.get();
        }
    }
    return nullptr;
}

bool VehicleManagementSystem::updateVehicle(int id) {
    for (auto& vehicle : vehicles) {
        if (vehicle->getId() == id) {
            vehicle->updateInfo();
            return true;
        }
    }
    return false;
}

int VehicleManagementSystem::generateNextId() {
    return nextId++;
}