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
//    struct BooksOrdered{
//        string a = "wao";
//        int b = 12;
//    };
//
//    BooksOrdered *arr = new BooksOrdered[2];
//1
    order.getOrder();
    order.displayOrderRecords();
    //

    cout << endl;
    cout << "Hello Dataists!" << endl;


    return 0;
}
