

//this file is for POS or (Order/Sale) System

//BooksOrdered should linked to BookID in Book System
//assigned to : Vince Hernandez, Andrei Pascual


//create a CRUD system for the Order Database

//order should not complete IF QtyOrder > Quantity in Book System
//every order should decrement the Book quantity
//create function to display the customer with remaining balance
//create function to read or access every necessary attributes given


#include <iostream>
#include <conio.h>
#include <limits>
#include "OrderSys.h"
#include "BookSys.h"
#include "Book.h"

using namespace std;

//if input wrong this happens
int intHandlerInput(string displayHint,int inputData){
    while (cout << displayHint && !(cin >> inputData )) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "   -Invalid Input. Please try again.- \n";
        }
    return inputData;
}
int intHandlerInput(string displayHint,int inputData , int a, int b){
    while (cout << displayHint && !(cin >> inputData) || (inputData>a || inputData<b)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "   -Invalid Input. Please try again.- \n";
        }
    return inputData;
}


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
    float VAT ;
    float Discount;
    float TotalPrice;
    float Cash = 0;
    float Change = 0;

    OrderByCash *next;
};
struct OrderSys::OrderByInstallment
{
    int OrderID;
    string CustomerName;
    BooksOrdered *BksQty;
    int OrderCtr;
    int UnitPrice = 200;
    int AmountPrice;
    float VAT ;
    float Discount;
    float TotalPrice;
    float Installment_1 = 0;
    float Installment_1_change = 0;
    float RemainingBal = 0;
    float Installment_2 = 0;
    float Installment_2_change = 0;


    OrderByInstallment *next;
};

//head declaration
OrderSys::OrderByCash *head = NULL;
OrderSys::OrderByInstallment *head_2 = NULL;

//OrderID ctr
int OrderID = 0;

//constructor
OrderSys::OrderSys(){

}

// getting orders
bool OrderSys::getOrder(){
    string custName;
    int ctr=0,totalOrder=0 ;
    float totaldue;
    int user_input = 1;
    BooksOrdered *custBks = new BooksOrdered[20];

    cout<<"Customer Name : ";
    cin>>custName;
    while(user_input == 1){
        switch(user_input){
        case 1:
            custBks[ctr].BookID = intHandlerInput("Enter Book Id : ",custBks[ctr].BookID);
            custBks[ctr].QtyOrdered = intHandlerInput("Enter Quantity : ",custBks[ctr].QtyOrdered);
            //TBA reject if quantity is not enough
            totalOrder += custBks[ctr].QtyOrdered;
            ctr++;
            break;
        case 2:

            break;
        }
        user_input = intHandlerInput("[1] Order more [2] Not anymore",user_input,2,1);
    }

    //condition if total is discounted
    if(totalOrder >= 3){
        cout<<"Discounted!"<<endl;
        totaldue = (totalOrder * 200) * 1.07;
    }
    else{
        totaldue = (totalOrder * 200) * 1.12;
    }
    cout<<"Total due"<<totaldue<<endl;

    user_input = intHandlerInput("[1]Cash or [2]Installment",user_input,2,1);
    switch(user_input){
    case 1:{
        float custCash;
        custCash = intHandlerInput("Enter Cash ", custCash);
        if (custCash >= totaldue){
            createOrder(custName,custBks,ctr,custCash);
            return true;
        }else{
            cout<<"Insufficient Amount"<<endl;
            return false;
        }
        break;
    }
    case 2:{
        cout<<"1st Installment : "<<totaldue * .6<<endl;
        float custInstall;
        custInstall = intHandlerInput("Enter Cash", custInstall);
        if (custInstall >= totaldue * .6){
            createOrderInstallment(custName,custBks,ctr,custInstall);
            return true;
        }else{
            cout<<"Insufficient Amount"<<endl;
            return false;
        }
        break;
    }
    }





}

