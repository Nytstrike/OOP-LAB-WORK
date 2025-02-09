// In ocean navigation, locations are measured in degrees and minutes of latitude and longitude. Thus if you’re lying
// off the mouth of Papeete Harbor in Tahiti, your location is 149 degrees 34.8 minutes west longitude, and 17
// degrees 31.5 minutes south latitude. This is written as 149°34.8’ W, 17°31.5’ S. There are 60 minutes in a degree.
// (An older system also divided a minute into 60 seconds, but the modern approach is to use decimal minutes
// instead.) Longitude is measured from 0 to 180 degrees, east or west from Greenwich, England, to the international
// dateline in the Pacific. Latitude is measured from 0 to 90 degrees, north or south from the equator to the poles.
// Create a class angle that includes three member variables: an int for degrees, a float for minutes, and a char for the
// direction letter (N, S, E, or W). This class can hold either a latitude variable or a longitude variable. Write one
// member function to obtain an angle value (in degrees and minutes) and a direction from the user, and a second to
// display the angle value in 179°59.9’ E format. Also write a three-argument constructor.
// Write a main() program that displays an angle initialized with the constructor, and then, within a loop, allows the
// user to input any angle value, and then displays the value. You can use the hex character constant ‘\xF8’, which
// usually prints a degree (°) symbol.
// Note:
//  fixed: This manipulator is used to display floating-point numbers in fixed-point notation (i.e., a set number
// of digits after the decimal point).
//  setprecision(n): This manipulator sets the number of digits to be displayed after the decimal point. For
// example, setprecision(1) ensures that only one digit will be displayed after the decimal point, as seen in
// your angle minutes.
#include <iostream>
#include <iomanip>
using namespace std;

class ANGLE {
private:
    int degrees;
    float minutes;
    char direction;

public:
    ANGLE() {
        degrees = 0;
        minutes = 0.0;
        direction = 'N';
    }
    ANGLE(int deg, float min, char dir) {
        degrees = deg;
        minutes = min;
        direction = dir;
    }
    int inputAngle() {
        cout << "Enter degrees: ";
        cin >> degrees;
        if(degrees<0 || degrees > 180){
            cout<<"Invalid input for degrees"<<endl;
            degrees= 0;
        }
        cout << "Enter minutes: ";
        if (minutes < 0.0 || minutes >= 60.0) {
            cout << "Invalid minutes! Must be between 0 and 59.9.\n";
            minutes = 0;
        }
        cin >> minutes;
        cout << "Enter direction (N, S, E, W): ";
        cin >> direction;
        if ((direction == 'N' || direction == 'S') && (degrees < 0 || degrees > 90)) {
            cout << "Invalid latitude degrees! Must be between 0 and 90.\n";
            degrees = 0;
        }
        else if ((direction == 'E' || direction == 'W') && (degrees < 0 || degrees > 180)) {
            cout << "Invalid longitude degrees! Must be between 0 and 180.\n";
            degrees = 0;
        }
        else if (direction != 'N' && direction != 'S' && direction != 'E' && direction != 'W') {
            cout << "Invalid direction! Must be N, S, E, or W.\n";
            direction = 'N';
        }
    }


    void outAngle() const {
        cout << fixed << setprecision(1);
        cout << degrees << "\xF8" << minutes << "' " << direction << endl;
    }


    ~ANGLE() {}
};

int main() {
 
    ANGLE latitude;
    ANGLE longitude;


    cout << "Enter latitude details:\n";
    latitude.inputAngle();

    cout << "Enter longitude details:\n";
    longitude.inputAngle();

    cout << "\nEntered Latitude: ";
    latitude.outAngle();

    cout << "Entered Longitude: ";
    longitude.outAngle();

    return 0;
}
