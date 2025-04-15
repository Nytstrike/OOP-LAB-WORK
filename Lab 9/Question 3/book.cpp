#include "book.h"
#include <iostream>

Book::Book(std::string t, std::string a, std::string i) : title(t), author(a), isbn(i) {}

std::string Book::getTitle() const
{
    return title;
}

std::string Book::getAuthor() const
{
    return author;
}

std::string Book::getIsbn() const
{
    return isbn;
}

void Book::displayDetails() const
{
    std::cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn << std::endl;
}

Library::Library() : bookCount(0) {}

void Library::addBook(Book *book)
{
    if (bookCount < 10)
    {
        books[bookCount++] = book;
    }
}

void Library::removeBook(const std::string &title)
{
    for (int i = 0; i < bookCount; ++i)
    {
        if (books[i]->getTitle() == title)
        {
            for (int j = i; j < bookCount - 1; ++j)
            {
                books[j] = books[j + 1];
            }
            --bookCount;
            std::cout << "Book \"" << title << "\" removed from library." << std::endl;
            return;
        }
    }
    std::cout << "Book \"" << title << "\" not found in library." << std::endl;
}

void Library::searchBook(const std::string &title) const
{
    for (int i = 0; i < bookCount; ++i)
    {
        if (books[i]->getTitle() == title)
        {
            books[i]->displayDetails();
            return;
        }
    }
    std::cout << "Book \"" << title << "\" not found in library." << std::endl;
}

void Library::displayAllBooks() const
{
    if (bookCount == 0)
    {
        std::cout << "No books available in the library." << std::endl;
        return;
    }
    std::cout << "Books in Library: " << std::endl;
    for (int i = 0; i < bookCount; ++i)
    {
        books[i]->displayDetails();
    }
}
