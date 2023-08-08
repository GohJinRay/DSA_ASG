#pragma once
#include "User.h"
#include "Queue.h"
#include "Customer.h"
#include "HashTable.h"
using namespace std;

class Admin: public User
{
public:
	Admin();
	Admin(string, string, int);
	void viewOrders(Queue&);
	void updateStatus(Queue&);
	void viewCustInfo(Dictionary&, int);
	virtual void printDetails();
};

