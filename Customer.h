#pragma once
#include "User.h"
#include "Order.h"
#include "LinkedList_Customer.h"
#include <string>
using namespace std;

class Customer : public User
{
private:
	LinkedList_Customer orderList;

public:
	Customer();
	Customer(LinkedList_Customer, int, string, string, int, bool);
	virtual bool login();
	void viewMenu();
	bool createOrder();
	bool cancelOrder();
};