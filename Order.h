#pragma once
#include <ctime>
#include "Customer.h"
#include "LinkedList_Order.h"
using namespace std;

class Order
{
private:
	int orderID;
	string orderDate;
	string status;
	Customer customer;
	LinkedList_Order foodItemList;

public:
	Order();
	Order(int, string, string, Customer);
	bool addFoodItem(int);
	bool removeFoodItem();

	void setOrderID(int);
	void setOrderDate(string);
	void setStatus(string);

	int getOrderID();
	string getOrderDate();
	string getStatus();
	Customer getCustomer();
	LinkedList_Order getFoodItemList();
};