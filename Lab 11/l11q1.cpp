#include <iostream>
using namespace std;
class InvalidValueException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "ArthematicException";
    }
};
bool validateAge(int a)
{
    try
    {
        if (a <0 || a>120)
        {
            throw InvalidValueException();
        }
    }
    catch (InvalidValueException e)
    {
        cout<<e.what();
        return false;
    }
    return true;
}
int main () {
    if (!validateAge(1234)) {
        std::cout<<"\nWhat is this!"<<std::endl;
    }
    else {
        std::cout<<"Thats reasonable!"<<std::endl;
    }
}
