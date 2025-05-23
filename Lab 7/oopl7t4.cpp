// Imagine designing a digital management system for a large university that seamlessly integrates academic and administrative operations. At the heart of this system is a Person
// class that stores universal data members such as name, id, address, phoneNumber, and email. It provides functions like displayInfo() to show personal details and updateInfo()
// to modify them.

// Derived classes—Student, Professor, and Staff—extend this system by introducing specific data members:
// Student includes coursesEnrolled, GPA, and enrollmentYear, modifying displayInfo() to show academic records.
// Professor has department, coursesTaught, and salary, updating displayInfo() to display faculty-specific details.
// Staff maintains department, position, and salary, tailoring displayInfo() to reflect administrative roles.

// An additional Course class, with attributes like courseld, courseName, credits, instructor, and schedule, provides functions such as registerStudent(student) and
// calculateGrades(). This ensures an interactive system where function overrides enable dynamic role-based management.

#include <iostream>
using namespace std;

class Person{
protected:
    string name;
    string id;
    string address;
    string phoneNumber;
    string email;

public:
    Person(string n, string i, string a, string p, string e) : name(n), id(i), address(a), phoneNumber(p), email(e) {}
    
    string getName() const { return name; }
    virtual void displayInfo(){
        cout << endl << "Displaying information below" << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }

    void updateInfo(string n, string i, string a, string p, string e){
        this->name = n;
        this->id = i;
        this->address = a;
        this->phoneNumber = p;
        this->email = e;
    }
};

class Student : public Person{
    string coursesEnrolled;
    double GPA;
    int enrollmentYear;

public:
    Student(string n, string i, string a, string p, string e, string courses, double gpa, int year) : Person(n, i, a, p, e), coursesEnrolled(courses), GPA(gpa), enrollmentYear(year) {}

    void displayInfo() override {
        Person :: displayInfo();
        cout << "Courses Enrolled: " << coursesEnrolled << endl;
        cout << "GPA: " << GPA << endl;
        cout << "Enrollment Year: " << enrollmentYear << endl;
    }
};

class Professor : public Person{
    string department;
    string coursesTaught;
    double salary;

public:
    Professor(string n, string i, string a, string p, string e, string depart, string courses, double sal) : Person(n, i, a, p, e), department(depart), coursesTaught(courses), salary(sal) {}

    void displayInfo() override {
        Person :: displayInfo();
        cout << "Department: " << department << endl;
        cout << "Courses Taught: " << coursesTaught << endl;
        cout << "Salary: $" << salary << endl;
    }
};

class Staff : public Person{
    string department;
    string position;
    double salary;

public:
    Staff(string n, string i, string a, string p, string e, string depart, string pos, double sal) : Person(n, i, a, p, e), department(depart), position(pos), salary(sal) {}

    void displayInfo() override {
        Person :: displayInfo();
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: $" << salary << endl;
    }
};

class Course{
    string courseID;
    string courseName;
    int credits;
    string instructor;
    string schedule;

public:
    Course(string id, string name, int c, string i, string s) : courseID(id), courseName(name), credits(c), instructor(i), schedule(s) {}

    void registerStudent(Student *s){
        cout << endl << s->getName() << " registered for course: " << courseName << " (" << courseID << ")" << endl;
    }

    void calculateGrades() {
        cout << "Grades calculated for course: " << courseName << " (" << courseID << ")" << endl;
    }
};

int main(){
    Person *p[3];
    p[0] = new Student("Muhammad Ali", "24K-1004", "Nazimabad", "923343776999", "K241004@nu.edu.pk", "DLD, OOP & MVC", 3.5, 2024);
    p[1] = new Professor("Sir Arsalan Shiekh", "K-1001", "Askari V", "92355343434", "arsalan.shiekh@nu.edu.pk", "Computer Science", "DSA", 250000);
    p[2] = new Staff("Miss Saima Baig", "K-1003", "Clifton", "9203237859321","saima.baig@nu.edu.pk", "MVC", "HR", 150000);

    for(int i = 0; i < 3; i++){
        p[i]->displayInfo();
    }

    Course c("MT1008", "Multivariable Calculus", 3, "Sir Mairaj", "Thursday & Friday");
    Student s = Student("Neeraj Khemani", "24K-0548", "Pakistan Chowk", "923126676580", "k240548@nu.edu.pk", "Computer Science", 3.04, 2024);
    c.registerStudent(&s);
    c.calculateGrades();

    p[0]->updateInfo("Muhammad Ali", "24K-1004", "Tipu Sultan Road", "923343776999", "k241004@nu.edu.pk");
    p[0]->displayInfo();

    for(int i = 0; i < 3; i++){
        delete p[i];
    }
    return 0;
}