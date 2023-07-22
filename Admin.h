#pragma once
#include "User.h"
#include "QueuePtr.h"
#include "Order.h"
using namespace std;

class Admin: public User
{
public:
	Admin();
	Admin(int, string, string, int, bool);
	virtual bool login();
	virtual void printDetails();
	void viewOrders(QueuePtr&);
	bool updateStatus(LinkedList_Customer&, QueuePtr&);
	void viewCustInfo(LinkedList_Customer&, int);
};

