#include <iostream>
#include <string>
using namespace std;

class Device {
protected:
    string brand;
    bool powerOn;

public:
    Device(string b) {
        brand = b;
        powerOn = false;
    }

    void switchOn() {
        powerOn = true;
        cout << brand << " device is ON" << endl;
    }

    void switchOff() {
        powerOn = false;
        cout << brand << " device is OFF" << endl;
    }

    virtual void showDetails() {
        cout << "Brand: " << brand << endl;
        cout << "Power: " << (powerOn ? "ON" : "OFF") << endl;
    }

    // Base method (to be renamed)
    virtual void operate(double duration) {
        cout << "Operating device for " << duration << " hours" << endl;
    }
};