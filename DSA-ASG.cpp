// DSA-ASG.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include "Admin.h"
#include "Customer.h"
#include "User.h"
#include "LinkedList_Order.h"
#include "LinkedList_Customer.h"
#include "Order.h"
#include "FoodItem.h"
#include "Queue.h"
#include "HashTable.h"
#include "AVLTree.h"
#include "SortedArray.h"
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

void adminMenu() // not done
{
	cout << "Please select an option:" << endl;
	cout << "1. View the incoming orders" << endl;
	cout << "2. Update status of the next incoming order" << endl;
	cout << "3. View custome information" << endl;
	cout << "4. Exit" << endl;
	cout << "-----------------------------------" << endl;
	cout << "Enter your choice (1, 2, 3 or 4): ";
}

void viewMenu(FoodItem foodItems[])
{
	cout << " Food ID |                 Food Name | Price ($)" << endl;
	cout << "------------------------------------------------" << endl;
	for (int i = 0; i < maxFoodItems; i++)
	{
		cout.width(8);
		cout << foodItems[i].getFoodID();
		cout << " | ";
		cout.width(25);
		cout << foodItems[i].getFoodName();
		cout << " | $";
		cout.precision(2);
		cout << fixed;
		cout << foodItems[i].getPrice();
		cout << endl;
	}
	cout << endl;
}

///////
void testing() {
	SortedArray foodItems;

	FoodItem item1(1, "Burger", 5.99);
	FoodItem item2(2, "Pizza", 8.50);
	FoodItem item3(3, "Salad", 6.25);

	foodItems.insert(&item2);
	foodItems.insert(&item1);
	foodItems.insert(&item3);

	cout << "Food Items: " << endl;
	foodItems.print();
}
///////

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
	LinkedList_Customer orderList;
	Dictionary usersInfo; //HashTable to store Customer objects
	Admin admin("Admin", "hehehehaw", 12345678); //By default, create new admin
	Order* order;
	int orderID = 0; //Start at 0 by default
	////
	testing(); // testing of sorted array
	////
	int choice;
	do
	{
		choice = getMenuChoice();
		string username, password;
		int phoneNum;
		Customer newCustomer;
		const string adminUsername = "Admin", adminPassword = "hehehehaw";


		switch (choice)
		{
			case 1: //Register
				cout << "Please enter your username: "; 
				cin >> username;

				if (username == usersInfo.get(username).getUserName())
				{
					cout << "Already exists! Please enter a new username!" << endl;
					break;
				}

				cout << "Please enter your password: ";
				cin >> password;

				cout << "Please enter your phone number: ";
				cin >> phoneNum;

				newCustomer = Customer(username, password, phoneNum, orderList);
				usersInfo.add(username, newCustomer);
				cout << "Registration complete!" << endl;

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
	Customer cust1("John", "123", 123, orderList); // initialization
	Customer cust2("Mary", "124", 124, orderList); // initialization

	//View Menu
	viewMenu(foodItems);

	order = cust1.createOrder(orderID);
	int option = 1;
	order->addFoodItem(foodItems[option - 1]);
	option = 2;
	order->addFoodItem(foodItems[option - 1]);
	newQueue.enqueue(*order); // enqueue the object by dereference the pointer
	orderID++;
	cust1.getOrderList().orderListPrint();

	order = cust1.createOrder(orderID);
	option = 1;
	order->addFoodItem(foodItems[option - 1]);
	option = 2;
	order->addFoodItem(foodItems[option - 1]);
	newQueue.enqueue(*order);
	orderID++;
	cust1.getOrderList().orderListPrint();

	order = cust2.createOrder(orderID);
	option = 2;
	order->addFoodItem(foodItems[option - 1]);
	newQueue.enqueue(*order);
	orderID++;
	cust2.getOrderList().orderListPrint();

	cout << "Shows what's in the queue currently" << endl;
	cout << "-----------------------------------" << endl;
	newQueue.displayItems();
	admin.updateStatus(newQueue); //Dequeue upon update
	newQueue.displayItems();
	cust1.getOrderList().orderListPrint();

	/*cout << "Cancel Order" << endl;
	cust1.cancelOrder(newQueue, 0);

	newQueue.displayItems();
	cust1.getOrderList().orderListPrint();*/

///////////////////////////////////////////////////////////////////////////////////////////////

	return 0;
}

