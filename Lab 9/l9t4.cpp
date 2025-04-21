#include <iostream>
#include <string>
using namespace std;

class PaymentMethod{
public:
    virtual bool processPayment(double amount) = 0;
};

class CreditCard : public PaymentMethod{
    string cardNumber;

public:
    CreditCard(const string &c) : cardNumber(c) {}

    bool processPayment(double amount) override {
        if(cardNumber.length() != 16 || amount <= 0){
            cout << "\t\t Invalid credit card number or amount." << endl;
            return false;
        }

        cout << "\t\t Credit Card payment of $" << amount << " with card no. " << cardNumber << " proceeded successfully!" << endl;
        return true;
    }
};

class DigitalWallet : public PaymentMethod{
    double balance;

public:
    DigitalWallet(double bal) : balance(bal) {}

    bool processPayment(double amount) override {
        if(balance < amount){
            cout << "\t\t Insufficient balance." << endl;
            return false;
        }

        balance -= amount;
        cout << "\t\t Digital Wallet payment of $" << amount << " proceeded successfully." << endl;
        cout << "\t\t New Balance: $ " << balance << endl;
        return true;
    }
};

int main(){
    CreditCard card("123456789012");
    DigitalWallet wallet(250.25);

    cout << endl << "\t\t Using Credit Card" << endl;
    cout << ((card.processPayment(150.47)) ? "Payment successful :)" : "Payment failed :(") << endl;

    cout << endl << "\t\t Using Digital Wallet" << endl;
    cout << ((wallet.processPayment(100.0)) ? "Payment successful :)" : "Payment failed :(") << endl;

    cout << endl << "\t\t Using Digital Wallet" << endl;
    cout << ((wallet.processPayment(400.0)) ? "Payment successful :)" : "Payment failed :(") << endl;

    return 0;
}