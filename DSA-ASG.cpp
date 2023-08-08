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
#include "SortedArray.h"
#include "Category.h"
using namespace std;

void invalidInput() {
	cout << endl;
	cout << "-----------------------------------" << endl;
	cout << "Invalid input. Please enter a valid integer choice." << endl;
	cout << "-----------------------------------" << endl;
	cout << endl;
}

bool isANumber(string input)
{
	for (char c : input)
		if (!isdigit(c))
			return false;
	return true;
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
	cout << "2. Update status of the chosen order" << endl;
	cout << "3. View customer information" << endl;
	cout << "4. Exit" << endl;
	cout << "-----------------------------------" << endl;
	cout << "Enter your choice (1, 2, 3 or 4): ";
}

void userMenu() // not done
{
	cout << "Please select an option:" << endl;
	cout << "1. Browse menu" << endl;
	cout << "2. Create a new order" << endl;
	cout << "3. Cancel order" << endl;
	cout << "4. Exit" << endl;
	cout << "-----------------------------------" << endl;
	cout << "Enter your choice (1, 2, 3 or 4): ";
}

///////
void testing() {

	LinkedList_Customer orderList1; // Create order list instance for customer1
	LinkedList_Customer orderList2; // Create order list instance for customer2

	Customer customer1("John Doe", "password", 123456, orderList1);
	Customer customer2("Jane Smith", "secret", 789012, orderList2);

	Dictionary customerDictionary;

	customerDictionary.add(customer1.getUserName(), &customer1);

	customerDictionary.add(customer2.getUserName(), &customer2);

	Order* order1 = customer1.createOrder(0);

	Order* order2 = customer2.createOrder(1);

	Admin admin("Admin Name", "adminpass", 999);

	admin.viewCustInfo(customerDictionary, 0);

}
///////

