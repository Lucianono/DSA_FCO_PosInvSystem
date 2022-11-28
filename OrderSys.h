#ifndef ORDERSYS_H
#define ORDERSYS_H

using namespace std;

class OrderSys
{
    protected:


    public:
        struct OrderSystem;
        OrderSys();
        OrderSystem* createOrder(OrderSystem *head, int OrderID, string CustomerName, int Price);
        void displayOrderRecords(OrderSystem *head);
        void adminMenu();

    private:


};

#endif // ORDERSYS_H
