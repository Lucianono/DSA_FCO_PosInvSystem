#include <iostream>
#include <windows.h>
#include <iomanip>
#include <unistd.h>

#include "UIDesign.h"
#include "BookSys.h"
#include "SecuritySys.h"
#include "OrderSys.h"

using namespace std;

//this file is responsible for the designs or UI
//create functions or methods to easily design an output
//design a receipt
//design a security UI
//design an order database UI
//design an book database UI
//design an about us UI
//design a transaction UI
//be creative!
//assigned to: Michaela De Guzman

//let you change the text color of line
void UIDesign::setTxtColor(int ColorValue)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, ColorValue);
}
//main header of app
void UIDesign::TitleHeader()
{
    string Title = "Book Store";
    system("CLS");
    setTxtColor(48);
    cout << std::string(155,'=') << endl;
    cout << setw((155/2) + (Title.length()/2)) << Title << setw((155/2) - (Title.length()/2)+1)<<" " << endl;
    cout << std::string(155,'=') << endl << endl;
}
//title of the page
void UIDesign::PageTitle(string title)
{
    string PageTitle = "|    " + title + "    |";
    int PageTitleSize = PageTitle.length();
    cout << setw(((155/2) + PageTitleSize/2) - 1) << std::string(PageTitleSize - 2, '*') << endl;
    cout << setw((155/2) + (PageTitleSize/2)) << PageTitle <<  endl;
    cout << setw(((155/2) + PageTitleSize/2) - 1) << std::string(PageTitleSize - 2, '*') << endl << endl;
}
//sort alphabetically in ascending order
bool UIDesign::sortAsc(string a, string b)
{
    return a<b;
}
//sort alphabetically in descending order
bool UIDesign::sortDesc(string a, string b)
{
    return a>b;
}
//count the length of the ID of a book
//example: 20 will be counted as 2 digits
int UIDesign::countDigit (long long n)
{
    if (n == 0)
        return 1;
    int count = 0;
    while (n != 0) {
        n = n / 10;
        ++count;
    }
    return count;
}



//constructor
UIDesign::UIDesign()
{

}


void UIDesign::MainMenu()
{
    //variable declarations
    MenuStart:
    string opt;


    system("CLS");
    TitleHeader();
    setTxtColor(11);
    PageTitle("Main Menu");
    string Menu[] = {"Add Books", "Search Books", "View Books", "Delete Book", "Exit"};
    cout << "1. Add Books" << endl;
    cout << "2. Search Books" << endl;
    cout << "3. View Books" << endl;
    cout << "4. Delete Books" << endl;
    cout << "5. Print Receipt" << endl << endl;
    cout << "0. Exit";

    cout << "\n\nEnter Option: ";
    cin >> opt;

    if(opt == "1")
    {
        //BookFunc.AddBook();
    }
    else if(opt == "2")
    {
        //BookFunc.SearchBook();
    }
    else if(opt == "3")
    {
       // BookFunc.ViewBooks();
    }
    else if(opt == "4")
    {
        //BookFunc.DeleteBook();
    }
    else if(opt == "0")
    {
        for (int j = 0; j < 3; j++) {
               cout << "\rLogging out, please wait   \rLogging out, please wait";
               for (int i = 0; i < 3; i++) {
                  cout << ".";
                  sleep(1);
               }
            }
       // SecSysFunc.Login();
    }
    else
    {
        cout << "Invalid option!" << endl;
        sleep(1);
        goto MenuStart;
    }
}

void UIDesign::AddBook()
{
    TitleHeader();
    setTxtColor(8);
    PageTitle("Add Book");

    //variable declarations
    char bookTitle[255], bookAuthor[255], bookPubDate[255], bookPublisher[255];

    system("CLS");

    cout << "Title: ";
    getchar();
    cin.getline(bookTitle,sizeof(bookTitle));
    cout << "Author: ";
    cin.getline(bookAuthor,sizeof(bookAuthor));
    cout << "Publication Date: ";
    cin.getline(bookPubDate,sizeof(bookPubDate));
    cout << "Publisher: ";
    cin.getline(bookPublisher,sizeof(bookPublisher));

    //replace this code with function to add the book to database
    cout << "\n\nTitle: " << bookTitle
         << "\nAuthor: " << bookAuthor
         << "\nDate: " << bookPubDate
         << "\nPublisher: " << bookPublisher << endl << endl;
    system("pause");
    MainMenu();
}


void UIDesign::DeleteBook()
{
    //variable declarations
    string h0 = "ID", h1= "Title", h2 = "Author", h3 = "Date Published", h4 = "Publishing Company";
    int hc0 = h0.length(), hc1 = h1.length(), hc2 = h2.length(), hc3 = h3.length(), hc4 = h4.length();

    system("CLS");
    TitleHeader();
    setTxtColor(8);
    PageTitle("Delete Book");
    cout << std::string(15 - 1, '-') << "+" << std::string(50 - 1, '-') << "+" << std::string(40 -1, '-') << "+" << std::string(20 - 1, '-') << "+" << std::string(30, '-') << endl;
    cout << " " + h0 << setw(15 - hc0 - 1) << "|" << setw((50/2) + (hc1/2)) << h1 << setw((50/2) - (hc1/2)) << "|"
         << setw((40/2) + (hc2/2)) << h2 << setw((40/2) - (hc2/2)) << "|"
         << setw((20/2) + (hc3/2)) << h3 << setw((20/2) - (hc3/2)) << "|"
         << setw((30/2) + (hc4/2)) << h4 << setw((30/2) - (hc4/2)) << endl;
    cout << std::string(15 - 1, '-') << "+" << std::string(50 - 1, '-') << "+" << std::string(40 -1, '-') << "+" << std::string(20 - 1, '-') << "+" << std::string(30, '-') << endl;

    //variable declarations
    /*string bTitle[] = {"Harry Potter", "Lord of the Rings", "The Hobbit", "Hunger Games"};
    string bAuthor[] = {"J.K. Rowling", "J.R.R. Tolkien", "J.R.R. Tolkien", "Suzanne Collins"};
    string bPubDate[] = {"Jan 1, 2020", "Nov 20,2022", "Nov 14, 2022", "March 15, 2015"};
    string bPublisher[] = {"Bloomsbury", "Allen & Unwin", "Allen & Unwin", "Scholastic"};
    int bTitleSize = std::size(bTitle), bookID;

    sort(bTitle, bTitle + bTitleSize, sortAsc);

    for (int x=0; x<bTitleSize; x++)
    {
        int TitleStrSize = bTitle[x].length(),
            AuthorStrSize = bAuthor[x].length(),
            PubDateStrSize = bPubDate[x].length(),
            PublisherStrSize = bPublisher[x].length();
        long long n = x;

        cout << " " << x << setw(15 - countDigit(n) - 1) << "|"
             << " " << bTitle[x] << setw(50 - TitleStrSize - 1) << "|"
             << " " << bAuthor[x] << setw(40 - AuthorStrSize - 1) << "|"
             << " " << bPubDate[x] << setw(20 - PubDateStrSize - 1) << "|"
             << " " << bPublisher[x] << endl;
    }
    cout << std::string(15 - 1, '-') << "+" << std::string(50 - 1, '-') << "+" << std::string(40 -1, '-') << "+" << std::string(20 - 1, '-') << "+" << std::string(30, '-') << endl;

    cout << "\nEnter ID of book to be deleted: ";
    cin >> bookID;
    MainMenu();*/
}








