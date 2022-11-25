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

        void addBook(std::string _bookName, int _bookYear);
        Book *getBook(int bookId);
        std::vector<Book*> getAllBooks();
        void updateBook(int bookId, int _bookQuantity);
        void deleteBook(int bookId);

        BookSys();
    private:
        std::vector<Book*> books;

};

#endif // BOOKSYS_H
