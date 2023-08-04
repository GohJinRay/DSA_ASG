#pragma once

#include <iostream>
#include "LinkedList_Customer.h"
#include "User.h"
#include "Order.h"
#include "Queue.h"


class Customer : public User
{
private:
    LinkedList_Customer orderList;

public:
    Customer();
    Customer(string, string, int, LinkedList_Customer); 
    Order* createOrder(int);
    bool cancelOrder(Queue&, int);
    LinkedList_Customer getOrderList();
    virtual void printDetails();
};
