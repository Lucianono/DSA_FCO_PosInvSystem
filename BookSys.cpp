#include <iostream>
#include "BookSys.h"
#include <string>
#include <vector>

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
    for (int i = 0; i < books.size(); i++) {
        Book *currentBook = books.at(i);
        if (currentBook->bookId == bookId) {
          bookToReturn = currentBook;
          break;
        }
    }
    return bookToReturn;
}

std::vector<Book*> BookSys::getAllBooks() {
    return books;
}

void BookSys::updateBook(int bookId, int _bookQuantity) {
    Book *bookToUpdate;
    int bookToUpdateIndex;
    for (int i = 0; i < books.size(); i++) {
        Book *currentBook = books.at(i);
        if (currentBook->bookId == bookId) {
          bookToUpdate = currentBook;
          bookToUpdateIndex = i;
          break;
        }
    }
    bookToUpdate->bookQuantity = _bookQuantity;
    books.at(bookToUpdateIndex) = bookToUpdate;

    if (_bookQuantity < 5) {
        std::cout << "NOTIF: Book with id \"" << bookId << "\" quantity is less than 5." << std::endl;
    }
}

void BookSys::deleteBook(int bookId) {
    int bookToDeleteIndex;
    for (int i = 0; i < books.size(); i++) {
        Book *currentBook = books.at(i);
        if (currentBook->bookId == bookId) {
          bookToDeleteIndex = i;
          break;
        }
    }
    books.erase(books.begin() + bookToDeleteIndex);
}
