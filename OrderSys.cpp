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

            cout<<"\t --Book ordered!--\n";
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

    //display total
    totaldue = (totalOrder * 200) * 1.12;
    cout<<"\t Total due : ||  "<<totaldue<<" ||"<<endl;
    cout<<endl;

    //ask if pay by cash or installment
    user_input = ih.intHandlerInput("\t [1]Pay by Cash or [2]Pay by Installment : ",user_input,2,1);
    switch(user_input){
    case 1:{

        //condition if total is discounted
        if(totalOrder >= 3){
            cout<<"\t Discounted!"<<endl;
            totaldue = (totalOrder * 200) * 1.07;
            cout<<"\t Total due : ||  "<<totaldue<<" ||"<<endl;
            cout<<endl;
        }

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

    system("CLS");
    ui.TitleHeader();
    ui.setTxtColor(7);
    ui.PageTitle("Pay Balance");

    if(displayOrdersWithRemainingBal()){

        int user_input;
        user_input = ih.intHandlerInput("Enter ID : ",user_input);
        bool isOrderFound = false;


        OrderByInstallment *orderPointer = head_2;
        while (orderPointer)
        {
            if(orderPointer->OrderID == user_input && orderPointer->RemainingBal != 0){
                isOrderFound = true;
                cout << endl;
                cout << "\tOrderID: " << orderPointer->OrderID << endl;
                cout << "\tCustomerName: " << orderPointer->CustomerName << endl;
                cout << "\tRemainingBal: " << orderPointer->RemainingBal << endl;
                int CustCash;
                CustCash = ih.intHandlerInput("Enter Cash ", CustCash);
                if(CustCash >= orderPointer->RemainingBal){
                    orderPointer->Installment_2 = CustCash;
                    orderPointer->Installment_2_change = orderPointer->Installment_2 - orderPointer->RemainingBal;
                    orderPointer->RemainingBal = 0;
                    displayOrderByInstallmentReceipt(orderPointer,bookSys);
                }else{
                    cout<<" -Insufficient Amount! Order Failed-"<<endl;
                    system("pause");
                }
                break;
            }
            orderPointer = orderPointer->next;
        }
        if(!isOrderFound){
            cout<<" -Order Not Found!- "<<endl;
            system("pause");
        }
    }else{
        cout<<" -No Pending Balance!-"<<endl;
        system("pause");
    }

}

//for displaying ALL records
void OrderSys::displayOrderRecords(BookSys bookSys){
    system("CLS");
    ui.TitleHeader();
    ui.setTxtColor(7);

    OrderByCash *displayPointer;
    displayPointer = head;
    ui.PageTitle("Order by Cash Records");
    while (displayPointer)
    {

        cout << string(receiptWidth,'=')<<endl;
        cout << "OrderID: " << displayPointer->OrderID << endl;
        cout << "CustomerName: " << displayPointer->CustomerName << endl;
        cout << "Books Ordered: " << setw(receiptWidth-17) << "PHP" << endl;
        for(int i = 0; i<displayPointer->OrderCtr; i++){
            Book *selectedBook = bookSys.getBook(displayPointer->BksQty[i].BookID);
            cout << "Book ID :"<<displayPointer->BksQty[i].BookID << endl;
            cout << "  "<<selectedBook->getBookName() << "   x" << displayPointer->BksQty[i].QtyOrdered <<endl;
            cout << string(receiptWidth/2,' ') << "@200 " << string((receiptWidth/2)-11,'-') <<" "<< displayPointer->BksQty[i].QtyOrdered*200<<endl;
        }

        cout<<endl;
        cout << "AMOUNT" << string(receiptWidth-11,' ')<< displayPointer->AmountPrice << endl;
        cout << "VAT" << string(receiptWidth-8,' ')<< displayPointer->VAT << endl;
        cout << "DISCOUNT" << string(receiptWidth-13,' ') << displayPointer->Discount << endl;
        cout << "T O T A L" << string(receiptWidth-14,' ') << displayPointer->TotalPrice<< endl;
        cout << "CASH" << string(receiptWidth-9,' ')<< displayPointer->Cash  << endl;
        cout << "CHANGE" << string(receiptWidth-11,' ')<< displayPointer->Change  << endl;
        cout << string(receiptWidth,'=')<<endl<<endl;

        displayPointer = displayPointer->next;
        cout << endl;
    }

    //display all Order By Installment
    OrderByInstallment *displayPointer_2;
    displayPointer_2 = head_2;
    ui.PageTitle("Order by Installment Records");
    while (displayPointer_2)
    {
        cout << string(receiptWidth,'=')<<endl;
        cout << "OrderID: " << displayPointer_2->OrderID << endl;
        cout << "CustomerName: " << displayPointer_2->CustomerName << endl;
        cout << "Books Ordered: " << setw(receiptWidth-17) << "PHP" << endl;
        for(int i = 0; i<displayPointer_2->OrderCtr; i++){
            Book *selectedBook = bookSys.getBook(displayPointer_2->BksQty[i].BookID);
            cout << "Book ID :"<<displayPointer_2->BksQty[i].BookID << endl;
            cout << "  "<<selectedBook->getBookName() << "   x" << displayPointer_2->BksQty[i].QtyOrdered <<endl;
            cout << string(receiptWidth/2,' ') << "@200 " << string((receiptWidth/2)-11,'-') <<" "<< displayPointer_2->BksQty[i].QtyOrdered*200<<endl;
        }

        cout<<endl;
        cout << "AMOUNT" << string(receiptWidth-11,' ')<< displayPointer_2->AmountPrice << endl;
        cout << "VAT" << string(receiptWidth-8,' ')<< displayPointer_2->VAT << endl;
        cout << "DISCOUNT" << string(receiptWidth-13,' ') << displayPointer_2->Discount << endl;
        cout << "T O T A L" << string(receiptWidth-14,' ') << displayPointer_2->TotalPrice<< endl;
        cout << "1ST INSTALLMENT" << string(receiptWidth-20,' ') << displayPointer_2->Installment_1 << endl;
        cout << "1ST INSTALLMENT CHANGE" << string(receiptWidth-27,' ') << displayPointer_2->Installment_1_change << endl;
        cout << "2ND INSTALLMENT" << string(receiptWidth-20,' ') << displayPointer_2->Installment_2 << endl;
        cout << "2ND INSTALLMENT CHANGE" << string(receiptWidth-27,' ') << displayPointer_2->Installment_2_change << endl;
        cout << "REMAINING BALANCE" << string(receiptWidth-22,' ') << displayPointer_2->RemainingBal << endl;
        cout << string(receiptWidth,'=')<<endl<<endl;

        displayPointer_2 = displayPointer_2->next;
        cout << endl;
    }

    system("pause");
}
//for displaying Orders With Remaining Balance
bool OrderSys::displayOrdersWithRemainingBal(){
    bool hasPendingBal = false;
    OrderByInstallment *displayPointer_2;
    displayPointer_2 = head_2;

    cout << endl;
    ui.textCenter("Customers with Remaining Balance",70);
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


        cout << string(receiptWidth,'=')<<endl;
        ui.textCenter("CICT BOOKSTORE",receiptWidth);
        ui.textCenter("Bulacan State University",receiptWidth);
        ui.textCenter("Malolos, Bulacan",receiptWidth);
        ui.textCenter("(044) 919 7800",receiptWidth);
        cout << string(receiptWidth,'=')<<endl<<endl;

        cout << "OrderID: " << oc->OrderID << endl;
        cout << "CustomerName: " << oc->CustomerName << endl;
        cout << "Books Ordered: " << setw(receiptWidth-17) << "PHP" << endl;
        for(int i = 0; i<oc->OrderCtr; i++){
            Book *selectedBook = bookSys.getBook(oc->BksQty[i].BookID);
            cout << "Book ID :"<<oc->BksQty[i].BookID << endl;
            cout << "  "<<selectedBook->getBookName() << "   x" << oc->BksQty[i].QtyOrdered <<endl;
            cout << string(receiptWidth/2,' ') << "@200 " << string((receiptWidth/2)-11,'-') <<" "<< oc->BksQty[i].QtyOrdered*200<<endl;
        }

        cout<<endl;
        cout << string(receiptWidth,'-')<<endl;
        cout << "AMOUNT" << string(receiptWidth-11,' ')<< oc->AmountPrice << endl;
        cout << "VAT" << string(receiptWidth-8,' ')<< oc->VAT << endl;
        cout << "DISCOUNT" << string(receiptWidth-13,' ') << oc->Discount << endl;
        cout << string(receiptWidth,'-')<<endl;
        cout << "T O T A L" << string(receiptWidth-14,' ') << oc->TotalPrice<< endl;
        cout << string(receiptWidth,'-')<<endl;
        cout << "CASH" << string(receiptWidth-9,' ')<< oc->Cash  << endl;
        cout << "CHANGE" << string(receiptWidth-11,' ')<< oc->Change  << endl;
        cout << string(receiptWidth,'=')<<endl<<endl;


    system("pause");


}
void OrderSys::displayOrderByInstallmentReceipt(OrderByInstallment *oc, BookSys bookSys){
    system("CLS");
    ui.TitleHeader();
    ui.setTxtColor(7);
    ui.PageTitle("Installment Receipt");

        cout << string(receiptWidth,'=')<<endl;
        ui.textCenter("CICT BOOKSTORE",receiptWidth);
        ui.textCenter("Bulacan State University",receiptWidth);
        ui.textCenter("Malolos, Bulacan",receiptWidth);
        ui.textCenter("(044) 919 7800",receiptWidth);
        cout << string(receiptWidth,'=')<<endl<<endl;

        cout << "OrderID: " << oc->OrderID << endl;
        cout << "CustomerName: " << oc->CustomerName << endl;
        cout << "Books Ordered: " << setw(receiptWidth-17) << "PHP" << endl;
        for(int i = 0; i<oc->OrderCtr; i++){
            Book *selectedBook = bookSys.getBook(oc->BksQty[i].BookID);
            cout << "Book ID :"<<oc->BksQty[i].BookID << endl;
            cout << "  "<<selectedBook->getBookName() << "   x" << oc->BksQty[i].QtyOrdered <<endl;
            cout << string(receiptWidth/2,' ') << "@200 " << string((receiptWidth/2)-11,'-') <<" "<< oc->BksQty[i].QtyOrdered*200<<endl;
        }

        cout<<endl;
        cout << string(receiptWidth,'-')<<endl;
        cout << "AMOUNT" << string(receiptWidth-11,' ')<< oc->AmountPrice << endl;
        cout << "VAT" << string(receiptWidth-8,' ')<< oc->VAT << endl;
        cout << "DISCOUNT" << string(receiptWidth-13,' ') << oc->Discount << endl;
        cout << string(receiptWidth,'-')<<endl;
        cout << "T O T A L" << string(receiptWidth-14,' ') << oc->TotalPrice<< endl;
        cout << string(receiptWidth,'-')<<endl;
        cout << "1ST INSTALLMENT" << string(receiptWidth-20,' ') << oc->Installment_1 << endl;
        cout << "1ST INSTALLMENT CHANGE" << string(receiptWidth-27,' ') << oc->Installment_1_change << endl;
        cout << "2ND INSTALLMENT" << string(receiptWidth-20,' ') << oc->Installment_2 << endl;
        cout << "2ND INSTALLMENT CHANGE" << string(receiptWidth-27,' ') << oc->Installment_2_change << endl;
        cout << "REMAINING BALANCE" << string(receiptWidth-22,' ') << oc->RemainingBal << endl;
        cout << string(receiptWidth,'=')<<endl<<endl;

    cout << endl;

    system("pause");
}
//to display menu
void OrderSys::orderMenu(BookSys bookSys){

    bool menu_active = true;
    while(menu_active){
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
                menu_active = false;
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

}

//deleting an order record
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

