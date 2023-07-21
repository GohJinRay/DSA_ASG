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
#include "HashTable_Customer.h"
using namespace std;

int main()
{
	QueuePtr newQueue;
	//LinkedList_Customer llC; // added this list
	Customer cust1(1, "John", "123", 123, false); // added the list into here
	Customer cust2(2, "Mary", "124", 124, false); // and here
	Order* order;

	order = cust1.createOrder(1);
	order->addFoodItem(1);
	order->addFoodItem(2);
	newQueue.enqueue(*order);

	order = cust2.createOrder(2);
	order->addFoodItem(2);
	newQueue.enqueue(*order);

	order = cust1.createOrder(3);
	order->addFoodItem(1);
	newQueue.enqueue(*order);

	//cout << "Shows cust1's order" << endl;
	//cust1.getOrderList().OrderListprint();
	//cout << "Shows cust2's order" << endl;
	//cust2.getOrderList().OrderListprint();

	//cout << "Shows what's in the queue currently" << endl;
	//newQueue.displayItems();
	//newQueue.dequeue();
	//cout << "Hello" << endl;
	//newQueue.displayItems();


	// testing dictionary
	Dictionary CustomerDict;
	CustomerDict.add(cust1.getName(),cust1);
	CustomerDict.add(cust2.getName(), cust2);


	// testing admin methods
	Admin admin1(999, "admin", "password", 12345678, true);
	//LinkedList_Customer orderL;
	//orderL.addOrder(order);
	//admin1.viewOrders(orderL);
	//admin1.updateStatus(orderL);
	//admin1.viewOrders(orderL);
	//admin1.viewCustInfo(orderL, 3);


	return 0;
}

