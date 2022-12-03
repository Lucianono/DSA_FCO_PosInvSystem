#include <iostream>
#include "UIDesign.h"
#include "AboutUs.h"
#include "BookSys.h"
#include "SecuritySys.h"
#include "OrderSys.h"
#include "Book.h"

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
    book.printAllBooks();
    order.getOrder(book);
    order.displayOrderRecords(book);
    book.printStockStatus();
    //

    cout << endl;
    cout << "Hello Dataists!" << endl;

    security.showHint();

    if(security.Login()){
        security.Modify();
    }





    return 0;
}
