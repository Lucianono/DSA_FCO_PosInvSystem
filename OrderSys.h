#ifndef ORDERSYS_H
#define ORDERSYS_H

#include "BookSys.h"

using namespace std;

class OrderSys
{
    private:

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





};

#endif // ORDERSYS_H
