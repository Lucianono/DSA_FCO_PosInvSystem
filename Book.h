#pragma once
#include <string>

class Book {
    public:
        Book(std::string _bookName, std::string _bookYear);
        Book(std::string _bookName, std::string _bookYear, int _bookQuantity);
        Book(int _bookId, std::string _bookName, std::string _bookYear, int _bookQuantity);
        int getBookId();
        int getBookQuantity();
        int getMaxQuantity();
        std::string getBookName();
        std::string getBookYear();
        void setBookQuantity(int _bookQuantity);

    private:
        int bookId;
        int bookQuantity;
        int MAX_QUANTITY;
        std::string bookName;
        std::string bookYear;
};
