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
	Customer(int, string, string, int, bool, LinkedList_Customer);
	virtual bool login();
	virtual void printDetails();
	void viewMenu();
	Order* createOrder(int);
	bool cancelOrder();
	LinkedList_Customer getOrderList();
};