#pragma once
#include <iostream>
#include <string>
#include "LinkedList_Order.h"
#include "FoodItem.h"
using namespace std;

// Enumeration representing different order status values.
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
	double totalPrice;
	Customer* customer;
	LinkedList_Order foodItemList;

public:
	Order();
	Order(int, string, OrderStatus, double, Customer*, LinkedList_Order);

	bool addFoodItem(FoodItem);
	bool removeFoodItem(int);
	void printOrder();

	void setOrderID(int);
	void setOrderDate(string);
	void setStatus(OrderStatus);
	void setTotalPrice(double);

	int getOrderID();
	string getOrderDate();
	string getStatus();
	double getTotalPrice();
	Customer* getCustomer();
	LinkedList_Order getFoodItemList();
};