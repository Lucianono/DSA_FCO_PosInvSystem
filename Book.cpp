#include "Book.h"
#include "BookSys.h"
#include <string>

Book::Book(std::string _bookName, std::string _bookYear) {
    bookId = BookSys::getCurrentId();
    bookName = _bookName;
    bookYear = _bookYear;
    bookQuantity = 20;
    MAX_QUANTITY = 20;
}

Book::Book(std::string _bookName, std::string _bookYear, int _bookQuantity) {
    bookId = BookSys::getCurrentId();
    bookName = _bookName;
    bookYear = _bookYear;
    bookQuantity = _bookQuantity;
    MAX_QUANTITY = 20;
}

Book::Book(int _bookId, std::string _bookName, std::string _bookYear, int _bookQuantity) {
    bookId = _bookId;
    bookName = _bookName;
    bookYear = _bookYear;
    bookQuantity = _bookQuantity;
    MAX_QUANTITY = 20;
}
