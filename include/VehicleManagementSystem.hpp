#ifndef VEHICLEMANAGEMENTSYSTEM_HPP
#define VEHICLEMANAGEMENTSYSTEM_HPP

#include <vector>
#include <memory>
#include "Vehicle.hpp"

class VehicleManagementSystem {
private:
    std::vector<std::unique_ptr<Vehicle>> vehicles;

public:
    void addVehicle(std::unique_ptr<Vehicle> vehicle);
    void removeVehicle(const std::string& brand, int year);
    void displayVehicles() const;
    Vehicle* searchVehicle(const std::string& brand) const;
    bool updateVehicle(const std::string& brand, int year);
};

#endif // VEHICLEMANAGEMENTSYSTEM_HPP