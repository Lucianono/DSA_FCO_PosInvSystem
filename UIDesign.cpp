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
    string Title = "CICT Book Store";
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
//text center-er
void UIDesign::textCenter(string title,int decorLength){
    int iterate = (decorLength - title.length())/2;
    cout<< string(iterate,' ') << title;
    cout << endl;
}


//constructor
UIDesign::UIDesign()
{

}












