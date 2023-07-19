#pragma once
#include "User.h"
#include <string>
using namespace std;

class Admin: public User
{
public:
	Admin();
	Admin(int, string, string, int, bool);
	virtual bool login();
	virtual void printDetails();
	void viewOrders();
	bool updateStatus(int, string); 
	void viewCustInfo(int); 
};

