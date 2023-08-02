#pragma once
#include "User.h"
#include "LinkedList_Customer.h"
using namespace std;

class Customer : public User
{
private:
	LinkedList_Customer orderList;

public:
	Customer();
	Customer(string, string, int, bool, LinkedList_Customer);
	LinkedList_Customer getOrderList();
	Order* createOrder(int);
	bool cancelOrder();
	void viewMenu();
	virtual void printDetails();
};