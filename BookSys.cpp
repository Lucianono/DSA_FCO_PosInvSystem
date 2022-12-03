#include <iostream>
#include "BookSys.h"
#include <string>
#include <vector>

//this file is for the CICT Books System
//assigned to : Joel-Vincent Bernardo, Jocelyn Rebato, Liah Baculi

int BookSys::currentId = 0;

BookSys::BookSys() {
    std::cout << "BookSys Class created" << std::endl;

    addBook("Fundamentals of Information Technology", "First Year");
    addBook("Integrated Computer Applications", "First Year");
    addBook("Learning Guide in C Programming", "First Year");

    addBook("Database Management System", "Second Year");
    addBook("Networking", "Second Year");
    addBook("Object Oriented Programming", "Second Year");
    addBook("Assembly Language", "Second Year");

    addBook("Software Engineering", "Third Year");
    addBook("SQL", "Third Year");
    addBook("Python", "Third Year");
    addBook("Web Development", "Third Year");

    addBook("Embedded Systems", "Fourth Year");
    addBook("Wireless Technology", "Fourth Year");
    addBook("Android Programming", "Fourth Year");
}

int BookSys::getCurrentId() {
    const int tempId = currentId;
    currentId++;
    return tempId;
}

void BookSys::addBook(std::string _bookName, std::string _bookYear) {
    Book *bookToAdd = new Book(_bookName, _bookYear);
    books.push_back(bookToAdd);
}

Book *BookSys::getBook(int bookId) {
    Book *bookToReturn = NULL;
    for (int i = 0; i < books.size(); i++) {
        Book *currentBook = books.at(i);
        if (currentBook->getBookId() == bookId) {
          bookToReturn = currentBook;
          return bookToReturn;
          break;
        }
    }
    std::cout<<"not found\n";
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
        if (currentBook->getBookId() == bookId) {
          bookToUpdate = currentBook;
          bookToUpdateIndex = i;
          break;
        }
    }
    bookToUpdate->setBookQuantity(_bookQuantity);
    books.at(bookToUpdateIndex) = bookToUpdate;

    if (_bookQuantity < bookToUpdate->getMaxQuantity() * 0.05) {
        std::cout << "NOTIF: Book with id \"" << bookId << "\" quantity is less than 5%." << std::endl;
    }
}

void BookSys::deleteBook(int bookId) {
    int bookToDeleteIndex;
    for (int i = 0; i < books.size(); i++) {
        Book *currentBook = books.at(i);
        if (currentBook->getBookId() == bookId) {
          bookToDeleteIndex = i;
          break;
        }
    }
    books.erase(books.begin() + bookToDeleteIndex);
}

void BookSys::printAllBooks() {
    for (int i = 0; i < getAllBooks().size(); i++) {
        Book *currentBook = getAllBooks().at(i);
        std::cout << currentBook->getBookId() << " | " << currentBook->getBookName()<<std::endl;
    }
}

void BookSys::printStockStatus(){
    for (int i = 0; i < getAllBooks().size(); i++) {
        Book *currentBook = getAllBooks().at(i);
        std::cout << currentBook->getBookId() << " | " << currentBook->getBookName() << " | " << currentBook->getBookQuantity()<<" | "<<currentBook->getMaxQuantity()<<std::endl;
    }
}

void BookSys::displayBook(int bookId) {
    Book *bookToDisplay;
    for (int i = 0; i < getAllBooks().size(); i++) {
        Book *currentBook = getAllBooks().at(i);
        if (currentBook->getBookId() == bookId) {
            bookToDisplay = currentBook;
            break;
        }
    }
    std::cout << bookToDisplay->getBookName();
}
