#ifndef BOOKSYS_H
#define BOOKSYS_H

#include "Book.h"
#include <string>
#include <vector>


class BookSys
{
    public:
        static int currentId;
        static int getCurrentId();

        // CRUD Methods
        void addBook(std::string _bookName, std::string _bookYear);
        std::vector<Book*> getAllBooks();
        Book *getBook(int bookId);
        void updateBook(int bookId, int _bookQuantity);
        void deleteBook(int bookId);

        // Display Methods
        void printAllBooks();
        void displayBook(int bookId);;

        BookSys();
    private:
        std::vector<Book*> books;

};

#endif // BOOKSYS_H
