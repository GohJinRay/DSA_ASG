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

void invalidIntegerInput() {
	cout << endl;
	cout << "Invalid input. Please enter a valid integer." << endl;
	cin.clear(); // Clear error state
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
}



/////
void testing() {



	
}
/////

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

	Category category1(1, "Main Course", mainCourseArray);
	Category category2(2, "Drinks", drinksArray);
	Category category3(3, "Deserts", desertsArray);

	Queue newQueue; //New Queue
	Dictionary usersInfo; //HashTable to store Customer objects
	LinkedList_Customer orderList;
	Admin admin("Admin", "admin", 1231);
	Order* order;
	int orderID = 0; //Start at 0 by default

	cout << "-----------------------------------" << endl;
	cout << "            Welcome!" << endl;
	cout << "-----------------------------------" << endl;

	int choice;
	do
	{
		string username, password;

		// admin case 4
		string catName, foodName;
		int foodID;
		double price;
		FoodItem fooditem;
		SortedArray* selectedArray = nullptr;
		//

		int phoneNum;
		Customer* newCustomer;


		do {
			cout << endl;
			cout << "Please select an option:" << endl;
			cout << "1. Register" << endl;
			cout << "2. Login" << endl;
			cout << "3. Exit" << endl;
			cout << "-----------------------------------" << endl;
			cout << "Enter your choice (1, 2, or 3): ";

			if (!(cin >> choice))
			{
				invalidIntegerInput();
			}
			else
				break;
		} while (true);

		switch (choice)
		{
		case 1: // register customer
			do { // Error handling for username Input
				cout << "Please enter your username: ";
				cin >> username;

				if (usersInfo.get(username) != NULL)
					cout << "Already exists! Please enter a new username!" << endl;
				else
					break;
			} while (true);

			cout << "Please enter your password: ";
			cin >> password;

			do { // Error handling for phoneNum Input
				cout << "Please enter your phone number: ";

				if (!(cin >> phoneNum))
				{
					invalidIntegerInput();
				}
				else
					break;
			} while (true);

			newCustomer = new Customer(username, password, phoneNum, orderList);
			usersInfo.add(username, newCustomer);
			cout << endl << "Registration complete! Please log in to your account to contiune using the services!" << endl;

			break;

		case 2: // login as customer or admin;
			cout << "Please enter your username: ";
			cin >> username;

			cout << "Please enter your password: ";
			cin >> password;

			if (username == admin.getUserName() && password == admin.getPassword()) // Admin login
			{
				int adminChoice1;
				cout << endl << "Login successful. Welcome, Admin!" << endl;
				do
				{
					cout << endl;
					cout << "Please select an option:" << endl;
					cout << "1. View the incoming orders" << endl;
					cout << "2. Update status of the chosen order" << endl;
					cout << "3. View customer information" << endl;
					cout << "4. Create new food item and add to menu" << endl; // Need to check whether a food item with the same order id exists first
					cout << "5. Logout" << endl;
					cout << "-----------------------------------" << endl;
					cout << "Enter your choice (1, 2, 3, 4 or 5): ";

					cin >> adminChoice1;

					switch (adminChoice1)
					{
					case 1: // View the incoming orders
						admin.viewOrders(newQueue);
						break;

					case 2: // Update status of the chosen order

						if (!newQueue.isEmpty()) { // checks if queue is not empty
							admin.viewOrders(newQueue); // display all the incoming orders
						}
						else {
							cout << "No incoming orders." << endl << endl;
							break;
						}

						// updating the status of incoming orders
						int orderIdToUpdate;
						cout << "Enter the Order ID you want to update: ";

						while (!(cin >> orderIdToUpdate)) {
							invalidIntegerInput();
							cout << "Please enter a valid Order ID: ";
						}

						admin.updateStatus(newQueue, orderIdToUpdate);
						break;

					case 3: // View customer information
					
						
						if (!usersInfo.isEmpty()) { 
							usersInfo.printAllOrders(); // print all the orders in customer dictionary
						}
						else {
							cout << "No Customer/Orders in this Dictionary" << endl << endl;
							break;
						}

						int orderIdToView;
						cout << endl;
						cout << "Enter the Order ID to view customer information: ";
						
						while (!(cin >> orderIdToView)) { // error handling
							invalidIntegerInput();
							cout << "Please enter a valid Order ID: ";
						}

						admin.viewCustInfo(usersInfo, orderIdToView);
						break;

					case 4: // Create new food item and add to menu
						int categoryChoice;
						cout << "Select a category:" << endl;
						cout << "1. Main Course" << endl;
						cout << "2. Drinks" << endl;
						cout << "3. Desserts" << endl;
						cout << "Enter your choice: ";


						while (!(cin >> categoryChoice)) { // error handling
							invalidIntegerInput();
							cout << "Please enter a Category ID: ";
						}


						switch (categoryChoice) {
						case 1:
							selectedArray = &mainCourseArray;
							catName = "Main Course";
							break;
						case 2:
							selectedArray = &drinksArray;
							catName = "Drinks";
							break;
						case 3:
							selectedArray = &desertsArray;
							catName= "Desserts";
							break;
						default:
							cout << "Invalid choice. Please select a valid Category ID." << endl;
							break;
						}

						cout << "Enter Food ID: ";

						while (!(cin >> foodID)) { // error handling
							invalidIntegerInput();
							cout << "Please enter a valid Food ID: ";
						}

						if (selectedArray != nullptr) {
							fooditem = selectedArray->search(foodID);
							if (fooditem.getFoodID() != -1) {
								cout << "Duplicate Food ID. Please enter a unique Food ID." << endl;
								break;
							}


							cout << "Enter Price: ";
							cin >> price;

							admin.addFoodItem(*selectedArray, foodID, foodName, price);
						}
					
						break;

					case 5:
						break;

					default:
						invalidIntegerInput();
					}
				} while (adminChoice1 != 5);
			}

			else if (usersInfo.get(username) != NULL)
			{
				Customer* customer = usersInfo.get(username);

				if (customer->getPassword() == password) // User login
				{
					int userChoice1;
					cout << endl << "Login successful. Welcome " << username << "!" << endl;
					do
					{
						cout << endl << "Please select an option:" << endl;
						cout << "1. Browse menu and create new order" << endl;
						cout << "2. Cancel order" << endl;
						cout << "3. View all orders" << endl;
						cout << "4. Logout" << endl;
						cout << "-----------------------------------" << endl;
						cout << "Enter your choice (1, 2, 3, or 4): ";

						cin >> userChoice1;

						switch (userChoice1)
						{
						case 1: // Browse menu and create new order
							cout << endl;
							cout << "------------------- Menu -----------------------" << endl << endl;
							cout << " Food ID |                 Food Name | Price ($)" << endl;
							cout << "------------------------------------------------" << endl;
							category1.getCatArray().print();
							category2.getCatArray().print();
							category3.getCatArray().print();
							do {
								string response;
								cout << endl << "Do you want to make an order? (yes/no): ";
								cin >> response;

								if (response == "yes")
								{
									order = customer->createOrder(orderID);
									
									int userChoice2;

									do {
										int foodIDOption;

										cout << endl << "Please select an option:" << endl;
										cout << "1. Add Food Item" << endl;
										cout << "2. Remove Food Item" << endl;
										cout << "3. View your current cart" << endl;
										cout << "4. Submit Order" << endl;
										cout << "------------------------" << endl;
										cout << "Enter your choice (1, 2, 3 or 4): ";

										cin >> userChoice2;

										switch (userChoice2)
										{
										case 1: // Add Food Item
											cout << endl << "Enter the foodID to add to cart: ";
											if (!(cin >> foodIDOption))
												invalidIntegerInput();

											if (foodIDOption > 0 && foodIDOption <= category1.getCatArray().getSize())
												order->addFoodItem(category1.getFoodItem(foodIDOption));
											else if (foodIDOption >= 100 && foodIDOption < category2.getCatArray().getSize() + 100)
												order->addFoodItem(category2.getFoodItem(foodIDOption));
											else if (foodIDOption >= 200 && foodIDOption < category3.getCatArray().getSize() + 200)
												order->addFoodItem(category3.getFoodItem(foodIDOption));
											else
												cout << "Invalid food ID option! Please choose from the menu!" << endl;

											break;

										case 2: // Remove Food Item
											cout << endl << "Enter the foodID to remove from cart: ";
											if (!(cin >> foodIDOption))
											{
												invalidIntegerInput();
												break;
											}

											if (order->removeFoodItem(foodIDOption) == true) {}

											else
												cout << "Removal of food item from cart is unsuccessful." << endl;
											
											break;

										case 3: // View your current cart
											cout << endl;
											cout << "----------------- Current Cart -----------------" << endl << endl;
											cout << " Food ID |                 Food Name | Price ($)" << endl;
											cout << "------------------------------------------------" << endl;
											order->getFoodItemList().print();

											cout << endl << "Total Price: $" << order->getTotalCartPrice() << endl;

											break;

										case 4: // Submit Order
											newQueue.enqueue(*order);
											orderID++;
											cout << endl << "Order receipt: " << endl;
											order->printOrder();

											cout << endl << "Total Price: $" << order->getTotalCartPrice() << endl;

											break;

										default:
											invalidIntegerInput();
										}
									} while (userChoice2 != 4);
									
									break;
								}
								else if (response == "no")
									break;
								else
									cout << "Invalid response. Please enter \"yes\" or \"no\"." << endl << endl;
									
							} while (true);

							break;

						case 2: // Cancel order
							int cancelOrder_OrderID;
							for (int i = 0; i < customer->getOrderList().orderListGetLength(); i++)
								if (customer->getOrderList().getOrderByIndex(i)->getStatus() == "Not Prepared")
									customer->getOrderList().getOrderByIndex(i)->printOrder();

							cout << "Enter the Order ID to cancel it: ";
							if (!(cin >> cancelOrder_OrderID))
							{
								invalidIntegerInput();
								break;
							}

							if (customer->getOrderList().getOrderByOrderID(cancelOrder_OrderID) != NULL)
							{
								if (customer->cancelOrder(newQueue, cancelOrder_OrderID) == true) {}
							}
							else
								cout << "Invalid Order ID!" << endl;

							break;

						case 3: // View all orders
							customer->getOrderList().orderListPrint();
							break;

						case 4:
							break;

						default:
							invalidIntegerInput();
						}
					} while (userChoice1 != 4);
				}
				else
					cout << "Invalid password. Login failed." << endl;
			}

			else
				cout << "Invalid username or password. Login failed." << endl;

			break;

		case 3:
			cout << endl;
			cout << "-----------------------------------" << endl;
			cout << "Thank you so much. Goodbye!" << endl;
			cout << "-----------------------------------" << endl;
			cout << endl;
			break;

		default:
			invalidIntegerInput();
		}
	} while (choice != 3);

