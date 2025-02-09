// Create a class called calendar. The calendar should have 12 arrays for each month of the year, and a variable that
// stores information about the current year. The user is allowed to store their tasks to do against each day. Assume
// only one entry is needed per day.
// Create the following methods for your class:
// >Add a task. Thisfunction accepts three parameters: task details, date and month. It should add
// >a task on the day specified.
// >Remove a task. Accepts the date and month as a parameter to remove the task from.
// >Show tasks. This method should go through all of your months and print all the tasks allocated.
// Your task is to create one calendar object, then hardcode 5-6 tasks for your calendar. Then demonstrate how
// you’ll remove a task, and display the updated task list.
#include <iostream>
#include <string>
using namespace std;
class Calendar {
private:
    string months[12][31]; 
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
    int year;
public:
    Calendar(int y) {
        year = y;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < daysInMonth[i]; j++) {
                months[i][j] = "";
            }
        }
    }

    void addTask(int day, int month, const string &task) {
        if (month < 1 || month > 12 || day < 1 || day > daysInMonth[month - 1]) {
            cout << "Invalid date!\n";
            return;
        }
        months[month - 1][day - 1] = task;
    }
    void removeTask(int day, int month) {
        if (month < 1 || month > 12 || day < 1 || day > daysInMonth[month - 1]) {
            cout << "Invalid date!\n";
            return;
        }
        months[month - 1][day - 1] = "";
    }
    void showTasks() {
        cout << "Tasks for the year " << year << ":\n";
        for (int i = 0; i < 12; i++) {
            bool hasTasks = false;
            for (int j = 0; j < daysInMonth[i]; j++) {
                if (!months[i][j].empty()) {
                    cout << "Month " << (i + 1) << ", Day " << (j + 1) << ": " << months[i][j] << endl;
                    hasTasks = true;
                }
            }
            if (!hasTasks) {
                cout << "Month " << (i + 1) << ": No tasks\n";
            }
        }
    }
};

int main() {
    Calendar myCalendar(2025);
    myCalendar.addTask(5, 1, "New Year Celebration");
    myCalendar.addTask(14, 2, "Valentine's Day");
    myCalendar.addTask(23, 3, "Friend's Birthday");
    myCalendar.addTask(10, 4, "Project Deadline");
    myCalendar.addTask(25, 12, "Christmas Celebration");
    myCalendar.addTask(31, 12, "New Year's Eve Party");
    cout << "\nTasks before removal:\n";
    myCalendar.showTasks();
    myCalendar.removeTask(10, 4);
    cout << "\nTasks after removal:\n";
    myCalendar.showTasks();
    return 0;
}
