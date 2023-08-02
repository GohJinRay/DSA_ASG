#pragma once
#include "User.h"
#include "Queue.h"
#include "Order.h"
using namespace std;

class Admin: public User
{
public:
	Admin();
	Admin(string, string, int, bool);
	void viewOrders(Queue&);
	bool updateStatus(Queue&);
	void viewCustInfo(LinkedList_Customer&, int);
	virtual void printDetails();
};

