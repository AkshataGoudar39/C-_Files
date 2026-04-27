#include <iostream>
#include <string>
#include <vector>

// Base class demonstrating encapsulation and inheritance
class Vehicle {
private:
    std::string make;
    std::string model;
    int year;

protected:
    double fuelLevel;

public:
    // Constructor
    Vehicle(std::string mk, std::string mdl, int yr) : make(mk), model(mdl), year(yr), fuelLevel(100.0) {}

    // Destructor
    virtual ~Vehicle() {
        std::cout << "Vehicle " << make << " " << model << " destroyed." << std::endl;
    }

    // Getter methods (encapsulation)
    std::string getMake() const { return make; }
    std::string getModel() const { return model; }
    int getYear() const { return year; }

    // Setter methods
    void setFuelLevel(double level) { fuelLevel = level; }

    // Virtual method for polymorphism
    virtual void drive(double distance) {
        std::cout << "Driving " << distance << " km in a generic vehicle." << std::endl;
        fuelLevel -= distance * 0.1; // Assume 10 liters per 100 km
    }

    // Pure virtual method (abstract)
    virtual void honk() const = 0;

    // Method to display info
    void displayInfo() const {
        std::cout << "Make: " << make << ", Model: " << model << ", Year: " << year << ", Fuel: " << fuelLevel << "%" << std::endl;
    }
};

// Derived class demonstrating inheritance and polymorphism
class Car : public Vehicle {
private:
    int numDoors;

public:
    // Constructor
    Car(std::string mk, std::string mdl, int yr, int doors) : Vehicle(mk, mdl, yr), numDoors(doors) {}

    // Destructor
    ~Car() override {
        std::cout << "Car " << getMake() << " " << getModel() << " destroyed." << std::endl;
    }

    // Overridden method (polymorphism)
    void drive(double distance) override {
        std::cout << "Driving " << distance << " km in a car with " << numDoors << " doors." << std::endl;
        fuelLevel -= distance * 0.08; // Cars are more efficient
    }

    // Implementation of pure virtual method
    void honk() const override {
        std::cout << "Beep beep! Car horn." << std::endl;
    }

    // Additional method
    void openTrunk() {
        std::cout << "Opening trunk of the car." << std::endl;
    }
};

// Another derived class
class Truck : public Vehicle {
private:
    double loadCapacity;

public:
    // Constructor
    Truck(std::string mk, std::string mdl, int yr, double capacity) : Vehicle(mk, mdl, yr), loadCapacity(capacity) {}

    // Destructor
    ~Truck() override {
        std::cout << "Truck " << getMake() << " " << getModel() << " destroyed." << std::endl;
    }

    // Overridden method
    void drive(double distance) override {
        std::cout << "Driving " << distance << " km in a truck with " << loadCapacity << " tons capacity." << std::endl;
        fuelLevel -= distance * 0.15; // Trucks consume more fuel
    }

    // Implementation of pure virtual method
    void honk() const override {
        std::cout << "Honk honk! Truck horn." << std::endl;
    }

    // Additional method
    void loadCargo(double weight) {
        if (weight <= loadCapacity) {
            std::cout << "Loaded " << weight << " tons of cargo." << std::endl;
        } else {
            std::cout << "Cannot load " << weight << " tons. Capacity is " << loadCapacity << " tons." << std::endl;
        }
    }
};

// Main function demonstrating OOP concepts
int main() {
    // Creating objects (instances of classes)
    Car myCar("Toyota", "Camry", 2020, 4);
    Truck myTruck("Ford", "F-150", 2019, 5.0);

    // Vector to hold base class pointers (polymorphism)
    std::vector<Vehicle*> vehicles;
    vehicles.push_back(&myCar);
    vehicles.push_back(&myTruck);

    // Displaying info
    for (auto* v : vehicles) {
        v->displayInfo();
        v->honk();
        v->drive(50.0);
        std::cout << std::endl;
    }

    // Specific methods
    myCar.openTrunk();
    myTruck.loadCargo(3.0);
    myTruck.loadCargo(6.0);

    // Demonstrating encapsulation
    myCar.setFuelLevel(80.0);
    myCar.displayInfo();

    return 0;
}