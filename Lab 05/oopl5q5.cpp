// Keeping in mind our previous car example, write a class that represents a car, and use aggregation and
// composition to combine different components like engine, wheels, headlights and steering to create the
// car object.
// Hint: create the individual classes first before performing the composition. Remember
// that for aggregation, you will need pointers! You’ll be needing constructors and setters to
// set these values in case of aggregation. Same hint applies to other questions.


#include <iostream>
using namespace std;

class Engine
{
public:
    Engine()
    {
        cout << "Engine created." << endl;
    }

    ~Engine()
    {
        cout << "Engine destroyed." << endl;
    }
};

class Wheels
{
public:
    Wheels()
    {
        cout << "Wheels created." << endl;
    }

    ~Wheels()
    {
        cout << "Wheels destroyed." << endl;
    }
};

class Headlights
{
public:
    Headlights()
    {
        cout << "Headlights created." << endl;
    }

    ~Headlights()
    {
        cout << "Headlights destroyed." << endl;
    }
};

class Steering
{
public:
    Steering()
    {
        cout << "Steering created." << endl;
    }

    ~Steering()
    {
        cout << "Steering destroyed." << endl;
    }
};

class Car
{
    Engine *engine;
    Wheels *wheels;
    Steering steering;
    Headlights headlights;

public:
    Car() : engine(nullptr), wheels(nullptr) {}
    Car(Engine *e, Wheels *w) : engine(e), wheels(w)
    {
        cout << "Car has been created." << endl;
    }

    void setEngine(Engine *e) { engine = e; }

    void setWheels(Wheels *w) { wheels = w; }

    ~Car()
    {
        cout << "Car has been destroyed." << endl;
    }
};

int main()
{
    Engine v12;
    Wheels michelin;
    Car Bentley(&v12, &michelin);
    return 0;
}