int main()
{
	SortedArray mainCourseArray;
	FoodItem food1(1, "Hainanese Chicken Rice", 4.50);
	FoodItem food2(2, "Steak", 15.99);
	FoodItem food3(3, "Nasi Lemak", 5.80);
	FoodItem food4(4, "Mee Goreng", 6.99);
	FoodItem food5(5, "Tom Yum Soup", 7.50);

	mainCourseArray.insert(food1);
	mainCourseArray.insert(food2);
	mainCourseArray.insert(food3);
	mainCourseArray.insert(food4);
	mainCourseArray.insert(food5);

	SortedArray drinksArray;
	FoodItem food6(100, "Coca-Cola", 2.00);
	FoodItem food7(101, "Ice Lemon Tea", 2.3);
	FoodItem food8(102, "Bandung", 1.80);
	FoodItem food9(103, "Thai Iced Tea", 2.20);

	drinksArray.insert(food6);
	drinksArray.insert(food7);
	drinksArray.insert(food8);
	drinksArray.insert(food9);

	SortedArray desertsArray;
	FoodItem food10(200, "Chocolate Cake", 5.99);
	FoodItem food11(201, "Ice Cream", 3.50);
	FoodItem food12(202, "Mango Sticky Rice", 5.00);

	desertsArray.insert(food10);
	desertsArray.insert(food11);
	desertsArray.insert(food12);

	Queue newQueue; //New Queue
	LinkedList_Customer orderList;
	Dictionary usersInfo; //HashTable to store Customer objects
	Admin admin("Admin", "hehehehaw", 12345678); //By default, create new admin
	Order* order;
	int orderID = 0; //Start at 0 by default
	////
	testing(); // testing of xxxx
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

				if (usersInfo.get(username) != NULL)
				{
					cout << "Already exists! Please enter a new username!" << endl;
					break;
				}

				cout << "Please enter your password: ";
				cin >> password;

				cout << "Please enter your phone number: ";
				cin >> phoneNum;

				newCustomer = Customer(username, password, phoneNum, orderList);
				usersInfo.add(username, &newCustomer);
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

				else if (usersInfo.get(username) != NULL)
				{
					Customer* customer = usersInfo.get(username);

					if (customer->getPassword() == password)
					{
						cout << "Login successful. Welcome " << username << "!" << endl;
						userMenu();
						break;
					}
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

	//viewMenu(foodItems);
	Category category1(1, "Main Course", mainCourseArray);
	category1.printDetails();

	Category category2(2, "Drinks", drinksArray);
	category2.printDetails();

	Category category3(3, "Deserts", desertsArray);
	category3.printDetails();

	order = cust1.createOrder(orderID);
	int option = 1;
	if (option > 0 && option <= category1.getCatArray().getSize())
		order->addFoodItem(category1.getFoodItem(option));
	else if (option >= 100 && option < category2.getCatArray().getSize() + 100)
		order->addFoodItem(category2.getFoodItem(option));
	else if (option >= 200 && option < category3.getCatArray().getSize() + 200)
		order->addFoodItem(category3.getFoodItem(option));
	else
		cout << "Invalid option. Please a valid one." << endl;
	option = 200;
	if (option > 0 && option <= category1.getCatArray().getSize())
		order->addFoodItem(category1.getFoodItem(option));
	else if (option >= 100 && option < category2.getCatArray().getSize() + 100)
		order->addFoodItem(category2.getFoodItem(option));
	else if (option >= 200 && option < category3.getCatArray().getSize() + 200)
		order->addFoodItem(category3.getFoodItem(option));
	else
		cout << "Invalid option. Please a valid one." << endl;
	newQueue.enqueue(*order); // enqueue the object by dereference the pointer
	orderID++;
	cust1.getOrderList().orderListPrint();

	order = cust1.createOrder(orderID);
	option = 100;
	if (option > 0 && option <= category1.getCatArray().getSize())
		order->addFoodItem(category1.getFoodItem(option));
	else if (option >= 100 && option < category2.getCatArray().getSize() + 100)
		order->addFoodItem(category2.getFoodItem(option));
	else if (option >= 200 && option < category3.getCatArray().getSize() + 200)
		order->addFoodItem(category3.getFoodItem(option));
	else
		cout << "Invalid option. Please a valid one." << endl;
	option = 201;
	if (option > 0 && option <= category1.getCatArray().getSize())
		order->addFoodItem(category1.getFoodItem(option));
	else if (option >= 100 && option < category2.getCatArray().getSize() + 100)
		order->addFoodItem(category2.getFoodItem(option));
	else if (option >= 200 && option < category3.getCatArray().getSize() + 200)
		order->addFoodItem(category3.getFoodItem(option));
	else
		cout << "Invalid option. Please a valid one." << endl;
	newQueue.enqueue(*order);
	orderID++;
	cust1.getOrderList().orderListPrint();

	order = cust2.createOrder(orderID);
	option = 202;
	if (option > 0 && option <= category1.getCatArray().getSize())
		order->addFoodItem(category1.getFoodItem(option));
	else if (option >= 100 && option < category2.getCatArray().getSize() + 100)
		order->addFoodItem(category2.getFoodItem(option));
	else if (option >= 200 && option < category3.getCatArray().getSize() + 200)
		order->addFoodItem(category3.getFoodItem(option));
	else
		cout << "Invalid option. Please a valid one." << endl;
	newQueue.enqueue(*order);
	orderID++;
	cust2.getOrderList().orderListPrint();

	cout << "Shows what's in the queue currently" << endl;
	cout << "-----------------------------------" << endl;
	newQueue.displayItems();
	admin.updateStatus(newQueue); //Dequeue upon update
	newQueue.displayItems();
	cust1.getOrderList().orderListPrint();

	cout << "Cancel Order" << endl;
	cust1.cancelOrder(newQueue, 1); // Cancel orderID 1

	newQueue.displayItems();
	cust1.getOrderList().orderListPrint();

///////////////////////////////////////////////////////////////////////////////////////////////

	return 0;
}

