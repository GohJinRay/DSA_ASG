#pragma once
#include "User.h"
#include "LinkedList_Customer.h"
#include <string>
using namespace std;

class Admin: public User
{
public:
	Admin();
	Admin(int, string, string, int, bool);
	virtual bool login();
	virtual void printDetails();
	void viewOrders(LinkedList_Customer&);
	bool updateStatus(LinkedList_Customer&);
	void viewCustInfo(LinkedList_Customer&, int);
};

