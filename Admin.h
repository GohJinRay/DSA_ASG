#pragma once
#include "User.h"
#include "Queue.h"
#include "Customer.h"
#include "HashTable.h"
#include "SortedArray.h"
using namespace std;

class Admin: public User
{
public:
	Admin();
	Admin(string, string, int);

	void viewOrders(Queue&);

	void updateStatus(Queue&, int);

	void viewCustInfo(Dictionary&, int);

	bool addFoodItem(SortedArray&, int, string, double);

	virtual void printDetails();
};

