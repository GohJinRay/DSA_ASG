#pragma once
#include "User.h"
#include "LinkedList_Customer.h"
#include <string>
using namespace std;

class Customer : public User
{
private:

public:
	Customer();
	Customer(int, string, string, int, bool);
	virtual bool login();
	void viewMenu();
	bool createOrder();
	bool cancelOrder();
};