// Problem: A homeowner wants to integrate smart lights and thermostats from different
// brands into a single app. The system must provide a unified way to turn devices on/off,
// adjust settings, and check statuses without requiring users to interact with brand-specific
// interfaces. Future devices (e.g., smart locks) should integrate without altering the core
// system.
// Classes and Structure:
// • Abstract Class SmartDevice:
// o Member Functions:

// ▪ turnOn(): Pure virtual function to activate the device.
// ▪ turnOff(): Pure virtual function to deactivate the device.
// ▪ getStatus(): Pure virtual function to return the device’s current state.

// • Derived Class LightBulb:
// o Data Members:
// ▪ isOn (bool): Tracks if the light is on/off.
// ▪ brightness (int): Stores brightness level (0-100%).
// o Implements turnOn(), turnOff(), and getStatus() for light control.
// • Derived Class Thermostat:
// o Data Members:
// ▪ isOn (bool): Tracks if the thermostat is active.
// ▪ temperature (double): Stores the current temperature setting.
// o Implements turnOn(), turnOff(), and getStatus() for temperature control.

// Flow:
// • Create LightBulb and Thermostat objects.
// • Turn devices on/off and display their statuses.
#include<iostream>
#include<string>
class SmartDevice{
    protected: 
    bool isOn;
    public:
    SmartDevice(bool o): isOn(o) {}; 
    virtual  void turnOn () =0;
    virtual void turnOff() =0;
    virtual void getStatus() =0;
};
class LightBulb : public SmartDevice {
    private:
    int brightness;
    public: 
    LightBulb (bool o, int b) : SmartDevice(o) , brightness(b) {} ;
    void turnOn () override {
        std::cout<<"Bulb turned on"<<std::endl;
    }
    void turnOff() override {
        std::cout<<"Bulb turned off"<<std::endl;
    }
    void getStatus() override {
        std::cout<<"Bulb is"<<(isOn ? "On" : "Off")<<" Brightness :"<< brightness <<std::endl;
    }
};
class Thermostat : public SmartDevice {
    private:
    double temp;
    public: 
    Thermostat(bool o, double t) : SmartDevice (o), temp(t) {};
    void turnOn () override {
        std::cout<<"Thermostat turned on"<<std::endl;
    }
    void turnOff() override {
        std::cout<<"Thermostat turned off"<<std::endl;
    }
    void getStatus() override {
        std::cout<<"THermostat is"<<(isOn ? "On" : "Off")<<" Temperature:"<< temp <<std::endl;
    }
};
int main () {
    LightBulb l1(false,50);
    Thermostat t1(false,102.4);
    l1.turnOn();
    l1.turnOff();
    l1.getStatus();
    t1.turnOn();
    t1.turnOff();
    t1.getStatus();

}