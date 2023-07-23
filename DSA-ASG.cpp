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

void invalidInput() {
	cout << endl;
	cout << "-----------------------------------" << endl;
	cout << "Invalid input. Please enter a valid integer choice." << endl;
	cout << "-----------------------------------" << endl;
	cout << endl;
}

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
					break;

				case 3:
					cout << endl;
					cout << "-----------------------------------" << endl;
					cout << "Thank you so much. Goodbye!" << endl;
					cout << "-----------------------------------" << endl;
					cout << endl;
					break;

				default:
					invalidInput();
			}
		}

		else
		{
			invalidInput();
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
	LinkedList_Customer llc;
	Customer cust1(1, "John", "123", 123, false, llc); // initialization
	Customer cust2(2, "Mary", "124", 124, false, llc); // initialization
	Order* order;

	//LinkedList_Customer orderL; //

	order = cust1.createOrder(1);
	order->addFoodItem(1);
	order->addFoodItem(2);
	newQueue.enqueue(*order);

	//orderL.addOrder(order); //
	order = cust2.createOrder(2);
	order->addFoodItem(2);
	newQueue.enqueue(*order);

	//orderL.addOrder(order); //
	order = cust1.createOrder(3);
	order->addFoodItem(1);
	newQueue.enqueue(*order);

	//orderL.addOrder(order); //

	/*cout << "Shows cust1's order" << endl;
	cust1.getOrderList().OrderListprint();
	cout << "Shows cust2's order" << endl;
	cust2.getOrderList().OrderListprint();*/

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

	admin1.viewOrders(newQueue);
	admin1.updateStatus(newQueue);


///////////////////////////////////////////////////////////////////////////////////////////////

	return 0;
}

