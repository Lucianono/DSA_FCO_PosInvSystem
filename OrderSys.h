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
        bool getOrder(BookSys booksys);
        OrderSys();
        OrderByCash* createOrder(string CustomerName, OrderSys::BooksOrdered *CustBksOrder,int OrderCtr,float CustCash);
        OrderByInstallment* createOrderInstallment(string CustomerName, OrderSys::BooksOrdered *CustBksOrder,int OrderCtr,float CustInstall_1);
        void payRemainingBal();
        void displayOrderRecords(BookSys bookSys);
        void displayOrdersWithRemainingBal();
        void adminMenu(BookSys bookSys);
        void deleteOrder(int OrderID);
        void deleteOrderInstallment(int OrderId);

    private:
        IntHandler ih;
        UIDesign ui;
        int OrderID = 0; //OrderID ctr

        //head declaration
        OrderByCash *head = NULL;
        OrderByInstallment *head_2 = NULL;







};

#endif // ORDERSYS_H
