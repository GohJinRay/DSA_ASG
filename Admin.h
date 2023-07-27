#pragma once
#include "User.h"
#include "QueuePtr.h"
#include "Order.h"
using namespace std;

class Admin: public User
{
public:
	Admin();
	Admin(string, string, int, bool);
	virtual void printDetails();
	void viewOrders(QueuePtr&);
	bool updateStatus(QueuePtr&);
	void viewCustInfo(LinkedList_Customer&, int);
};

