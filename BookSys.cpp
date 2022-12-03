#include <iostream>
#include "BookSys.h"
#include <string>
#include <vector>
#include <iomanip>


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

    //variable declarations
    std::string h0 = "ID", h1= "Title", h2 = "Book Year", h3 = "Quantity", h4 = "Publishing Company";
    int hc0 = h0.length(), hc1 = h1.length(), hc2 = h2.length(), hc3 = h3.length(), hc4 = h4.length();

    system("CLS");
    ui.TitleHeader();
    ui.setTxtColor(8);
    ui.PageTitle("Book List");
    cout << std::string(15 - 1, '-') << "+" << std::string(50 - 1, '-') << "+" << std::string(40 -1, '-') << "+" << std::string(20 - 1, '-') << "+" << std::string(30, '-') << endl;
    cout << " " + h0 << setw(15 - hc0 - 1) << "|" << setw((50/2) + (hc1/2)) << h1 << setw((50/2) - (hc1/2)) << "|"
         << setw((40/2) + (hc2/2)) << h2 << setw((40/2) - (hc2/2)) << "|"
         << setw((20/2) + (hc3/2)) << h3 << setw((20/2) - (hc3/2)) << "|"
         << setw((30/2) + (hc4/2)) << h4 << setw((30/2) - (hc4/2)) << endl;
    cout << std::string(15 - 1, '-') << "+" << std::string(50 - 1, '-') << "+" << std::string(40 -1, '-') << "+" << std::string(20 - 1, '-') << "+" << std::string(30, '-') << endl;

    //variable declarations
    std::string bTitle[] = {"Harry Potter", "Lord of the Rings", "The Hobbit", "Hunger Games"};
    std::string bAuthor[] = {"J.K. Rowling", "J.R.R. Tolkien", "J.R.R. Tolkien", "Suzanne Collins"};
    std::string bPubDate[] = {"Jan 1, 2020", "Nov 20,2022", "Nov 14, 2022", "March 15, 2015"};
    std::string bPublisher[] = {"Bloomsbury", "Allen & Unwin", "Allen & Unwin", "Scholastic"};
    int bTitleSize = sizeof(bTitle)/sizeof(bTitle[0]);

    //sort(bTitle, bTitle + bTitleSize, sortAsc);

    for (int x=0; x<bTitleSize; x++)
    {
        int TitleStrSize = bTitle[x].length(),
            AuthorStrSize = bAuthor[x].length(),
            PubDateStrSize = bPubDate[x].length(),
            PublisherStrSize = bPublisher[x].length();
        long long n = x;

        cout << " " << x << setw(15 - ui.countDigit(n) - 1) << "|"
             << " " << bTitle[x] << setw(50 - TitleStrSize - 1) << "|"
             << " " << bAuthor[x] << setw(40 - AuthorStrSize - 1) << "|"
             << " " << bPubDate[x] << setw(20 - PubDateStrSize - 1) << "|"
             << " " << bPublisher[x] << endl;
    }
    cout << std::string(15 - 1, '-') << "+" << std::string(50 - 1, '-') << "+" << std::string(40 -1, '-') << "+" << std::string(20 - 1, '-') << "+" << std::string(30, '-') << endl;
    system("pause");

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
