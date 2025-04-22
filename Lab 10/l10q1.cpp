#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student
{
    int id;
    string name;
    float gpa;
};

void clearInputBuffer()
{
    cin.clear();
    cin.ignore(10000, '\n');
}

int main()
{
    // Writing data to file
    ofstream outFile("student.txt", ios::out | ios::app);
    if (!outFile.is_open())
    {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    const int MAX_STUDENTS = 5;
    Student stud[MAX_STUDENTS + 1];

    // Input for first 5 students
    for (int i = 0; i < MAX_STUDENTS; i++)
    {
        cout << "\nEnter details for student " << i + 1 << ":" << endl;

        cout << "ID: ";
        cin >> stud[i].id;
        clearInputBuffer();

        cout << "Name: ";
        getline(cin, stud[i].name);

        cout << "GPA: ";
        cin >> stud[i].gpa;
        clearInputBuffer();

        outFile << stud[i].id << " " << stud[i].name << " " << stud[i].gpa << endl;
    }

    // Option to add another student
    char choice;
    cout << "\nDo you want to add another student? (y/n): ";
    cin >> choice;
    clearInputBuffer();

    if (choice == 'y' || choice == 'Y')
    {
        cout << "\nEnter details for additional student:" << endl;

        cout << "ID: ";
        cin >> stud[MAX_STUDENTS].id;
        clearInputBuffer();

        cout << "Name: ";
        getline(cin, stud[MAX_STUDENTS].name);

        cout << "GPA: ";
        cin >> stud[MAX_STUDENTS].gpa;
        clearInputBuffer();

        outFile << stud[MAX_STUDENTS].id << " " << stud[MAX_STUDENTS].name
                << " " << stud[MAX_STUDENTS].gpa << endl;

        cout << "Additional student data saved!" << endl;
    }
    outFile.close();

    cout << "\nDisplaying student data:" << endl;
    ifstream inFile("student.txt");
    if (!inFile.is_open())
    {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    Student tempStudent;
    while (inFile >> tempStudent.id)
    {
        inFile.ignore();                   
        getline(inFile, tempStudent.name, ' '); 
        inFile >> tempStudent.gpa;
        inFile.ignore(); 

        cout << "ID: " << tempStudent.id
             << "\tName: " << tempStudent.name
             << "\tGPA: " << tempStudent.gpa << endl;
    }
    inFile.close();
    cout << "\nAll student data has been processed." << endl;
    return 0;
}