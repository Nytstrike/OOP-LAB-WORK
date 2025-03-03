// Create a class called LoanHelper, which helps the user calculate their loan payments. The class
// should have a variable that stores interest rate for the loan as a user defined constant value. Aside
// from the that, it also stores the amount for the loan taken and amount of months that the user will
// repay the loan in. The loan repayment should be calculated on a monthly basis, and the interest rate
// should be applied over the monthly return amount. The output should be something like:
// “You have to pay 999 every month for 12 monthsto repay your loan”
// Note: first divide loan amount by number of months, then apply the interest rate on it. Interest rate
// should be a value between 0-0.5%
#include<iostream>
using namespace std;
class LoanHelper{
    float laonAmount;
    float noMonths;
    public:
    const double interestRate;
    LoanHelper() : interestRate(0),laonAmount(0), noMonths(0){}
    LoanHelper(double rate,float loan, float months) : interestRate(rate), laonAmount(loan),noMonths(months) {}
    double monthlyCAl(){
        double monthlyPayment =laonAmount/noMonths;
        double monthlyInterest =monthlyPayment* (interestRate/100);
        return (monthlyInterest+monthlyPayment);
    }
    void messageDisplay(){
        cout<<"You have to pay\t"<< monthlyCAl()<< "\tfor"<< noMonths << "\tmonths" <<endl;
    }
};
int main (){
    LoanHelper m1(0.5,500,12);
    m1.monthlyCAl();
    m1.messageDisplay();

}