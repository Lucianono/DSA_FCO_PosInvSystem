

//this file is for POS or (Order/Sale) System
//create a blank database for the orders using linked list
//should have the following attributes: OrderID, CustomerName, [BooksOrdered, QtyOrder] , UnitPrice, AmountPrice, VAT,
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
//create function to display the entire Order Database
//create function to read or access every attributes given

//ADDITIONAL COMMENTS
//main function SHOULD NOT BE HERE
//Syntax Structure is wrong(try building this project, it produces an errors)
//make use of classes of SEPERATE FILES refer on sololearn
//editRecords is not necessary
//Linked list is correct but needs improvement
//UI is not necessary
//Attributes is incomplete
//COMMENTING IS NECESSARY for others to read

#include <iostream>
#include <conio.h>
#include "OrderSys.h"

using namespace std;

//node for the BooksOrdered
struct OrderSys::BooksOrdered
{
    int BookID;
    int QtyOrdered;
};

//node for the Orders
struct OrderSys::OrderByCash
{
    int OrderID;
    string CustomerName;
    BooksOrdered *BksQty;
    int OrderCtr;
    int UnitPrice = 200;
    int AmountPrice;
    double VAT = (AmountPrice *.12)+AmountPrice;
    double Cash;
    double Change;

    OrderByCash *next;
};

//head declaration
OrderSys::OrderByCash *head = NULL;

//OrderID ctr
int OrderID = 0;

//constructor
OrderSys::OrderSys(){

}

bool OrderSys::getOrder(){
    string custName;
    int ctr=0;
    bool isCustOrdering = true;
    BooksOrdered *custBks = new BooksOrdered[20];

    cin>>custName;
    while(isCustOrdering){
        int user_input;
        cin>>user_input;
        switch(user_input){
        case 1:
            cin>>custBks[ctr].BookID;
            cin>>custBks[ctr].QtyOrdered;
            ctr++;
            break;
        default:
            isCustOrdering = false;
            break;
        }
    }

    createOrder(custName,custBks,ctr);
}

//add/create order
OrderSys::OrderByCash* OrderSys::createOrder(string CustomerName,OrderSys::BooksOrdered *CustBksOrder,int OrderCtr){
    OrderByCash *orderPointer;
    OrderByCash *newOrder = new OrderByCash;
    newOrder->OrderID = OrderID++;
    newOrder->CustomerName = CustomerName;
    newOrder->BksQty = CustBksOrder;
    cout << newOrder->BksQty[0].BookID;
    newOrder->OrderCtr = OrderCtr;
    newOrder->next = NULL;
    if (head == NULL){
        head = newOrder;
    }else{
        orderPointer = head;
        while(orderPointer->next){
            orderPointer = orderPointer->next;
        }
        orderPointer->next = newOrder;
    }

    return newOrder;
}

//for displaying records
void OrderSys::displayOrderRecords(){
    OrderByCash *displayPointer;
    displayPointer = head;
    cout << endl;
    cout << "\t\t\t User Records \t\t\n";
    cout << endl;
    while (displayPointer)
    {
        cout << "\tOrderID: " << displayPointer->OrderID << endl;
        cout << "\tCustomerName: " << displayPointer->CustomerName << endl;
        cout << "\Books Ordered: "<<endl;
        for(int i = 0; i<displayPointer->OrderCtr; i++){
            cout << displayPointer->BksQty[i].BookID << endl;
            cout << displayPointer->BksQty[i].QtyOrdered << endl;
        }
        displayPointer = displayPointer->next;
        cout << endl;
    }
}

//to display menu
void OrderSys::adminMenu(){
    bool menu_active = true;
    while (menu_active)
    {
        int choice;

        cout << endl;
        cout << "\t\t    -- Admin Menu -- \n";
        cout << endl;
        cout << "\t[1] Display Order Records\n";
        cout << "\t[2] Add Order Records\n";
        cout << endl;
        cout << "\tEnter Choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            displayOrderRecords();
            break;
        }
    }
}

//OrderSys::OrderSystem *addDummyRecords(OrderSys::OrderSystem *head);





//OrderSystem *addDummyRecords(OrderSystem *head)
//{
//    head = createOrder(head, 0, "Math", 0);
//    createOrder(head, 1, "Science", 1000);
//    createOrder(head, 2, "Calculus", 1000);
//    createOrder(head, 3, "General Math", 600);
//    createOrder(head, 4, "History", 500);
//    createOrder(head, 5, "Programming", 600);
//
//    return head;
//}
