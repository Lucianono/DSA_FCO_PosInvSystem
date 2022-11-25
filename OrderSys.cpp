

//this file is for POS or (Order/Sale) System
//tite
//create a blank database for the orders using linked list
//should have the following attributes: OrderID, CustomerName, [BooksOrdered, QtyOrder] , UnitPrice, AmountPrice, VAT, DiscountPrice, TotalSales



// ->>if the customer will pay by cash, add these attribute : Cash, Change
// ->>if the customer will pay by installment, add these attribute : 1stInstallment, 1stChange, 2ndInstallment, 2ndChange
//create your own OrderID format
//OrderId should be automated, every order should increment ID by 1, example Ord-01 -> Ord-02 -> Ord-03 ->...
//customer's first middle last name is NOT necessary, only the provided name, example Bryan Calulo, REYSAN, Luciano123, etc.
//customer CAN order 1 or more books
//BooksOrdered should linked to BookID in Book System
//BooksOrdered should be in 2D array together with the QtyOrder
//UnitPrice is 200.00
//AmountPrice is UnitPrice*TotalQtyOrder
//VAT is 12% of AmountPrice
//DiscountPrice is 5% of AmountPrice IF TotalQtyOrder is >= 3 ELSE 0
//TotalSales is AmountPrice + VAT - DiscountPrice
//Cash will be given by an imaginary customer
//Cash should decline IF Cash < TotalSales
//Change = Cash - TotalSales
//1stInstallment should be 60% of TotalSales ELSE decline
//2ndInstallment should be the the remaining balance ELSE decline
//assigned to : Vince Hernandez, Andrei Pascual


//create a CRUD system for the Order Database
//should create an Order Entry every transaction
//Customer paying with cash should differ from customer paying with installment
//ask if the customer will pay in cash or installment
//order should not complete IF QtyOrder > Quantity in Book System
//every order should decrement the Book quantity
//create function to display the customer with remaining balance

//void display;
//create function to display the entire Order Database
//create function to read or access every attributes given

#include <iostream>
#include <conio.h>

using namespace std;


void cashType();
void installmentType();

struct Osys
{
    int OrderID;
    string CustomerName;
    int UnitPrice;
    int AmountPrice;
    int Vat;
    int DiscountPrice;
    int TotalSales;
    int Cash;
    int Change;
    int FirstInstallment;
    int FirstChange;
    int SecondFirstInstallment;
    int SecondChange;
    Osys *next;
};

    
int main()
{



    Osys *head;
    head = NULL;

    Osys *newOsys;

    int orderType;
    cout << "\n--------------------------------------------------------------\n";
    cout << "\t-- POS or (Order/Sale) System --\t\t\n";
    cout << "\t[1] Cash\t[2] Installment\t\n";
    cout << "--------------------------------------------------------------\n";
    cout << "\tEnter: "; cin >> orderType;

    switch(orderType)
    {

    case 1:
        cashType();
        break;
    case 2:
        installmentType();
        break;

    }

    newOsys = new Osys;
    newOsys -> OrderID = 1;
    newOsys->next=NULL;
    head=newOsys;

    newOsys = new Osys;
    newOsys -> OrderID = 2;
    newOsys->next=NULL;
    head->next=newOsys;
    
    newOsys = new Osys;
    newOsys -> OrderID = 3;
    newOsys->next=NULL;
    head->next=newOsys;

    Osys *displayPointer;
    displayPointer=head;

    while(displayPointer)
    {

        cout << displayPointer -> OrderID;
        displayPointer=displayPointer->next;    
        getch();
    }


    cout<<"OrderSys Class created"<<endl;


    getch();
    return 0;
}



void cashType()
{
    cout << "\nEnter Cash Amount: ";
    
}

void installmentType()
{

}

