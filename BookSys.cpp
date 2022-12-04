#include <iostream>
#include "BookSys.h"
#include <string>
#include <vector>
#include <iomanip>


int BookSys::currentId = 0;

BookSys::BookSys() {

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

    //variable declarations
    std::string h0 = "ID", h1= "Title", h2 = "Book Year", h3 = "Quantity", h4 = "Max Quantity";
    int hc0 = h0.length(), hc1 = h1.length(), hc2 = h2.length(), hc3 = h3.length(), hc4 = h4.length();

    ui.setTxtColor(7);
    ui.PageTitle("Book List");
    cout << std::string(15 - 1, '-') << "+" << std::string(50 - 1, '-') << "+" << std::string(40 -1, '-') << "+" << std::string(20 - 1, '-') << "+" << std::string(30, '-') << endl;
    cout << " " + h0 << setw(15 - hc0 - 1) << "|" << setw((50/2) + (hc1/2)) << h1 << setw((50/2) - (hc1/2)) << "|"
         << setw((40/2) + (hc2/2)) << h2 << setw((40/2) - (hc2/2)) << "|"
         << setw((20/2) + (hc3/2)) << h3 << setw((20/2) - (hc3/2)) << "|"
         << setw((30/2) + (hc4/2)) << h4 << setw((30/2) - (hc4/2)) << endl;
    cout << std::string(15 - 1, '-') << "+" << std::string(50 - 1, '-') << "+" << std::string(40 -1, '-') << "+" << std::string(20 - 1, '-') << "+" << std::string(30, '-') << endl;


    for (int i = 0; i < getAllBooks().size(); i++)
    {
        Book *currentBook = getAllBooks().at(i);


        int TitleStrSize = currentBook->getBookName().length(),
            BookYrStrSize = currentBook->getBookYear().length();

        long long BookIdIntSize = currentBook->getBookId(),
                  BookQtyIntSize = currentBook->getBookQuantity();


        cout << " " << currentBook->getBookId() << setw(15 - ui.countDigit(BookIdIntSize) - 1) << "|"
             << " " << currentBook->getBookName() << setw(50 - TitleStrSize - 1) << "|"
             << " " << currentBook->getBookYear() << setw(40 - BookYrStrSize - 1) << "|"
             << " " << currentBook->getBookQuantity() << setw(20 - ui.countDigit(BookQtyIntSize) - 1) << "|"
             << " " << currentBook->getMaxQuantity() << endl;
    }
    cout << std::string(15 - 1, '-') << "+" << std::string(50 - 1, '-') << "+" << std::string(40 -1, '-') << "+" << std::string(20 - 1, '-') << "+" << std::string(30, '-') << endl;

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
