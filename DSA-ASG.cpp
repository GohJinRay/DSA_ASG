// DSA-ASG.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <string>
#include "Admin.h"
#include "Customer.h"
#include "User.h"
#include "LinkedList_Customer.h"
#include "LinkedList_Order.h"
#include "Order.h"
#include "FoodItem.h"
#include "QueuePtr.h"
using namespace std;

int main()
{
	QueuePtr newQueue;
	LinkedList_Customer llC; // added this list
	Customer cust1(llC, 1, "a", "123", 123, false); // added the list into here
	Customer cust2(llC, 2, "b", "124", 124, false); // and here
	Order& orderList1 = cust1.createOrder();
	Order& orderList2 = cust2.createOrder();
	Order& orderList3 = cust1.createOrder();
	orderList1.addFoodItem(1);
	orderList1.addFoodItem(2);
	orderList2.addFoodItem(2);
	orderList3.addFoodItem(1);
	cout << "Shows cust1's order" << endl;
	cust1.getOrderList().OrderListprint();
	cout << "Shows cust2's order" << endl;
	cust2.getOrderList().OrderListprint();
	newQueue.enqueue(&orderList1);
	newQueue.enqueue(&orderList2);
	cout << "Shows what's in the queue currently" << endl;
	newQueue.displayItems();
	return 0;
}

