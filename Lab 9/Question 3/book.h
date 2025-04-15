#pragma once
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    Book(std::string t, std::string a, std::string i);
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getIsbn() const;
    void displayDetails() const;
};

class Library {
private:
    Book* books[10];
    int bookCount;

public:
    Library();
    void addBook(Book* book);
    void removeBook(const std::string& title);
    void searchBook(const std::string& title) const;
    void displayAllBooks() const;
};
