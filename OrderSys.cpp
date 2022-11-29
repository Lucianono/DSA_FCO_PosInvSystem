

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
#include <limits>
#include "OrderSys.h"

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

bool OrderSys::getOrder(){
    string custName;
    int ctr=0,totalOrder=0 ;
    float totaldue;
    bool isCustOrdering = true;
    int user_input;
    BooksOrdered *custBks = new BooksOrdered[20];

    cout<<"Customer Name";
    cin>>custName;
    while(isCustOrdering){
        user_input=0;
        user_input = intHandlerInput("Enter Choice [1-2]",user_input,2,1);
        switch(user_input){
        case 1:
            custBks[ctr].BookID = intHandlerInput("Enter Id",custBks[ctr].BookID);
            custBks[ctr].QtyOrdered = intHandlerInput("Enter Quantity",custBks[ctr].QtyOrdered);
            //TBA reject if quantity is not enough
            totalOrder += custBks[ctr].QtyOrdered;
            ctr++;
            break;
        case 2:
            isCustOrdering = false;
            break;
        }
    }

    totaldue = (totalOrder * 200) * 1.12;
    cout<<"Total due"<<totaldue<<endl;

    cout<<"Cash or Installment"<<endl;
    user_input = intHandlerInput("Enter Choice [1-2]",user_input,2,1);
    switch(user_input){
    case 1:{
        float custCash;
        custCash = intHandlerInput("Enter Cash", custCash);
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
    newOrder->TotalPrice = newOrder->VAT + newOrder->AmountPrice;
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
    newOrder->TotalPrice = newOrder->VAT + newOrder->AmountPrice;
    newOrder->Installment_1 = CustInstall_1;
    newOrder->Installment_1_change = newOrder->Installment_1 - (newOrder->TotalPrice*.6);
    newOrder->RemainingBal = newOrder->TotalPrice - (newOrder->TotalPrice*.6);

    cout<<newOrder->Installment_1_change;

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
