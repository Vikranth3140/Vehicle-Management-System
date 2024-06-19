#ifndef VEHICLEMANAGEMENTSYSTEM_HPP
#define VEHICLEMANAGEMENTSYSTEM_HPP

#include <vector>
#include <memory>
#include "Vehicle.hpp"

class VehicleManagementSystem {
private:
    std::vector<std::unique_ptr<Vehicle>> vehicles;
    int nextId = 1; // Auto-incrementing ID

public:
    void addVehicle(std::unique_ptr<Vehicle> vehicle);
    bool removeVehicle(int id);
    void displayVehicles() const;
    Vehicle* searchVehicle(int id) const;
    bool updateVehicle(int id);
    int generateNextId();
};

#endif // VEHICLEMANAGEMENTSYSTEM_HPP