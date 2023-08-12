#pragma once

#include <iostream>
#include "LinkedList_Customer.h"
#include "User.h"
#include "Order.h"
#include "Queue.h"
#include "Membership.h"


class Customer : public User
{
private:
    Membership membership;
    LinkedList_Customer orderList;

public:
    Customer();
    Customer(string, string, int, Membership, LinkedList_Customer); 

    Order* createOrder(int);
    bool cancelOrder(Queue&, int);

    Membership& getMembership();
    LinkedList_Customer& getOrderList();

    virtual void printDetails();
};
