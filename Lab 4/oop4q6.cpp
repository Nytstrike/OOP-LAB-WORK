#include <iostream>
#include <string>
using namespace std;

class BankAccount{
    int accountNumber;
    string ownerName;
    double balance;

    public:
    BankAccount(){
          balance = 0.0;
    }
    BankAccount(int accNum, string name, double initialBalance = 0.0) : accountNumber(accNum), ownerName(name), balance(initialBalance) {}
    
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful.\nNew balance: Rs." << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

     void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful.\nNew balance: Rs." << balance << endl;
        } else {
            cout << "Insufficient funds or invalid amount." << endl;
        }
    }
    void displayDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Owner Name: " << ownerName << endl;
        cout << "Current Balance: Rs." << balance << endl;

    }
};

int main() {
    int accNum;
    string name;
    double initialBalance;

    cout << "Enter account number: ";
    cin >> accNum;
    cin.ignore();
    cout << "Enter owner name: ";
    getline(cin, name);
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    BankAccount userAccount(accNum, name, initialBalance);

    int choose;
    do {
        cout << "\nBank Menu:"<<endl;
        cout << "1. Deposit"<<endl;
        cout << "2. Withdraw"<<endl;
        cout << "3. Display Details"<<endl;
        cout << "4. Exit"<<endl;
        cout << "Enter your choice:"<<endl;
        cin >> choose;

        double amount;
        switch (choose) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                userAccount.deposit(amount);
                break;
            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                userAccount.withdraw(amount);
                break;
            case 3:
                userAccount.displayDetails();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choose != 4);

    return 0;
}