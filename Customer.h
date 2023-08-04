#pragma once

#include <iostream>
#include "User.h"
#include "Order.h"
#include "Queue.h"


class Customer : public User
{
public:
    Customer();
    Customer(string, string, int); 
    Order createOrder(int);
    bool cancelOrder(Queue, int);
    virtual void printDetails();
};
