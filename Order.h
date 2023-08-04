#pragma once
#include <iostream>
#include <string>
#include "LinkedList_Order.h"
#include "FoodItem.h"
using namespace std;

const int maxFoodItems = 12;

class Customer;

class Order
{
private:
	int orderID;
	string orderDate;
	string status;
	Customer* customer;
	LinkedList_Order foodItemList;

public:
	Order();
	Order(int, string, string, Customer*, LinkedList_Order);
	bool addFoodItem(FoodItem, int option);
	bool removeFoodItem(int);
	void printOrder();

	void setOrderID(int);
	void setOrderDate(string);
	void setStatus(string);

	int getOrderID();
	string getOrderDate();
	string getStatus();
	Customer* getCustomer();
	LinkedList_Order getFoodItemList();
};