//add/create order
OrderSys::OrderByCash* OrderSys::createOrder(string CustomerName,OrderSys::BooksOrdered *CustBksOrder,int OrderCtr, float CustCash){
    OrderByCash *orderPointer;
    OrderByCash *newOrder = new OrderByCash;
    newOrder->OrderID = OrderID++;
    newOrder->CustomerName = CustomerName;
    newOrder->BksQty = CustBksOrder;
    newOrder->OrderCtr = OrderCtr;
    int TotalQty=0;
    for(int i = 0; i<OrderCtr; i++){
        TotalQty += newOrder->BksQty[i].QtyOrdered;
    }
    newOrder->AmountPrice = TotalQty * newOrder->UnitPrice;
    newOrder->VAT = newOrder->AmountPrice * 0.12;
    newOrder->Discount = newOrder->AmountPrice * 0.05;
    newOrder->TotalPrice = (newOrder->AmountPrice + newOrder->VAT) - newOrder->Discount;
    newOrder->Cash = CustCash;
    newOrder->Change = newOrder->Cash - newOrder->TotalPrice;


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
OrderSys::OrderByInstallment* OrderSys::createOrderInstallment(string CustomerName,OrderSys::BooksOrdered *CustBksOrder,int OrderCtr, float CustInstall_1){
    OrderByInstallment *orderPointer;
    OrderByInstallment *newOrder = new OrderByInstallment;
    newOrder->OrderID = OrderID++;
    newOrder->CustomerName = CustomerName;
    newOrder->BksQty = CustBksOrder;
    newOrder->OrderCtr = OrderCtr;
    int TotalQty=0;
    for(int i = 0; i<OrderCtr; i++){
        TotalQty += newOrder->BksQty[i].QtyOrdered;
    }
    newOrder->AmountPrice = TotalQty * newOrder->UnitPrice;
    newOrder->VAT = newOrder->AmountPrice * 0.12;
    newOrder->Discount = newOrder->AmountPrice * 0.05;
    newOrder->TotalPrice = (newOrder->AmountPrice + newOrder->VAT) - newOrder->Discount;
    newOrder->Installment_1 = CustInstall_1;
    newOrder->Installment_1_change = newOrder->Installment_1 - (newOrder->TotalPrice*.6);
    newOrder->RemainingBal = newOrder->TotalPrice - (newOrder->TotalPrice*.6);


    newOrder->next = NULL;
    if (head_2 == NULL){
        head_2 = newOrder;
    }else{
        orderPointer = head_2;
        while(orderPointer->next){
            orderPointer = orderPointer->next;
        }
        orderPointer->next = newOrder;
    }

    return newOrder;
}

//pay remaining balance
void OrderSys::payRemainingBal(){
    int user_input;
    user_input = intHandlerInput("Enter ID : ",user_input,OrderID-1,0);


    OrderByInstallment *orderPointer = head_2;
    while (orderPointer)
    {
        if(orderPointer->OrderID == user_input){
            cout << "\tOrderID: " << orderPointer->OrderID << endl;
            cout << "\tCustomerName: " << orderPointer->CustomerName << endl;
            cout << "\tRemainingBal: " << orderPointer->RemainingBal << endl;
            int CustCash;
            CustCash = intHandlerInput("Enter Cash ", CustCash);
            if(CustCash >= orderPointer->RemainingBal){
                orderPointer->Installment_2 = CustCash;
                orderPointer->Installment_2_change = orderPointer->Installment_2 - orderPointer->RemainingBal;
                orderPointer->RemainingBal = 0;
            }else{
                cout<<"Insufficient Amount"<<endl;
            }
            break;
        }
        orderPointer = orderPointer->next;
        cout << endl;
    }

}

//for displaying records
void OrderSys::displayOrderRecords(BookSys bookSys){
    //display all Order By Cash
    OrderByCash *displayPointer;
    displayPointer = head;
    cout << endl;
    cout << "\t\t\t User Records \t\t\n";
    cout << endl;
    while (displayPointer)
    {
        cout << "\tOrderID: " << displayPointer->OrderID << endl;
        cout << "\tCustomerName: " << displayPointer->CustomerName << endl;
        cout << "\tBooks Ordered: "<<endl;
        for(int i = 0; i<displayPointer->OrderCtr; i++){
            Book *selectedBook = bookSys.getBook(displayPointer->BksQty[i].BookID);
            cout <<"\t"<<displayPointer->BksQty[i].BookID << endl;
            cout << "\t" << selectedBook->getBookName() << endl;
            cout <<"\t"<< displayPointer->BksQty[i].QtyOrdered << endl;
        }
        cout << "\tUnitPrice: " << displayPointer->UnitPrice << endl;
        cout << "\tAmountPrice: " << displayPointer->AmountPrice << endl;
        cout << "\tVAT: " << displayPointer->VAT << endl;
        cout << "\tDiscount: " << displayPointer->Discount << endl;
        cout << "\tTotalPrice: " << displayPointer->TotalPrice << endl;
        cout << "\tCash: " << displayPointer->Cash << endl;
        cout << "\tChange: " << displayPointer->Change << endl;


        displayPointer = displayPointer->next;
        cout << endl;
    }

    //display all Order By Installment
    OrderByInstallment *displayPointer_2;
    displayPointer_2 = head_2;
    cout << endl;
    cout << "\t\t\t User Records \t\t\n";
    cout << endl;
    while (displayPointer_2)
    {
        cout << "\tOrderID: " << displayPointer_2->OrderID << endl;
        cout << "\tCustomerName: " << displayPointer_2->CustomerName << endl;
        cout << "\Books Ordered: "<<endl;
        for(int i = 0; i<displayPointer_2->OrderCtr; i++){
            Book *selectedBook = bookSys.getBook(displayPointer_2->BksQty[i].BookID);
            cout << displayPointer_2->BksQty[i].BookID << endl;
            cout << "\t" << selectedBook->getBookName() << endl;
            cout << displayPointer_2->BksQty[i].QtyOrdered << endl;
        }
        cout << "\tUnitPrice: " << displayPointer_2->UnitPrice << endl;
        cout << "\tAmountPrice: " << displayPointer_2->AmountPrice << endl;
        cout << "\tVAT: " << displayPointer_2->VAT << endl;
        cout << "\tDiscount: " << displayPointer_2->Discount << endl;
        cout << "\tTotalPrice: " << displayPointer_2->TotalPrice << endl;
        cout << "\t1stInstallment: " << displayPointer_2->Installment_1 << endl;
        cout << "\t1stInstallment Change: " << displayPointer_2->Installment_1_change << endl;
        cout << "\tRemainingBal: " << displayPointer_2->RemainingBal << endl;
        cout << "\t2nd Installment: " << displayPointer_2->Installment_2 << endl;
        cout << "\t2nd Installment Change: " << displayPointer_2->Installment_2_change << endl;
        displayPointer_2 = displayPointer_2->next;
        cout << endl;
    }
}

//for displaying Orders With Remaining Balance
void OrderSys::displayOrdersWithRemainingBal(){
    OrderByInstallment *displayPointer_2;
    displayPointer_2 = head_2;
    cout << endl;
    cout << "\t\t\t User Records \t\t\n";
    cout << endl;
    while (displayPointer_2)
    {
        if(displayPointer_2->RemainingBal != 0){
            cout << "\tOrderID: " << displayPointer_2->OrderID << endl;
            cout << "\tCustomerName: " << displayPointer_2->CustomerName << endl;
            cout << "\tRemainingBal: " << displayPointer_2->RemainingBal << endl;
        }
        displayPointer_2 = displayPointer_2->next;
        cout << endl;
    }
}

//to display menu
void OrderSys::adminMenu(BookSys bookSys){
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
            displayOrderRecords(bookSys);
            break;
        }
    }
}

void OrderSys::deleteOrder(int OrderID) {
    OrderByCash *orderIterator = head;
    OrderByCash *previousOrder = NULL;

    while (orderIterator) {
        if (orderIterator->OrderID == OrderID) {
            if (previousOrder) {
                previousOrder->next = orderIterator->next;
            } else {
                head = orderIterator->next;
            }
            break;
        }
        previousOrder = orderIterator;
        orderIterator = orderIterator->next;
    }
}

void OrderSys::deleteOrderInstallment(int OrderID) {
    OrderByInstallment *orderIterator = head_2;
    OrderByInstallment *previousOrder = NULL;

    while (orderIterator) {
        if (orderIterator->OrderID == OrderID) {
            if (previousOrder) {
                previousOrder->next = orderIterator->next;
            } else {
                head_2 = orderIterator->next;
            }
            break;
        }
        previousOrder = orderIterator;
        orderIterator = orderIterator->next;
    }
}

