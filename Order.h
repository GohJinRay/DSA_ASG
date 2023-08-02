#pragma once
#include "Customer.h"
#include "LinkedList.h"
using namespace std;

class Order
{
private:
	int orderID;
	string orderDate;
	string status;
	Customer* customer;
	LinkedList foodItemList;

public:
	Order();
	Order(int, string, string, Customer*);
	bool addFoodItem(int);
	bool removeFoodItem(int);

	void setOrderID(int);
	void setOrderDate(string);
	void setStatus(string);

	int getOrderID();
	string getOrderDate();
	string getStatus();
	Customer* getCustomer();
	LinkedList getFoodItemList();
};