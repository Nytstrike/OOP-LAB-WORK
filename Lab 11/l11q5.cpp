#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;

class InsufficientFundsException : public exception {
    private :
    string message;
    public:
    InsufficientFundsException (const string& msg) : message(msg) {}
    const char *what () const noexcept override {
        return message.c_str();

    }
};


template <typename T>
class BankAccount {
private:
    T balance;

public:
    BankAccount(T initialBalance) : balance(initialBalance) {}

    void withdraw(T amount) {
        if (amount > balance) {
            T deficit = amount - balance;
            throw InsufficientFundsException("InsufficientFundsException - Deficit: $" + to_string(deficit)); }
        balance -= amount;
        cout << fixed << setprecision(2);
        cout << "Withdrew $" << amount << ". New balance: $" << balance << endl;
    }

    T getBalance() const {
        return balance;
    }

    void displayBalance() const {
        cout << fixed << setprecision(2) << "Balance: $" << balance << endl;
    }
};

int main() {
    try {
        BankAccount<double> account(500.00);
        account.displayBalance();
        cout << "Withdraw $600: ";
        account.withdraw(600.00); } 
    catch (const InsufficientFundsException& e) {
        cerr << e.what() << endl; }
    return 0;
}