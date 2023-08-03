#pragma once

#include <iostream>
#include "User.h"
#include "Order.h"


class Customer : public User
{
private:

public:
    Customer();
    Customer(string, string, int, bool); 
    Order createOrder(int);
    bool cancelOrder();
    virtual void printDetails();
};
