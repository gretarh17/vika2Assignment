#ifndef ORDER_H
#define ORDER_H

#include "Extra.h"
#include "Pizza.h"
#include "Location.h"

class Order
{
    public:
        static const int MAX_EXTRAS_ORDER = 10;
        static const int MAX_PIZZAS_ORDER = 10;
        static const int MAX_NAME_LENGTH = 24;
        static const int MAX_ADDRESS_LENGTH = 24;
        static const int MAX_COMMENT_LENGTH = 64;

        Order();

        int getOrderId() const;
        string getName() const;
        Pizza* getPizzas();
        Extra* getExtras();
        bool isDelivered() const;
        int getLocationId() const;
        string getAddress() const;
        double getTotalPrice() const;
        string getComment() const;
        bool getPaymentStatus() const;
        int getOrderStatus() const;
        bool getActiveState() const;


        void setOrderId(int newOrderId);
        void setName(string newName);
        void addPizzas();       //Kallar � fall � sevices
        void addExtras();       //Kallar � fall � sevices
        void setDeliveryMethod(bool isDelivered);
        void setLocation(int newLocationId);
        void setAddress(string newAddress);
        void setTotalPrice(double newPrice);
        void setComment(string newComment);
        void setPaymentStatus(bool isPayed);
        void setOrderStatus(int newOrderStatus);
        void setActiveState(bool newState);

        //void pizzaOrders();

    private:
        int orderId;
        char name[MAX_NAME_LENGTH];
        Pizza pizzas[MAX_PIZZAS_ORDER];
        Extra extras[MAX_EXTRAS_ORDER];
        bool delivery;
        int locationId;
        char address[MAX_ADDRESS_LENGTH];
        double totalPrice;
        char comment[MAX_COMMENT_LENGTH];
        bool paymentStatus;
        int orderStatus;
        bool isActive;

};

#endif // ORDER_H
