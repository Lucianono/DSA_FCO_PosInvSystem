#ifndef BOOKSYS_H
#define BOOKSYS_H
#include "UIDesign.h"
#include "IntHandler.h"
#include "Book.h"
#include <string>
#include <vector>


class BookSys
{
    public:
        static int currentId;
        static int getCurrentId();

        // CRUD Methods
        void addBook(std::string _bookName, std::string _bookYear,int _bookQty);
        std::vector<Book*> getAllBooks();
        Book *getBook(int bookId);
        void updateBook(int bookId, int _bookQuantity);
        void deleteBook(int bookId);

        // Display Methods
        void printAllBooks();
        void printStockStatus();
        void displayBook(int bookId);
        void addBookUI();
        void deleteBookUI();
        void updateBookUI();

        void bookMenu();
        BookSys();
    private:
        IntHandler ih;
        UIDesign ui;
        std::vector<Book*> books;

};

#endif // BOOKSYS_H
