#include <iostream>
#include <string>

class Vehicle {
protected:
    std::string brand;
    int year;

public:
    Vehicle(const std::string& brand, int year) : brand(brand), year(year) {}

    virtual void displayInfo() const {
        std::cout << "Brand: " << brand << ", Year: " << year << std::endl;
    }

    virtual ~Vehicle() {}
};

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

int main() {
    Vehicle* vehicles[2];
    vehicles[0] = new Car("Toyota", 2020, 4);
    vehicles[1] = new Motorcycle("Harley-Davidson", 2018, true);

    for (int i = 0; i < 2; ++i) {
        vehicles[i]->displayInfo();
        delete vehicles[i];
    }

    return 0;
}