#pragma once
#include <string>
#include <ctime>
#include "Customer.h"
#include "LinkedList_Order.h"
using namespace std;

class Order
{
private:
	int orderID;
	time_t orderDate;
	string status;
	Customer customer;
	LinkedList_Order foodItemList;

public:
	Order();
	Order(int, time_t, string, Customer);
	bool addFoodItem(int);
	bool removeFoodItem();

	void setOrderID(int);
	void setOrderDate(time_t);
	void setStatus(string);

	int getOrderID();
	time_t getOrderDate();
	string getStatus();
	Customer getCustomer();
	LinkedList_Order getFoodItemList();
};