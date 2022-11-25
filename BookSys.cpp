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
    Book *bookToAdd = new Book(_bookName, _bookYear);
    books.push_back(bookToAdd);
}

Book *BookSys::getBook(int bookId) {
    Book *bookToReturn;
    for (int i = 0; i < books.size(), i++) {
        const Book *currentBook = books.at(i);
        if (currentBook.bookId == bookId) {
          bookToReturn = currentBook;
          break;
        }
    }
    return bookToReturn;
}

void BookSys::updateBook(int bookId, int _bookQuantity) {
    Book *bookToUpdate;
    for (int i = 0; i < books.size(), i++) {
        const Book *currentBook = books.at(i);
        if (currentBook.bookId == bookId) {
          bookToUpdate = currentBook;
          break;
        }
    }
    bookToUpdate.bookQuantity = _bookQuantity;
    books.at(bookId) = bookToUpdate;
}

void BookSys::deleteBook(int bookId) {
    // TODO: Remove the book from the books vector. See BookSys.book.
}
