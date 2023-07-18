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
	LinkedList_Order foodItemList;

public:
	Order();
	Order(int, time_t, string, LinkedList_Order);
	bool addFoodItem();
	bool removeFoodItem();

	void setOrderID(int);
	void setOrderDate(time_t);
	void setStatus(string);

	int getOrderID();
	time_t getOrderDate();
	string getStatus();
	LinkedList_Order getFoodItemList();
};