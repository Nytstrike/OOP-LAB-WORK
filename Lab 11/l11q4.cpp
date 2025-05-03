#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class NegativeNumberException : public exception {
public:
    const char* what() const noexcept override {
        return "NegativeNumberException";
    }
};

class InvalidTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "InvalidTypeException";
    }
};

template <typename T>
double sqrt_custom(T num) {
    if constexpr (is_arithmetic<T>::value) {
        if (num < 0) {
            throw NegativeNumberException();
        }
        return sqrt(static_cast<double>(num));
    } else {
        throw InvalidTypeException();
    }
}

int main() {
    try {
        cout << "sqrt(-4): " << sqrt_custom(-4) << endl;
    }
    catch (const exception& e) {
        cout << "sqrt(-4): " << e.what() << endl;
    }

    try {
        cout << "sqrt(hello): " << sqrt_custom(string("hello")) << endl;
    }
    catch (const exception& e) {
        cout << "sqrt(hello): " << e.what() << endl;
    }
    return 0;
}
