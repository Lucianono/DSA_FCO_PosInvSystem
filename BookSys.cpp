#include <iostream>
#include "BookSys.h"
#include <string>

//this file is for the CICT Books System

//create a database for the given CICT books using 2D array
//should have 4 attributes: BookID, BookName, BookYear, Quantity
//let Quantity of each book be 20
//BookID will be decided by you, pick which is best
//the books is in Teams

//create a CRUD system for the Books
//should access the book by the given Book ID
//can modify the Quantity
//should NOT modify the BookID,Name,and Year
//notify if TotalBookQuantity is <= 5%

//assigned to : Joel-Vincent Bernardo, Jocelyn Rebato, Liah Baculi

int BookSys::currentId = 0;

BookSys::BookSys() {
    std::cout << "BookSys Class created" << std::endl;
}

int BookSys::getCurrentId() {
    const int tempId = currentId;
    currentId++;
    return tempId;
}

void BookSys::addBook(std::string _bookName, int _bookYear) {
    // TODO: Create a book object. See Book.h & Book.cpp.
    // TODO: Add the book object to the books vector. See BookSys.books.
    // Note: You do not need to pass a bookId. The bookId is automatically
    // set by the Book constructor. See implementation @ Book.cpp line 6 & 13
}

Book BookSys::getBook(int bookId) {
    // TODO: Get the book object from the books vector. See BookSys.books.
    // then change the return value @ line 44.
    // Note: The return value below is a placeholder to prevent compilation errors.
    return new Book("Test", 2022);
}

void BookSys::updateBook(int bookId, int _bookQuantity) {
    // TODO: Get the book from the books vector. See BookSys.books.
    // then update the quantity value of the book.
}

void BookSys::deleteBook(int bookId) {
    // TODO: Remove the book from the books vector. See BookSys.book.
}
