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
	void updateStatus(AVLTree, Queue&);
	void viewCustInfo(AVLTree, int);
	virtual void printDetails();
};

