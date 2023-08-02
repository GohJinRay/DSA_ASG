#pragma once
#include "User.h"
#include "Queue.h"
#include "AVLTree.h"
#include "Customer.h"
using namespace std;

class Admin: public User
{
public:
	Admin();
	Admin(string, string, int, bool);
	void viewOrders(Queue&);
	Order updateStatus(Queue&);
	void viewCustInfo(AVLTree, int);
	virtual void printDetails();
};