/////////////////////////////////////////////////////////////////////////////////////////////
	//Customer cust1("John", "123", 123, orderList); // initialization
	//Customer cust2("Mary", "124", 124, orderList); // initialization

	//order = cust1.createOrder(orderID);
	//int option = 1;
	//if (option > 0 && option <= category1.getCatArray().getSize())
	//	order->addFoodItem(category1.getFoodItem(option));
	//else if (option >= 100 && option < category2.getCatArray().getSize() + 100)
	//	order->addFoodItem(category2.getFoodItem(option));
	//else if (option >= 200 && option < category3.getCatArray().getSize() + 200)
	//	order->addFoodItem(category3.getFoodItem(option));
	//else
	//	cout << "Invalid option. Please a valid one." << endl;
	//option = 200;
	//if (option > 0 && option <= category1.getCatArray().getSize())
	//	order->addFoodItem(category1.getFoodItem(option));
	//else if (option >= 100 && option < category2.getCatArray().getSize() + 100)
	//	order->addFoodItem(category2.getFoodItem(option));
	//else if (option >= 200 && option < category3.getCatArray().getSize() + 200)
	//	order->addFoodItem(category3.getFoodItem(option));
	//else
	//	cout << "Invalid option. Please a valid one." << endl;
	//newQueue.enqueue(*order); // enqueue the object by dereference the pointer
	//orderID++;
	//cust1.getOrderList().orderListPrint();

	//order = cust1.createOrder(orderID);
	//option = 100;
	//if (option > 0 && option <= category1.getCatArray().getSize())
	//	order->addFoodItem(category1.getFoodItem(option));
	//else if (option >= 100 && option < category2.getCatArray().getSize() + 100)
	//	order->addFoodItem(category2.getFoodItem(option));
	//else if (option >= 200 && option < category3.getCatArray().getSize() + 200)
	//	order->addFoodItem(category3.getFoodItem(option));
	//else
	//	cout << "Invalid option. Please a valid one." << endl;
	//option = 201;
	//if (option > 0 && option <= category1.getCatArray().getSize())
	//	order->addFoodItem(category1.getFoodItem(option));
	//else if (option >= 100 && option < category2.getCatArray().getSize() + 100)
	//	order->addFoodItem(category2.getFoodItem(option));
	//else if (option >= 200 && option < category3.getCatArray().getSize() + 200)
	//	order->addFoodItem(category3.getFoodItem(option));
	//else
	//	cout << "Invalid option. Please a valid one." << endl;
	//newQueue.enqueue(*order);
	//orderID++;
	//cust1.getOrderList().orderListPrint();

	//order = cust2.createOrder(orderID);
	//option = 202;
	//if (option > 0 && option <= category1.getCatArray().getSize())
	//	order->addFoodItem(category1.getFoodItem(option));
	//else if (option >= 100 && option < category2.getCatArray().getSize() + 100)
	//	order->addFoodItem(category2.getFoodItem(option));
	//else if (option >= 200 && option < category3.getCatArray().getSize() + 200)
	//	order->addFoodItem(category3.getFoodItem(option));
	//else
	//	cout << "Invalid option. Please a valid one." << endl;
	//newQueue.enqueue(*order);
	//orderID++;
	//cust2.getOrderList().orderListPrint();

	//cout << "Shows what's in the queue currently" << endl;
	//cout << "-----------------------------------" << endl;
	//newQueue.displayItems();
	//admin.updateStatus(newQueue); // Dequeue upon update
	//newQueue.displayItems();
	//cust1.getOrderList().orderListPrint();

	//cout << "Cancel Order" << endl;
	//cust1.cancelOrder(newQueue, 1); // Cancel orderID 1

	//newQueue.displayItems();
	//cust1.getOrderList().orderListPrint();

///////////////////////////////////////////////////////////////////////////////////////////////

	return 0;
}

