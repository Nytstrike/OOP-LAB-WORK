// Create a class called Square with the following attributes:
// • sideLength – float variable
// • area – float variable
// • allareas – static float variable
// Create the following methods for your class:
// • Constructors (default and parameterized (only takes sideLength as input))
// • Function to calculate area, the calculated area should always be added to the allareas
// variable each time an area is calculated. (assume it’s called only once for each object)
// • Getters and Setters for all variables
// In your main functions create 3 Squares with different sideLength. Call the area method for each of
// those Square objects. After each time the area method is called, call that square’s getters for area and
// allareas to display the updated values.
#include<iostream>
#include<cmath>
using namespace std;
class SQUARE{
    float sidelength;
    float area;
    static float allarea;
    public:
    SQUARE() {}
    SQUARE(float sidelength){
            this->sidelength=sidelength;
    }
    void areaCal(){
        area=sidelength*sidelength;
        allarea+=area;
    }
    float getSidelength(){
        return sidelength;
    }
    float getArea(){
        return area;
    }
    static float getAllArea(){
        return allarea;
    }
    void setSidelength(float s){
        sidelength=s;
    }
    void setArea(float a){
        area=a;
    }
    void setAllarea(float all){
        allarea=all;
    }
};

float SQUARE:: allarea =0;
int main (){
    SQUARE s1(45);
    SQUARE s2(56);
    SQUARE s3(34);
    s1.areaCal();
    cout<< "For sidelength:" <<s1.getSidelength()<<endl;
    cout<< "The area is:" <<s1.getArea()<<endl;
    cout<< "All area is:" <<s1.getAllArea()<<endl;
    
    s2.areaCal();
    cout<< "For sidelength:" <<s2.getSidelength()<<endl;
    cout<< "The area is:" <<s2.getArea()<<endl;
    cout<< "All area is:" <<s2.getAllArea()<<endl;
    
    s3.areaCal();
    cout<< "For sidelength:" <<s3.getSidelength()<<endl;
    cout<< "The area is:" <<s3.getArea()<<endl;
    cout<< "All area is:" <<s3.getAllArea()<<endl;
}
