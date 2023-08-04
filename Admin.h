#pragma once
#include "User.h"
#include "Queue.h"
#include "Customer.h"
using namespace std;

class Admin: public User
{
public:
	Admin();
	Admin(string, string, int);
	void viewOrders(Queue&);
	void updateStatus(Queue&);
	void viewCustInfo(int);
	virtual void printDetails();
};

