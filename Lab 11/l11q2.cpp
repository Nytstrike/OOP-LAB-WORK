#include<iostream>
using namespace std;

#define Max_Value 100

class StackOverflowException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Stack is full";
    }
};

class StackUnderflowException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Stack is empty";
    }
};

template <typename T>
class Stack {
private:
    T elements[Max_Value];
    int currentIndex; 

public:
    Stack() : currentIndex(0) {} 
    bool isFull() {
        return currentIndex == Max_Value;
    }

    bool isEmpty() {
        return currentIndex == 0;
    }

    void push(T a) {
        if (isFull()) {
            throw StackOverflowException();
        }
        elements[currentIndex++] = a;
    }

    T pull() {
        if (isEmpty()) {
            throw StackUnderflowException();
        }
        return elements[--currentIndex];
    }
};

int main() {
    Stack<int> A;

    try {
        A.pull();
    }
    catch (StackUnderflowException& e) {
        cout << e.what() << endl;
    }

    try {
        A.push(123);
        cout << "Pushed: 123" << endl;
    }
    catch (StackOverflowException& e) {
        cout << e.what() << endl;
    }

    return 0;
}
