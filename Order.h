#pragma once
#include <iostream>
#include <string>
#include "LinkedList_Order.h"
#include "FoodItem.h"
using namespace std;

const int maxFoodItems = 12;

enum OrderStatus 
{ 
	Prepared,
	NotPrepared,
	Paid
};

class Customer;

class Order
{
private:
	int orderID;
	string orderDate;
	OrderStatus status;
	Customer* customer;
	LinkedList_Order foodItemList;

public:
	Order();
	Order(int, string, OrderStatus, Customer*, LinkedList_Order);

	bool addFoodItem(FoodItem);
	bool removeFoodItem(int);
	void printOrder();

	void setOrderID(int);
	void setOrderDate(string);
	void setStatus(OrderStatus);

	int getOrderID();
	string getOrderDate();
	string getStatus();
	Customer* getCustomer();
	LinkedList_Order getFoodItemList();

	double getTotalCartPrice();
};