// DSA-ASG.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include "Admin.h"
#include "Customer.h"
#include "User.h"
#include "LinkedList.h"
#include "Order.h"
#include "FoodItem.h"
#include "Queue.h"
#include "HashTable_Customer.h"
#include "AVLTree.h"
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

				case 2: // login as customer or admin;
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
	} while (!validChoice);

	return choice;
}

int main()
{
	
	FoodItem foodItems[maxFoodItems] = {
		//Main course
		{1, "Hainanese Chicken Rice", 4.50},
		{2, "Steak", 15.99},
		{3, "Nasi Lemak", 5.80},
		{4, "Mee Goreng", 6.99},
		{5, "Tom Yum Soup", 7.50},

		//Drinks
		{6, "Coca-Cola", 2.00},
		{7, "Ice Lemon Tea", 2.30},
		{8, "Bandung", 1.80},
		{9, "Thai Iced Tea", 2.20},

		//Deserts 
		{10, "Chocolate Cake", 5.99},
		{11, "Ice Cream", 3.50},
		{12, "Mango Sticky Rice", 5.00}
	};

	Queue newQueue; //New Queue
	Dictionary usersInfo; //HashTable to store Customer objects
	Admin admin("Admin", "hehehehaw", 12345678, true); //By default, create new admin
	Order order;
	int orderID = 0; //Start at 0 by default
	AVLTree avlTree;

	int choice;
	do
	{
		choice = getMenuChoice();

		string username, password;
		const string adminUsername = "Admin", adminPassword = "hehehehaw";
		Customer newCustomer;

		switch (choice)
		{
			case 1: //Register
				int phoneNum;
				bool isAdmin;
				cout << "Please enter your username: "; 
				cin >> username;

				cout << "Please enter your password: ";
				cin >> password;

				cout << "Please enter your phone number: ";
				cin >> phoneNum;

				if (username == usersInfo.get(username).getUserName())
				{
					cout << "Already exists! Please enter a new username!" << endl;
					break;
				}
				//newCustomer = Customer(username, password, phoneNum, false, order);
				usersInfo.add(username, newCustomer);
				cout << "Registeration complete!" << endl;

				break;

			case 2: //Login
				cout << "Please enter your username: ";
				cin >> username;

				cout << "Please enter your password: ";
				cin >> password;

				if (username == adminUsername && password == adminPassword) //Admin login
				{
					cout << "Login successful. Welcome, Admin!" << endl;
					break;
				}

				if (username == usersInfo.get(username).getUserName() && password == usersInfo.get(username).getPassword()) //Customer login
				{
					cout << "Login successful. Welcome " << username << "!" << endl;
					break;
				}

				else
				{
					cout << "Invalid username or password. Login failed." << endl;
				}
				break;
		}
	} while (choice != 3);

/////////////////////////////////////////////////////////////////////////////////////////////
	Customer cust1("John", "123", 123, false); // initialization
	Customer cust2("Mary", "124", 124, false); // initialization

	order = cust1.createOrder(orderID);
	int option = 1;
	order.addFoodItem(foodItems[option - 1], option);
	option = 2;
	order.addFoodItem(foodItems[option - 1], option);
	newQueue.enqueue(order);
	orderID++;

	order = cust2.createOrder(orderID);
	option = 2;
	order.addFoodItem(foodItems[option - 1], option);
	newQueue.enqueue(order);
	orderID++;

	cout << "Shows what's in the queue currently" << endl;
	cout << "-----------------------------------" << endl;
	newQueue.displayItems();
	order = admin.updateStatus(newQueue); //Dequeue upon update
	avlTree.insert(order);
	newQueue.displayItems();
	avlTree.printInorder();

///////////////////////////////////////////////////////////////////////////////////////////////

	return 0;
}

