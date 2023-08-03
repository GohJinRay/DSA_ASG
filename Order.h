#pragma once
#include <iostream>
#include "LinkedList.h"
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
	LinkedList foodItemList;

public:
	Order();
	Order(int, string, string, Customer*, LinkedList);
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
	LinkedList getFoodItemList();
};