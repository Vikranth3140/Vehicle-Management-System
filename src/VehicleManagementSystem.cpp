#include "VehicleManagementSystem.hpp"

void VehicleManagementSystem::addVehicle(std::unique_ptr<Vehicle> vehicle) {
    vehicles.push_back(std::move(vehicle));
}

void VehicleManagementSystem::removeVehicle(const std::string& brand, int year) {
    vehicles.erase(std::remove_if(vehicles.begin(), vehicles.end(),
                                  [&brand, year](const std::unique_ptr<Vehicle>& vehicle) {
                                      return vehicle->getBrand() == brand && vehicle->getYear() == year;
                                  }),
                   vehicles.end());
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

void VehicleManagementSystem::updateVehicle(const std::string& brand, int year) {
    for (auto& vehicle : vehicles) {
        if (vehicle->getBrand() == brand && vehicle->getYear() == year) {
            vehicle->updateInfo();
            return;
        }
    }
    std::cout << "Vehicle not found.\n";
}