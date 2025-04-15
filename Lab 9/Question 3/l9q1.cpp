#include <iostream>
#include <string>
class Vehicle {
protected:
    std::string model;
    double rate;

public:
    Vehicle(std::string n, double m) : model(n), rate(m) {}
    virtual double getDailyRate() = 0;  // Pure virtual function
    virtual void displayDetails() = 0;  // Pure virtual function
};

class Car : public Vehicle {
public:
    Car(std::string n, double r) : Vehicle(n, r) {}

    double getDailyRate() override {
        return rate;
    }
    void displayDetails() override {
        std::cout << "Car Model: " << model << ", Daily Rate: " << rate << std::endl;
    }
};
class Bike : public Vehicle {
public:
    Bike(std::string n, double r) : Vehicle(n, r) {}

    double getDailyRate() override {
        return rate;
    }

    void displayDetails() override {
        std::cout << "Bike Model: " << model << ", Daily Rate: " << rate << std::endl;
    }
};

int main() {

    Car c1("Tesla Model 3", 50000);
    Bike b1("Honda 150", 3000); 
         
    Vehicle* v1 = &c1;
    Vehicle* v2 = &b1;
    v1->displayDetails();
    std::cout << "Daily Rate: " << v1->getDailyRate() << std::endl;
    v2->displayDetails();
    std::cout << "Daily Rate: " << v2->getDailyRate() << std::endl;

    return 0;
}
