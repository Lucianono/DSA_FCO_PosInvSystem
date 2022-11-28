#ifndef ORDERSYS_H
#define ORDERSYS_H

using namespace std;

class OrderSys
{
    private:

    protected:


    public:
        struct OrderByCash;
        struct BooksOrdered;
        OrderSys();
        OrderByCash* createOrder(string CustomerName, OrderSys::BooksOrdered *CustBksOrder,int OrderCtr);
        void displayOrderRecords();
        void adminMenu();
        bool getOrder();




};

#endif // ORDERSYS_H
