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


void Menu() 
{
	cout << "Please select an option:" << endl;
	cout << "1. Register" << endl;
	cout << "2. Login" << endl;
	cout << "3. Exit" << endl;
	cout << "-----------------------------------" << endl;
	cout << "Enter your choice (1, 2, or 3): ";
}

int getMenuChoice() 
{
	cout << "-----------------------------------" << endl;
	cout << "            Welcome!" << endl;
	cout << "-----------------------------------" << endl;

	int choice;
	bool validChoice;

	do 
	{
		validChoice = true; //Assume the choice is valid

		Menu();

		if (!(cin >> choice)) 
		{
			validChoice = false; //Not an integer
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignore invalid input
		}

		if (validChoice)
		{
			switch (choice)
			{
				case 1: // register customer
					break;

				case 2:
					// login as customer or admin;
					cout << "2" << endl;
					break;

				case 3:
					cout << endl;
					cout << "-----------------------------------" << endl;
					cout << "Thank you so much. Goodbye!" << endl;
					cout << "-----------------------------------" << endl;
					cout << endl;
					break;

				default:
					cout << endl;
					cout << "-----------------------------------" << endl;
					cout << "Invalid choice. Please enter a valid option (1, 2, or 3)." << endl;
					cout << "-----------------------------------" << endl;
					cout << endl;
			}
		}

		else
		{
			cout << endl;
			cout << "-----------------------------------" << endl;
			cout << "Invalid input. Please enter a valid integer choice (1, 2, or 3)." << endl;
			cout << "-----------------------------------" << endl;
			cout << endl;
		}
	} while (!validChoice || choice != 3);

	return choice;
}

int main()
{
	int choice;

	do
	{
		choice = getMenuChoice();
	} while (choice != 3);

/////////////////////////////////////////////////////////////////////////////////////////////
	QueuePtr newQueue;
	//LinkedList_Customer llC; // added this list
	Customer cust1(1, "John", "123", 123, false); // initialization
	Customer cust2(2, "Mary", "124", 124, false); // initialization
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
	CustomerDict.add(cust1.getFullName(),cust1);
	CustomerDict.add(cust2.getFullName(), cust2);


	// testing admin methods
	Admin admin1(999, "admin", "password", 12345678, true);
	LinkedList_Customer orderL;
	orderL.addOrder(order);
	admin1.viewOrders(orderL);
	admin1.updateStatus(orderL);
	admin1.viewOrders(orderL);
	admin1.viewCustInfo(orderL, 3);

///////////////////////////////////////////////////////////////////////////////////////////////

	return 0;
}

