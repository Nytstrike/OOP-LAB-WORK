// Create a class called Smartphone with the following attributes:
// ? Company
// ? Model
// ? Display Resolution
// ? RAM
// ? ROM
// ? Storage

// Create getter and setter methods for your attributes. A smartphone has some specific actions that it can perform.
#include<iostream>
#include<string>
using namespace std;
class Smartphone {
    private:
    string company;
    string model;
    string displayResolution;
    int RAM;
    int ROM;
    int storage;
    public:
    // Getter methods
    string getCompany() {
        return company;
        }
        string getModel() {
            return model;
            }
        string getDisplayResolution() {
                return displayResolution;
                }
        int getRAM() {
                    return RAM;
                    }
    int getROM() {
                        return ROM;
                        }
        int getStorage() {
                            return storage;
                            }
                            
void setCompany(string c) {
                        company = c;
                        }
void setModel(string m) {
                        model = m;
                        }
void setDisplayResolution(string d) {
                                    displayResolution = d;
                                        }
void setRAM(int r) {
                    RAM = r;
                    }
void setROM(int rm) {
                    ROM = rm;
                        }
void setStorage(int s) {
                        storage = s;
                        }
                                                    };
int main (){
    Smartphone s1;
    s1.setCompany("Oneplus");
    s1.setModel("N100 plus 5g");
    s1.setDisplayResolution("1080 x 2400 pixels");
    s1.setRAM(12);
    s1.setROM(128);
    s1.setStorage(512);
    cout << "Company: " << s1.getCompany() << endl;
    cout << "Model: " << s1.getModel() << endl;
    cout << "Display Resolution: " << s1.getDisplayResolution() << endl;
}

