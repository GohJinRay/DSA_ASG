#pragma once

#include "User.h"
#include "AVLTree.h"


class Customer : public User
{
private:
    AVLTree binTree;

public:
    Customer();
    Customer(string, string, int, bool, AVLTree); // change to avl tree
    Order getOrder();
    Order* createOrder(int);
    bool cancelOrder();
    void viewMenu();
    virtual void printDetails();
};
