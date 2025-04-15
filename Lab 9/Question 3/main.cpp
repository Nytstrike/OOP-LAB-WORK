#include <iostream>
#include "book.h"

int main()
{
    Library lib;

    Book book1("Crime and Punishment", "Fyodor Dostoevsky", "978074457673565");
    Book book2("Rich Dad Poor Dad", "Robert Kiyosaki", "9780451566935");
    Book book3("Letters to his father", "Franz Kafka", "9780061120084");

    lib.addBook(&book1);
    lib.addBook(&book2);
    lib.addBook(&book3);

    lib.displayAllBooks();

    std::cout << "\nSearching for '1984':" << std::endl;
    lib.searchBook("1984");

    std::cout << "\nRemoving '1984' from the library:" << std::endl;
    lib.removeBook("1984");

    lib.displayAllBooks();

    return 0;
}
