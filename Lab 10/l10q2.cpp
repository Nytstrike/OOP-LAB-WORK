#include <iostream>
#include <fstream>
#include <string>
void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}
int main()
{
    std::ofstream outfile("data.txt", std::ios::app);
    if (!outfile.is_open())
    {
        std::cerr << "Error Opening file" << std::endl;
    }
    std::string name;
    std::string email;
    int yearsOfExprience;
    std::string summary;
    std::cout << " Enter  Name:" << std::endl;
    getline(std::cin, name);
    std::cout << "Enter Email:" << std::endl;
    getline(std::cin, email);
    std::cout << " Enter  Years of Expreince:" << std::endl;
    std::cin >> yearsOfExprience;
    clearInputBuffer();
    std::cout << " Enter Summary" << std::endl;
    getline(std::cin, summary);
    outfile << name << "\n-" << email << "\n-" << yearsOfExprience << "\n-" << summary << std::endl;
    std::ifstream file("data.txt");
    // displaying
    if (!file.is_open())
    {
        std::cerr << "Error opening file" << std::endl;
    }

    std::cout << "\n=== Saved Data ===\n\n";
    std::string line;
    while (getline(file, line))
    {
        std::cout <<"\n "<< line << "\n\n";
    }

    file.close();

    return 0;
}