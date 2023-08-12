// DSA-ASG.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <regex>
#include <algorithm> // for transform
#include <cctype>    // for tolower
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
#include "Membership.h"
using namespace std;

void invalidIntegerInput() {
	cout << endl;
	cout << "Invalid input. Please enter a valid integer." << endl;
	cin.clear(); // Clear error state
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
}

///////
//void testing() {
//
//	LinkedList_Customer orderList1; // Create order list instance for customer1
//	LinkedList_Customer orderList2; // Create order list instance for customer2
//
//	Customer customer1("John Doe", "password", 123456, orderList1);
//	Customer customer2("Jane Smith", "secret", 789012, orderList2);
//
//	Dictionary customerDictionary;
//
//	customerDictionary.add(customer1.getUserName(), &customer1);
//
//	customerDictionary.add(customer2.getUserName(), &customer2);
//
//	Order* order1 = customer1.createOrder(0);
//
//	Order* order2 = customer2.createOrder(1);
//
//	Admin admin("Admin Name", "adminpass", 999);
//
//	admin.viewCustInfo(customerDictionary);
//}
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

	SortedArray dessertsArray;
	FoodItem food10(200, "Chocolate Cake", 5.99);
	FoodItem food11(201, "Ice Cream", 3.50);
	FoodItem food12(202, "Mango Sticky Rice", 5.00);

	dessertsArray.insert(food10);
	dessertsArray.insert(food11);
	dessertsArray.insert(food12);

	Category category1(1, "Main Course", mainCourseArray);
	Category category2(2, "Drinks", drinksArray);
	Category category3(3, "Desserts", dessertsArray);

	Queue newQueue; //New Queue
	Dictionary usersInfo; //HashTable to store Customer objects
	LinkedList_Customer orderList;
	Admin admin("Admin", "admin", 12345678); //By default, create new admin
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
		int foodID, maxID, filterOption; // filter option for admins to decide if they want to filter or not, maxID for each cat
		string price, filterString; // string price to match regex, filterstring to get what admin wants to filter
		bool foundMatch; // to keep track if there is any matches, for searching/filtering
		FoodItem fooditem;
		SortedArray* selectedArray = nullptr;
		const regex numRegex("^[0-9]+(\\.[0-9]+)?$"); // regular expression for integers and doubles
		const regex stringRegex("^[A-Za-z\\s]+$"); // regular expression for strings (letters and spaces)
		//

		int phoneNum;
		Customer* newCustomer;
		Membership membership(Bronze, 0, 0);


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

				if (usersInfo.get(username) != NULL || username == admin.getUserName())
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


			newCustomer = new Customer(username, password, phoneNum, membership, orderList); // creation of Customer object
			usersInfo.add(username, newCustomer); // adding Customer object to Dictionary
			cout << endl << "Registration complete! Please log in to your account to contiune using the services!" << endl;
			break;


		case 2: // login as customer or admin;
			cout << "Please enter your username: "; // get user input username
			cin >> username;

			cout << "Please enter your password: "; // get user input password
			cin >> password;

			if (username == admin.getUserName() && password == admin.getPassword()) // Admin login //
			{
				int adminChoice1;
				cout << endl << "Login successful. Welcome, Admin!" << endl;
				do
				{
					// Menu for Admin
					cout << endl;
					cout << "Please select an option:" << endl;
					cout << "1. View the incoming orders" << endl;
					cout << "2. Update status of the chosen order" << endl;
					cout << "3. View customer information" << endl;
					cout << "4. Create new food item and add to menu" << endl; 
					cout << "5. Logout" << endl;
					cout << "-----------------------------------" << endl;
					cout << "Enter your choice (1, 2, 3, 4 or 5): ";

					cin >> adminChoice1;

					switch (adminChoice1)
					{
					case 1: // View the incoming orders
						cout << endl << endl;
						admin.viewOrders(newQueue);
						break;


					case 2: // Update status of the chosen order
						if (newQueue.isEmpty()) {
							cout << endl << "No incoming orders." << endl;
							break;
						}
						admin.viewOrders(newQueue); // display all the incoming orders

						// updating the status of incoming orders
						int orderIdToUpdate;
						cout << endl << "Enter the Order ID you want to update: ";

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
							cout << endl << "No Customer/Orders in this Dictionary" << endl;
							break;
						}

						int orderIdToView;
						cout << endl << "Enter the Order ID to view customer information: ";
						
						while (!(cin >> orderIdToView) || orderIdToView < 0) { // error handling
							if (!cin) {
								invalidIntegerInput();
								cout << "Please enter a valid Order ID: ";
							}
							else {
								cout << "Please enter a valid non-negative Order ID: ";
							}
						}
						admin.viewCustInfo(usersInfo, orderIdToView);
						break;


					case 4: // Create new food item and add to menu
						int categoryChoice;
						while (true) {

							// Menu
							cout << "Select a category:" << endl;
							cout << "1. Main Course" << endl;
							cout << "2. Drinks" << endl;
							cout << "3. Desserts" << endl;
							cout << "Enter your choice: ";

							if (!(cin >> categoryChoice)) { // error handling
								invalidIntegerInput();
							}
							else {								
								switch (categoryChoice) {
								case 1:
									selectedArray = &category1.getCatArray();
									catName = "Main Course";
									selectedArray->print();
									maxID = 99;
									break;
								case 2:
									selectedArray = &category2.getCatArray();
									catName = "Beverages";
									selectedArray->print();
									maxID = 200;
									break;
								case 3:
									selectedArray = &category3.getCatArray();
									catName = "Desert";
									selectedArray->print();
									maxID = 300;
									break;
								default:
									cout << "Invalid choice. Please select a valid Category ID." << endl << endl;
									continue; // Go back to the beginning of the loop
								}
								break; // Exit the loop if a valid choice was made
							}
						}

						while (true) { // filtering if admin wants to. 
							// e.g. if admin enter chic, everything with foodname with c h i c in them will come out

							cout << "Do you want to filter? (1 for yes) (2 for no): ";
							cin >> filterOption;

							if (filterOption == 2) {
								break;
							}
							else if (filterOption == 1) {

								// filtering/searching by name
								while (true) {
									foundMatch = false;
									cout << "Enter Food Name to filter or type 'exit' to go exit: ";
									cin >> filterString;

									if (!regex_match(filterString, stringRegex)) { // checks if it contain letters and spacing only
										cout << "Invalid input. Please enter a valid Food Name (letters & spaces only)." << endl;
										foundMatch = true; // prevent it to print
									}
									if (filterString == "exit") { // to exiting the search
										break;
									}
									else {
										transform(filterString.begin(), filterString.end(), filterString.begin(), ::tolower); // changing input to lowercase
										for (int i = 0; i < selectedArray->getSize(); i++) {
											foodName = selectedArray->searchByIndex(i).getFoodName();

											// ensure that it will not be case sensitive
											transform(foodName.begin(), foodName.end(), foodName.begin(), ::tolower); // changing food name to lowercase
											if (foodName.find(filterString) != string::npos) {
												selectedArray->searchByIndex(i).printFoodItem();
												foundMatch = true;
											}
										}
										if (!foundMatch) {
											cout << "No food name matches the search string: " << filterString << endl;
										}
									}
								}
							}
							else {
								invalidIntegerInput();
							}
						};

						// sort price by ascending order
						while (true) {
							cout << "Do you want to sort the Menu by price in ascending order? (1 for yes, 2 for no): ";
							cin >> filterOption;

							if (filterOption == 1) {
								selectedArray->sortPriceAscending();
								cout << endl << "Filtered results sorted by price in ascending order:" << endl;
								selectedArray->print(); // Print the sorted results
								cout << endl;
							}
							else if (filterOption == 2) {
								break;
							}
							else {
								invalidIntegerInput();
							}
						}
						
						// error handling for Food ID
						while (true) {
							cout << "Enter Food ID: ";
							if (cin >> foodID) {
								if (foodID <= 0 || foodID > maxID) { // ensure its a positive foodID
									cout << "Please enter a valid Food ID!" << endl << endl; 
									cin.ignore();
								}
								else if (selectedArray != nullptr) { // checks for duplicates
									fooditem = selectedArray->searchByFoodID(foodID);
									if (fooditem.getFoodID() != -1) {
										cout << "Duplicate Food ID. Please enter a unique Food ID." << endl; 
										cin.ignore();
									}
									else {
										break;
									}
								}
							}
							else {
								invalidIntegerInput();
							}
						}

						// checks for Food ID duplicates
						if (selectedArray != nullptr) { // ensure select array contains something
							// do while loop
							do {
								cout << "Enter Food Name: ";
								cin.ignore();
								getline(cin, foodName); // Read a full line of input

								// checks if its a valid string
								if (!regex_match(foodName, stringRegex)) {
									cout << "Invalid input. Please enter a valid Food Name (letters & spaces only)." << endl; // only accept more than 1 character
									foodName.clear();
								}

								else if (selectedArray->searchByFoodName(foodName).getFoodID() != -1) { // checks for duplicate foodName via foodID
									cout << "Duplicate Food Name found. Please enter a unique Food Name." << endl;
									foodName.clear();
								}
								else {
									break;
								}
							} while (true);

							do {
								cout << "Enter Price: ";
								cin >> price;

								// checks to see if its a valid integer/double
								if (!regex_match(price, numRegex)) {
									cout << "Price is not a valid number. Please try again." << endl;
								}
								else
									break;
							} while (true);

							double fPrice = stod(price); // final price being converted to double;

							// changing it to 2 decimal place
							ostringstream oss;
							oss << fixed << setprecision(2) << fPrice;

							
							cout << endl << "Food Item of Name: " << foodName << " has been added to Category: " << catName << endl;
							cout << "Updated " << catName << " Menu: " << endl;
							admin.createNewFoodItem(foodID, foodName, fPrice, *selectedArray); // creating new fooditem and adding it into the selected array
						}
						else {
							cout << "Array is empty" << endl;
						}
						break;


					case 5: // log out
						cout << endl << "Logging out..." << endl;
						cout << "Logged out sucessfully!" << endl;
						cout << "-----------------------------------" << endl;
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
					bool unpaidOrdersExist = false;
					int userChoice1;
					cout << endl << "Login successful. Welcome " << username << "!" << endl;
					do
					{
						cout << endl << "Please select an option:" << endl;
						cout << "1. Browse menu and create new order" << endl;
						cout << "2. Cancel order" << endl;
						cout << "3. View all orders" << endl;
						cout << "4. Payment" << endl;
						cout << "5. Logout" << endl;
						cout << "-----------------------------------" << endl;
						cout << "Enter your choice (1, 2, 3, 4 or 5): ";

						cin >> userChoice1;

						double totalAmountToPay = 0.0;
						string paymentInput;
						bool case2Flag = false;
						bool case4Flag = false;

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
									
									bool case1_4Flag = false;
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
												order->addFoodItem(category1.getFoodItemByFoodID(foodIDOption));
											else if (foodIDOption >= 100 && foodIDOption < category2.getCatArray().getSize() + 100)
												order->addFoodItem(category2.getFoodItemByFoodID(foodIDOption));
											else if (foodIDOption >= 200 && foodIDOption < category3.getCatArray().getSize() + 200)
												order->addFoodItem(category3.getFoodItemByFoodID(foodIDOption));
											else
												cout << "Invalid food ID option! Please choose from the menu!" << endl;

											break;

										case 2: // Remove Food Item
											if (order->getFoodItemList().isEmpty())
											{
												cout << endl << "Your cart is empty!" << endl;
												break;
											}
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

											cout << endl << "Total Price: $" << order->getTotalPrice() << endl;

											break;

										case 4: // Submit Order
											if (order->getFoodItemList().isEmpty())
											{
												cout << endl << "Your cart is empty!" << endl;
												break;
											}
											cout << "You have " << customer->getMembership().getCurrentLoyaltyPoints() << " points currently." << endl;
											cout << "Do you want to redeem your loyalty points? Enter \"yes\" to reedeem or any key to exit: ";
											cin >> response;
											if (response == "yes")
												customer->getMembership().redeemLoyaltyPoints(category1, category2, category3, *order);

											newQueue.enqueue(*order);
											orderID++;
											cout << endl << "Order receipt: " << endl;
											order->printOrder();
											case1_4Flag = true;

											break;

										default:
											invalidIntegerInput();
										}
									} while (userChoice2 != 4 || case1_4Flag == false);
									
									break;
								}
								else if (response == "no")
									break;
								else
									cout << "Invalid response. Please enter \"yes\" or \"no\"." << endl;
									
							} while (true);

							break;

						case 2: // Cancel order
							int cancelOrder_OrderID;
							for (int i = 0; i < customer->getOrderList().orderListGetLength(); i++)
								if (customer->getOrderList().getOrderByIndex(i)->getStatus() == "Not Prepared")
								{
									customer->getOrderList().getOrderByIndex(i)->printOrder();
									case2Flag = true;
								}
							if (case2Flag == false)
							{
								cout << endl << "You have no orders to cancel!" << endl;
								break;
							}
									
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
							if (customer->getOrderList().orderListIsEmpty())
							{
								cout << endl << "You have no orders!" << endl;
								break;
							}
							customer->getOrderList().orderListPrint();
							break;

						case 4: // Payment
							for (int i = 0; i < customer->getOrderList().orderListGetLength(); i++)
								if (customer->getOrderList().getOrderByIndex(i)->getStatus() == "Prepared")
								{
									case4Flag = true;
									customer->getOrderList().getOrderByIndex(i)->printOrder();
									totalAmountToPay += customer->getOrderList().getOrderByIndex(i)->getTotalPrice();
								}
							if (case4Flag == false)
							{
								cout << endl << "No orders to pay!" << endl;
								break;
							}

							cout << endl <<  "Total amount to pay: " << totalAmountToPay << endl;
							cout << "Enter \"yes\" to confirm your payment or any key to exit: ";
							cin >> paymentInput;

							if (paymentInput == "yes")
							{
								customer->getMembership().addLoyaltyPoints(totalAmountToPay);
								for (int i = 0; i < customer->getOrderList().orderListGetLength(); i++)
									if (customer->getOrderList().getOrderByIndex(i)->getStatus() == "Prepared")
									{
										customer->getOrderList().getOrderByIndex(i)->setStatus(Paid);
									}
								cout << endl << "Payment successful!" << endl;
								unpaidOrdersExist = false;
								customer->getMembership().printMembership();
							}

							break;

						case 5:
							for (int i = 0; i < customer->getOrderList().orderListGetLength(); i++) {
								if (customer->getOrderList().getOrderByIndex(i)->getStatus() == "Prepared") {
									unpaidOrdersExist = true;
									break; // No need to continue checking if one unpaid order is found
								}
							}
							if (unpaidOrdersExist) {
								cout << "You have unpaid orders. You cannot log out until all orders are paid." << endl;
							}
							break;

						default:
							invalidIntegerInput();
						}
					} while (userChoice1 != 5 || unpaidOrdersExist);
				}
				else
					cout << "Invalid password. Login failed." << endl << endl;
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

	return 0;
}

