#include <iostream>
#include "UIDesign.h"
#include "AboutUs.h"
#include "BookSys.h"
#include "SecuritySys.h"
#include "OrderSys.h"


using namespace std;

int main()
{
    //this is the main file/class
    //all methods and features will be call here
    //Assigned to: Bryan Calulo

    UIDesign ui;
    AboutUs abt_us;
    BookSys book;
    SecuritySys security;
    OrderSys order;

    //
    book.addBook("MMW101",1995);
    book.addBook("MMW1d01",1995);
    book.updateBook(0,77);
    book.deleteBook(0);
    //

    cout << endl;
    cout << "Hello Dataists!" << endl;


    return 0;
}
