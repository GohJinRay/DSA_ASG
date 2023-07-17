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
	void viewOrders();
	bool updateStatus(); 
	void viewCustInfo(); 
};

