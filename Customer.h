#pragma once
#include "User.h"
#include "LinkedList_Customer.h"
#include <string>
using namespace std;

class Customer : public User
{
private:
	LinkedList_Customer orderList;

public:
	Customer();
	Customer(int, string, string, int, bool);
	virtual bool login();
	virtual void printDetails();
	void viewMenu();
	Order& createOrder();
	bool cancelOrder();
	LinkedList_Customer getOrderList();
};