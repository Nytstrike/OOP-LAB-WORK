// Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a 50 cent toll. Mostly they do, but
// sometimes a car goes by without paying. The tollbooth keeps track of the number of cars that have gone by, and of
// the total amount of money collected.
// Model this tollbooth with a class called tollBooth. The two data items are a type unsigned int to hold the total
// number of cars, and a type double to hold the total amount of money collected. A constructor initializes both of
// these to 0. A member function called payingCar() increments the car total and adds 0.50 to the cash total. Another
// function,
// called nopayCar(), increments the car total but adds nothing to the cash total. Finally, a member function called
// display() displays the two totals. Make appropriate member functions const.
// Include a program to test this class. This program should allow the user to push one key to count a paying car, and
// another to count a nonpaying car. Pushing the Esc key should cause the program to print out the total cars and
// total cash and then exit.
// Note: _getch() (from &lt;conio.h&gt;) reads a key press instantly without requiring Enter.
// The loop keeps running until the user presses Esc.the ASCII code 27 is the Esc key
#include <iostream>
#include <conio.h>
using namespace std;
class Tollbooth {
    unsigned int totalCars;
    double totalCash;
    public:
    Tollbooth() {
        totalCars = 0;
        totalCash = 0;
        }
        void payingCar() {
            totalCars++;
            totalCash += 0.50;
            }
            void nopayCar() {
                totalCars++;
}
                void display() const {
                    cout << "\nTotal cars: " << totalCars << endl;
                    cout << "\nTotal cash: $" << totalCash << endl;
}
};
int main() {
    Tollbooth tollbooth;
    char key;
    cout<<"Press P to Pay"<<endl;
    cout<<"Press N to Not Pay"<<endl;
    cout<<"Press Esc to Exit"<<endl;
    while (key != 27) {
        key = _getch();
        if (key == 'p' || key == 'P') {
            cout<<"0.50$ payed\n";
            tollbooth.payingCar();

            }
            else if (key == 'n' || key == 'N') {
                cout<<"No amount payed\n";
                tollbooth.nopayCar();
                }
                else if (key == 27) {
                    tollbooth.display();
                    return 0;
                }
    }
}
