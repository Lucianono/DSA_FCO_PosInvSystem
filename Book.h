#pragma once
#include <string>

class Book {
    public:
        Book(std::string _bookName, int _bookYear);
        Book(std::string _bookName, int _bookYear, int _bookQuantity);
        Book(int _bookId, std::string _bookName, int _bookYear, int _bookQuantity);
    private:
        int bookId;
        std::string bookName;
        int bookYear;
        int bookQuantity;
};
