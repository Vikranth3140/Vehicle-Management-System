# Vehicle Management System

This is a simple console-based Vehicle Management System implemented in C++. It allows you to manage a collection of vehicles (cars, motorcycles, and trucks) using Object-Oriented Programming (OOP) principles such as inheritance and polymorphism. Each vehicle is uniquely identified by a vehicle ID.

## Features

- **Add Vehicles**: Add new cars, motorcycles, and trucks to the system.
- **Remove Vehicles**: Remove vehicles from the system using their unique ID.
- **Display Vehicles**: Display details of all vehicles in the system.
- **Search Vehicles**: Search for a vehicle by its unique ID.
- **Update Vehicles**: Update the details of an existing vehicle using its unique ID.

## Class Structure

### Vehicle (Base Class)
- Attributes: `id`, `brand`, `year`
- Methods:
  - `displayInfo()`: Displays vehicle details.
  - `getId()`: Returns the vehicle ID.
  - `updateInfo()`: Updates the vehicle details.

### Car (Derived from Vehicle)
- Additional Attribute: `numDoors`
- Methods:
  - `displayInfo()`: Displays car details.
  - `updateInfo()`: Updates the car details.

### Motorcycle (Derived from Vehicle)
- Additional Attribute: `hasSidecar`
- Methods:
  - `displayInfo()`: Displays motorcycle details.
  - `updateInfo()`: Updates the motorcycle details.

### Truck (Derived from Vehicle)
- Additional Attribute: `loadCapacity`
- Methods:
  - `displayInfo()`: Displays truck details.
  - `updateInfo()`: Updates the truck details.

### VehicleManagementSystem
- Attributes: `vehicles` (vector of unique pointers to Vehicle), `nextId` (auto-incrementing ID)
- Methods:
  - `addVehicle()`: Adds a new vehicle to the system.
  - `removeVehicle()`: Removes a vehicle by ID.
  - `displayVehicles()`: Displays all vehicles.
  - `searchVehicle()`: Searches for a vehicle by ID.
  - `updateVehicle()`: Updates a vehicle by ID.
  - `generateNextId()`: Generates the next unique ID for a vehicle.

## Installation and Compilation

1. **Clone the repository:**

   ```sh
   git clone https://github.com/Vikranth3140/Vehicle-Management-System.git
   cd Vehicle-Management-System
   ```

2. **Compile the project:**

   ```sh
   make
   ```

3. **Run the compiled program:**

   ```sh
   ./bin/vehicle_management
   ```

## Directory Structure:
  
  ```
  vehicle_management_system/
  ├── include/
  │   ├── Car.hpp
  │   ├── Motorcycle.hpp
  │   ├── Truck.hpp
  │   ├── Utils.hpp
  │   ├── Vehicle.hpp
  │   └── VehicleManagementSystem.hpp
  ├── src/
  │   ├── Car.cpp
  │   ├── Motorcycle.cpp
  │   ├── Truck.cpp
  │   ├── Vehicle.cpp
  │   ├── VehicleManagementSystem.cpp
  │   └── main.cpp
  ├── Makefile
  ├── .gitignore
  ├── README.md
  ├── LICENSE
  ```

## Usage

When you run the program, you will be presented with a menu:

```
==============================
Vehicle Management System
==============================
1. Add Car
2. Add Motorcycle
3. Add Truck
4. Remove Vehicle
5. Display Vehicles
6. Search Vehicle
7. Update Vehicle
8. Exit
==============================
Enter your choice:
```

Follow the on-screen prompts to add, remove, display, search, or update vehicles. Each operation is straightforward and self-explanatory.

## Example

### Adding a Car

```
Enter Car Details:
------------------
Brand: Volvo
Year: 2024
Number of doors: 4

Car added successfully with ID: 1
```

### Displaying Vehicles

```
==============================
Vehicle Management System
==============================
1. Add Car
2. Add Motorcycle
3. Add Truck
4. Remove Vehicle
5. Display Vehicles
6. Search Vehicle
7. Update Vehicle
8. Exit
==============================
Enter your choice: 5

ID: 1
Brand: Volvo
Year: 2024
Number of doors: 4
----------------------
```

## License

This project is licensed under the [MIT License](LICENSE).
