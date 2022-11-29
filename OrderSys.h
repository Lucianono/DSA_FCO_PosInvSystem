#ifndef ORDERSYS_H
#define ORDERSYS_H

using namespace std;

class OrderSys
{
    private:

    protected:


    public:
        struct OrderByCash;
        struct OrderByInstallment;
        struct BooksOrdered;
        OrderSys();
        OrderByCash* createOrder(string CustomerName, OrderSys::BooksOrdered *CustBksOrder,int OrderCtr,float CustCash);
        OrderByInstallment* createOrderInstallment(string CustomerName, OrderSys::BooksOrdered *CustBksOrder,int OrderCtr,float CustInstall_1);
        void displayOrderRecords();
        void adminMenu();
        bool getOrder();




};

#endif // ORDERSYS_H
