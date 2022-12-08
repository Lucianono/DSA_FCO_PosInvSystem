#include "OrderSys.h"
#include "BookSys.h"
#include "Book.h"
#include <iostream>
#include <conio.h>
#include <iomanip>


using namespace std;


//node for the BooksOrdered
struct OrderSys::BooksOrdered{
    int BookID;
    int QtyOrdered;
};

//node for the Orders
struct OrderSys::OrderByCash{
    int OrderID;
    string CustomerName;
    BooksOrdered *BksQty;
    int OrderCtr;
    int UnitPrice = 200;
    int AmountPrice;
    int php;
    float VAT ;
    float Discount;
    float TotalPrice;
    float Cash = 0;
    float Change = 0;

    OrderByCash *next;
};
struct OrderSys::OrderByInstallment{
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


//constructor
OrderSys::OrderSys(){

}

// getting orders
int OrderSys::getOrder(BookSys booksys){

    system("CLS");
    ui.TitleHeader();
    ui.setTxtColor(7);
    ui.PageTitle("Order Books");

    string custName;
    int ctr=0,totalOrder=0 ;
    float totaldue;
    int user_input = 1;
    BooksOrdered *custBks = new BooksOrdered[20];

    cout<<"\t Customer Name : ";
    getchar();
    getline(cin,custName);

    booksys.printAllBooks();
    cout<<endl;

    while(user_input == 1){
        switch(user_input){
        case 1:
            custBks[ctr].BookID = ih.intHandlerInput("\t Enter Book Id : ",custBks[ctr].BookID);
            //check if book exists
            if(!booksys.getBook(custBks[ctr].BookID)){
                cout<<"\t --Book not found!--\n";
                break;
            }
            //reject if quantity is not enough
            custBks[ctr].QtyOrdered = ih.intHandlerInput("\t Enter Quantity : ",custBks[ctr].QtyOrdered);
            if(!(booksys.getBook(custBks[ctr].BookID)->getBookQuantity()>=custBks[ctr].QtyOrdered)){
                cout<<"\t --Stock is not enough!--\n";
                break;
            }

            booksys.updateBook(custBks[ctr].BookID,booksys.getBook(custBks[ctr].BookID)->getBookQuantity() - custBks[ctr].QtyOrdered);
            totalOrder += custBks[ctr].QtyOrdered;
            ctr++;
            break;
        case 2:

            break;
        }
        user_input = ih.intHandlerInput("\t [1] Order more [2] Not anymore : ",user_input,2,1);
        cout<<endl;
    }

    //condition if total is discounted
    if(totalOrder >= 3){
        cout<<"\t Discounted!"<<endl;
        totaldue = (totalOrder * 200) * 1.07;
    }
    else{
        totaldue = (totalOrder * 200) * 1.12;
    }
    cout<<"\t Total due : ||  "<<totaldue<<" ||"<<endl;
    cout<<endl;

    //ask if pay by cash or installment
    user_input = ih.intHandlerInput("\t [1]Pay by Cash or [2]Pay by Installment : ",user_input,2,1);
    switch(user_input){
    case 1:{
        float custCash;
        custCash = ih.intHandlerInput("\t Enter Cash : ", custCash);
        if (custCash >= totaldue){
            createOrder(custName,custBks,ctr,custCash,booksys);
            return OrderID-1;
        }else{
            cout<<"\t --Insufficient Amount! Order failed.--"<<endl;
            return -1;
        }
        break;
    }
    case 2:{
        cout<<"\t 1st Installment : "<<totaldue * .6<<endl;
        float custInstall;
        custInstall = ih.intHandlerInput("\t Enter Cash : ", custInstall);
        if (custInstall >= totaldue * .6){
            createOrderInstallment(custName,custBks,ctr,custInstall,booksys);
            return OrderID-1;
        }else{
            cout<<"\t --Insufficient Amount! Order failed.--"<<endl;
            return -1;
        }
        break;
    }
    }


}

//add/create order
OrderSys::OrderByCash* OrderSys::createOrder(string CustomerName,OrderSys::BooksOrdered *CustBksOrder,int OrderCtr, float CustCash, BookSys booksys){
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
    if(TotalQty>=3){
        newOrder->Discount = newOrder->AmountPrice * 0.05;
    }else{
        newOrder->Discount = 0;
    }
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

    displayOrderByCashReceipt(newOrder,booksys);

    return newOrder;
}
OrderSys::OrderByInstallment* OrderSys::createOrderInstallment(string CustomerName,OrderSys::BooksOrdered *CustBksOrder,int OrderCtr, float CustInstall_1,BookSys booksys){
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
    if(TotalQty>=3){
        newOrder->Discount = newOrder->AmountPrice * 0.05;
    }else{
        newOrder->Discount = 0;
    }
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

    displayOrderByInstallmentReceipt(newOrder,booksys);

    return newOrder;
}

//pay remaining balance
void OrderSys::payRemainingBal(BookSys bookSys){

    if(displayOrdersWithRemainingBal()){

        int user_input;
        user_input = ih.intHandlerInput("Enter ID : ",user_input,OrderID-1,0);


        OrderByInstallment *orderPointer = head_2;
        while (orderPointer)
        {
            if(orderPointer->OrderID == user_input){
                cout << "\tOrderID: " << orderPointer->OrderID << endl;
                cout << "\tCustomerName: " << orderPointer->CustomerName << endl;
                cout << "\tRemainingBal: " << orderPointer->RemainingBal << endl;
                int CustCash;
                CustCash = ih.intHandlerInput("Enter Cash ", CustCash);
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
    }else{
        cout<<"No Pending Balance!"<<endl;
    }

    system("pause");
    orderMenu(bookSys);


}

//for displaying records
void OrderSys::displayOrderRecords(BookSys bookSys){

    //display all Order By Cash
    OrderByCash *displayPointer;
    displayPointer = head;
    cout << endl;
    cout << "\t\t\t Order by Cash Records\n";
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
    cout << "\t\t\t Order by Installment Records \t\t\n";
    cout << endl;
    while (displayPointer_2)
    {
        cout << "\tOrderID: " << displayPointer_2->OrderID << endl;
        cout << "\tCustomerName: " << displayPointer_2->CustomerName << endl;
        cout << "\tBooks Ordered: "<<endl;
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

    system("pause");
    orderMenu(bookSys);
}
//for displaying Orders With Remaining Balance
bool OrderSys::displayOrdersWithRemainingBal(){
    bool hasPendingBal = false;
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
            hasPendingBal = true;
        }
        displayPointer_2 = displayPointer_2->next;
        cout << endl;
    }
    return hasPendingBal;
}
//for displaying a single receipt

void OrderSys::displayOrderByCashReceipt(OrderByCash *oc, BookSys bookSys){
    system("CLS");
    ui.TitleHeader();
    ui.setTxtColor(7);
    ui.PageTitle("Receipt");


        cout << "=========================================================================\n";
        cout << "                               CICT BOOKSTORE" << endl;
        cout << "                         Bulacan State University" << endl;
        cout << "                              Malolos, Bulacan" << endl;
        cout << "                               0999-123-4567" << endl;
        cout << "=========================================================================\n"<< endl;
        cout << "\tOrderID: " << oc->OrderID << endl;
        cout << "\tCustomerName: " << oc->CustomerName << endl;
        cout << "\tBooks Ordered: ";
        for(int i = 0; i<oc->OrderCtr; i++){
            Book *selectedBook = bookSys.getBook(oc->BksQty[i].BookID);
            cout << oc->BksQty[i].BookID << endl << endl;
            cout << "                                                          PHP\n";
            cout << "\t" << selectedBook->getBookName() << "    x";
            cout << oc->BksQty[i].QtyOrdered;
        }
        cout << "                                               @" << oc->UnitPrice;


        cout << "-------------------------------------------------------------------------\n" << endl;
        cout << "\tAMOUNT                                                     " << oc->AmountPrice << endl;
        cout << "\tVAT                                                        " << oc->VAT << endl;
        cout << "\tDISC                                                       " << oc->Discount << endl << endl;
        cout << "-------------------------------------------------------------------------\n" << endl;
        cout << "\tTOTAL                                                      " << oc->TotalPrice << endl << endl;
        cout << "\tCASH                                                       " << oc->Cash << endl;
        cout << "\tCHANGE                                                     " << oc->Change << endl;







    system("pause");
    orderMenu(bookSys);


}
void OrderSys::displayOrderByInstallmentReceipt(OrderByInstallment *oc, BookSys bookSys){
    system("CLS");
    ui.TitleHeader();
    ui.setTxtColor(8);
    ui.PageTitle("Installment Receipt");

        cout << "=========================================================================\n";
        cout << "                               CICT BOOKSTORE" << endl;
        cout << "                         Bulacan State University" << endl;
        cout << "                              Malolos, Bulacan" << endl;
        cout << "                               0999-123-4567" << endl;
        cout << "=========================================================================\n"<< endl;
        cout << "\tOrderID: " << oc->OrderID << endl;
        cout << "\tCustomerName: " << oc->CustomerName << endl;
        cout << "\tBooks Ordered: ";
        for(int i = 0; i<oc->OrderCtr; i++){
            Book *selectedBook = bookSys.getBook(oc->BksQty[i].BookID);
            cout << oc->BksQty[i].BookID << endl << endl;
            cout << "                                                          PHP\n";
            cout << "\t" << selectedBook->getBookName() << "    x";
            cout << oc->BksQty[i].QtyOrdered;
        }
        cout << "                                               @" << oc->UnitPrice;

        cout << "-------------------------------------------------------------------------\n" << endl;
        cout << "\tAMOUNT                                                     " << oc->AmountPrice << endl;
        cout << "\tVAT                                                        " << oc->VAT << endl;
        cout << "\tDISC                                                       " << oc->Discount << endl;
        cout << "\tTOTAL                                                      " << oc->TotalPrice << endl << endl;
        cout << "-------------------------------------------------------------------------\n" << endl;
        cout << "\t1st Installment: " << oc->Installment_1 << endl;
        cout << "\t1st Installment Change: " << oc->Installment_1_change << endl;
        cout << "\tRemainingBal: " << oc->RemainingBal << endl;
        cout << "\t2nd Installment: " << oc->Installment_2 << endl;
        cout << "\t2nd Installment Change: " << oc->Installment_2_change << endl;

    cout << endl;

    system("pause");
    orderMenu(bookSys);
}


//to display menu
void OrderSys::orderMenu(BookSys bookSys){

    system("CLS");
    ui.TitleHeader();
    ui.setTxtColor(7);
    ui.PageTitle("Order Menu");
    cout << "[1] Add Order" << endl;
    cout << "[2] Pay Remaining Balance" << endl;
    cout << "[3] Display All Order Records" << endl << endl;
    cout << "[0] Back" << endl;

    int opt;
    opt = ih.intHandlerInput("\n\nEnter Option: ", opt,3,0);

    switch (opt){
        case 0:
            //go back to main menu
            break;
        case 1:
            getOrder(bookSys);
            break;
        case 2:
            payRemainingBal(bookSys);
            break;
        case 3:
            displayOrderRecords(bookSys);
            break;
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

//stock issue when order failed
