#include <iostream>
#include "BookSys.h"
#include <string>
#include <string>
#include <vector>
#include <iomanip>


int BookSys::currentId = 0;

BookSys::BookSys() {

    addBook("Fundamentals of Information Technology", "First Year",20);
    addBook("Integrated Computer Applications", "First Year",20);
    addBook("Learning Guide in C Programming", "First Year",20);

    addBook("Database Management System", "Second Year",20);
    addBook("Networking", "Second Year",20);
    addBook("Object Oriented Programming", "Second Year",20);
    addBook("Assembly Language", "Second Year",20);

    addBook("Software Engineering", "Third Year",20);
    addBook("SQL", "Third Year",20);
    addBook("Python", "Third Year",20);
    addBook("Web Development", "Third Year",20);

    addBook("Embedded Systems", "Fourth Year",20);
    addBook("Wireless Technology", "Fourth Year",20);
    addBook("Android Programming", "Fourth Year",20);
}

int BookSys::getCurrentId() {
    const int tempId = currentId;
    currentId++;
    return tempId;
}

void BookSys::addBook(std::string _bookName, std::string _bookYear, int _bookQty) {
    Book *bookToAdd = new Book(_bookName, _bookYear,_bookQty);
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
        std::cout << "\t\t -- Book with id \"" << bookId << "\" is low in stock! --" << std::endl;
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

void BookSys::addBookUI(){
    system("CLS");
    ui.TitleHeader();
    ui.setTxtColor(7);
    ui.PageTitle("Add Book");

    string bookTitle, bookYear;
    int bookQty;

    cout << "Title : ";
    getchar();
    getline(cin,bookTitle);
    cout << "Book Year : ";
    getline(cin,bookYear);
    bookQty = ih.intHandlerInput("Quantity (20 Max) : ",bookQty,20,1);

    addBook(bookTitle,bookYear,bookQty);

    cout << "\t --Book Added!--" << endl <<endl;
    system("pause");
}

void BookSys::deleteBookUI(){
    system("CLS");
    ui.TitleHeader();
    ui.setTxtColor(7);
    ui.PageTitle("Delete Book");

    printAllBooks();

    int bookID;

    bookID = ih.intHandlerInput("Enter ID : ",bookID);

    if(getBook(bookID)){
        deleteBook(bookID);
        cout << "\t --Book Deleted!--" << endl;
    }else{
        cout << "\t --Book Not Found!--" << endl;

    }

    cout<<endl;
    system("pause");
}

void BookSys::updateBookUI(){
    system("CLS");
    ui.TitleHeader();
    ui.setTxtColor(7);
    ui.PageTitle("Update Book");

    printAllBooks();

    int bookID, bookQty, opt;

    bookID = ih.intHandlerInput("\t Enter ID : ",bookID);

    if(getBook(bookID)){
        int currentBookQty = getBook(bookID)->getBookQuantity();
        opt = ih.intHandlerInput("\t [1] Add or [2] Remove: ", opt,2,1);
        switch (opt){
            case 1:
                if(currentBookQty<20){
                    bookQty = ih.intHandlerInput("\t Quantity to be added : ",bookQty,20-currentBookQty,1);
                    updateBook(bookID,currentBookQty+bookQty);
                    cout << "\t --Book Updated!--" << endl;
                }else{
                    cout << "\t --Book already Full!--" << endl;
                }
                break;
            case 2:
                if(currentBookQty>0){
                    bookQty = ih.intHandlerInput("\t Quantity to be removed : ",bookQty,currentBookQty,1);
                    updateBook(bookID,currentBookQty-bookQty);
                    cout << "\t --Book Updated!--" << endl;
                }else{
                    cout << "\t --Book already Empty!--" << endl;
                }
                break;
        }
    }else{
        cout << "\t --Book Not Found!--" << endl;
    }


    cout<<endl;
    system("pause");


}

void BookSys::bookMenu(){
    bool menu_active = true;
    while(menu_active){
        system("CLS");
        ui.TitleHeader();
        ui.setTxtColor(7);
        ui.PageTitle("Book Inventory Menu");
        cout << "[1] Display Books Inventory" << endl;
        cout << "[2] Update Stocks" << endl;
        cout << "[3] Add New Book" << endl ;
        cout << "[4] Delete Existing Book" << endl << endl;
        cout << "[0] Back" << endl;

        int opt;
        opt = ih.intHandlerInput("\n\nEnter Option: ", opt,4,0);

        switch (opt){
            case 0:
                menu_active = false;
                break;
            case 1:
                system("CLS");
                printAllBooks();
                system("pause");
                break;
            case 2:
                system("CLS");
                updateBookUI();
                break;
            case 3:
                system("CLS");
                addBookUI();
                break;
            case 4:
                system("CLS");
                deleteBookUI();
                break;
        }
    }
}
