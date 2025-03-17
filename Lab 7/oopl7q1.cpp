#include <iostream>
#include <string>

class Account {
protected:
    std::string accountNumber;
    double balance;
    std::string accountHolderName;
    std::string accountType;
    double *transactionHistory;
    int numTrans;
    int transactionCapacity;

public:
    Account() : accountNumber(""), balance(0), accountHolderName(""), accountType(""), numTrans(0), transactionCapacity(1) {
        transactionHistory = new double[transactionCapacity];
    }

    Account(std::string accountNumber, double balance, std::string accountHolderName, std::string accountType)
        : accountNumber(accountNumber), balance(balance), accountHolderName(accountHolderName), accountType(accountType), numTrans(0), transactionCapacity(1) {
        transactionHistory = new double[transactionCapacity];
    }

    virtual ~Account() {
        delete[] transactionHistory;
    }

    void updateHistory(double amount) {
        if (numTrans == transactionCapacity) {
            transactionCapacity *= 2;
            double *newTransactionHistory = new double[transactionCapacity];
            for (int i = 0; i < numTrans; i++) {
                newTransactionHistory[i] = transactionHistory[i];
            }
            delete[] transactionHistory;
            transactionHistory = newTransactionHistory;
        }
        transactionHistory[numTrans] = amount;
        numTrans++;
    }

    void deposit(double amount) {
        balance += amount;
        updateHistory(amount);
    }

    virtual double withdraw(double amount) {
        if (amount > balance) {
            std::cout << "INSUFFICIENT BALANCE" << std::endl;
            return 0;
        } else {
            balance -= amount;
            updateHistory(-amount);
            return amount;
        }
    }

    virtual double calculateInterest(int rate) {
        std::cout << "No interest calculation for this account type." << std::endl;
        return 0;
    }

    void printStatement() {
        std::cout << "-----Printing Transaction History-----" << std::endl;
        for (int i = 0; i < numTrans; i++) {
            std::cout << "Amount: " << transactionHistory[i] << std::endl;
        }
    }

    void getAccountInfo() {
        std::cout << "Account Title: " << accountHolderName << std::endl;
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Account Type: " << accountType << std::endl;
        std::cout << "Account Balance: " << balance << std::endl;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(std::string num, double amount, std::string name, std::string type)
        : Account(num, amount, name, type) {}

    double withdraw(double amount) override {
        return Account::withdraw(amount);
    }
};

class SavingAccount : public Account {
public:
    SavingAccount(std::string num, double amount, std::string name, std::string type)
        : Account(num, amount, name, type) {}

    double calculateInterest(int rate) override {
        if (rate < 1 || rate > 5) {
            std::cout << "INVALID VALUE for Savings Interest Rate" << std::endl;
            return 0;
        }
        return (rate / 100.0) * balance;
    }
};

class FixedAccount : public Account {
public:
    FixedAccount(std::string num, double amount, std::string name, std::string type)
        : Account(num, amount, name, type) {}

    double withdraw(double amount) override {
        std::cout << "Invalid Operation, cannot withdraw from Fixed Account" << std::endl;
        return 0;
    }

    double calculateInterest(int rate) override {
        if (rate < 5 || rate > 15) {
            std::cout << "INVALID VALUE for Fixed Deposit Interest Rate" << std::endl;
            return 0;
        }
        return (rate / 100.0) * balance;
    }
};

int main() {
    CheckingAccount checking("ABL098", 1500.0, "Mustafa Sohail", "Checking");
    SavingAccount savings("UBL123", 2600.0, "Netaesh Kumar", "Savings");
    FixedAccount fixed("SCB567", 5070.0, "Manzoor Chandio", "Fixed Deposit");

    checking.deposit(200.0);
    checking.withdraw(500.0);
    checking.printStatement();
    checking.getAccountInfo();
    
    savings.deposit(300.0);
    savings.withdraw(500.0);
    savings.printStatement();
    savings.getAccountInfo();
    std::cout << "Interest (Savings, 4%): " << savings.calculateInterest(4) << std::endl;

    fixed.deposit(1000.0);
    fixed.withdraw(500.0);
    fixed.printStatement();
    fixed.getAccountInfo();
    std::cout << "Interest (Fixed, 7%): " << fixed.calculateInterest(7) << std::endl;

    return 0;
}
