#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream chap1("chapter1.txt");
    std::ifstream chap2("chapter2.txt");
    std::ofstream book("book.txt", std::ios::app);

    if (!chap1.is_open() || !chap2.is_open() || !book.is_open()) {
        std::cerr << "Error opening files" << std::endl;
        return 1;
    }

    std::string line;
    while (getline(chap1, line)) {
        book << line << "\n";
    }
    book << "\n";

    while (getline(chap2, line)) {
        book << line << "\n";
    }

    chap1.close();
    chap2.close();
    book.close();

    std::ifstream readBook("book.txt");
    while (getline(readBook, line)) {
        std::cout << line << "\n";
    }
    readBook.close();

    return 0;
}