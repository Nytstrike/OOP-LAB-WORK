// Create a class called time that has separate int member data for hours, minutes, and seconds. One constructor
// should initialize this data to 0, and another should initialize it to fixed values. Another member function should
// display it, in 11:59:59 format. The final member function should add two objects of type time passed as
// arguments.
// A main() program should create two initialized time objects (should they be const?) and one that isn’t initialized.
// Then it should add the two initialized values together, leaving the result in the third time variable. Finally it should
// display the value of this third variable. Make appropriate member functions const.
#include<iostream>
using namespace std;
class Time
{
private:
    int hours;
    int minutes;
    int seconds;
public:
    Time() : hours(0), minutes(0), seconds(0) {} 
    Time(int h, int m, int s): hours(h), minutes(m), seconds(s) {}
   Time add(Time t2) {
    Time t3;
    int totalSeconds = seconds + t2.seconds;
    t3.seconds = totalSeconds % 60;  
    int carryMinutes = totalSeconds / 60; 
    int totalMinutes = minutes + t2.minutes + carryMinutes;
    t3.minutes = totalMinutes % 60; 
    int carryHours = totalMinutes / 60; 
    int totalHours = hours + t2.hours + carryHours;
    t3.hours = totalHours % 24;
    return t3;
}
    void display() const{
    	if(hours>12){
    	int	temp;
    		temp=hours-12;
    		 cout<<temp<<":"<<minutes<<":"<<seconds<<"pm";
		}
		else {
			cout<<hours<<":"<<minutes<<":"<<seconds<<"am";
		}
          }
    };
int main (){
    Time t1(11, 30, 27);
    Time t2(2, 45, 34);
    Time t3 = t1.add(t2);
    t3.display();
    return 0;
}
