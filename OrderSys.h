#ifndef ORDERSYS_H
#define ORDERSYS_H
#include "IntHandler.h"
#include "UIDesign.h"
#include "BookSys.h"

using namespace std;

class OrderSys
{

    protected:


    public:
        struct OrderByCash;
        struct OrderByInstallment;
        struct BooksOrdered;
        int getOrder(BookSys booksys);
        OrderSys();
        OrderByCash* createOrder(string CustomerName, OrderSys::BooksOrdered *CustBksOrder,int OrderCtr,float CustCash,BookSys booksys);
        OrderByInstallment* createOrderInstallment(string CustomerName, OrderSys::BooksOrdered *CustBksOrder,int OrderCtr,float CustInstall_1,BookSys booksys);
        void payRemainingBal(BookSys booksys);
        void displayOrderRecords(BookSys bookSys);
        bool displayOrdersWithRemainingBal();
        void displayOrderByCashReceipt(OrderByCash *oc,BookSys booksys);
        void displayOrderByInstallmentReceipt(OrderByInstallment *oc,BookSys booksys);
        void orderMenu(BookSys bookSys);
        void deleteOrder(int OrderID);
        void deleteOrderInstallment(int OrderId);
        void deleteOrderMenu();

    private:
        IntHandler ih;
        UIDesign ui;
        int OrderID = 0; //OrderID ctr
        int receiptWidth = 50; //for receipt ui

        //head declaration
        OrderByCash *head = NULL;
        OrderByInstallment *head_2 = NULL;








};

#endif // ORDERSYS_H
