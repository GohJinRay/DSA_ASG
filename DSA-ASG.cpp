/*
Group number: 9
Team member's name: Darrel Neo Yuzhe and Goh Jin Ray
Respective student's id: S10241995 and S10247558
*/

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

// display error message when invalid interger input
void invalidIntegerInput() {
	cout << endl;
	cout << "Invalid input. Please enter a valid integer." << endl;
	cin.clear(); // Clear error state
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
}

int main()
{
	// Initializing start //
	SortedArray mainCourseArray; // Sorted array for main course food items
	FoodItem food1(1, "Hainanese Chicken Rice", 4.50);
	FoodItem food2(2, "Steak", 15.99);
	FoodItem food3(3, "Nasi Lemak", 5.80);
	FoodItem food4(4, "Mee Goreng", 6.99);
	FoodItem food5(5, "Tom Yum Soup", 7.50);

	// Adding of fooditem to main course array
	mainCourseArray.insert(food1);
	mainCourseArray.insert(food2);
	mainCourseArray.insert(food3);
	mainCourseArray.insert(food4);
	mainCourseArray.insert(food5);

	SortedArray drinksArray; // Sorted array for drinks food items
	FoodItem food6(100, "Coca-Cola", 2.00);
	FoodItem food7(101, "Ice Lemon Tea", 2.3);
	FoodItem food8(102, "Bandung", 1.80);
	FoodItem food9(103, "Thai Iced Tea", 2.20);

	// Adding of fooditem to drinks array
	drinksArray.insert(food6);
	drinksArray.insert(food7);
	drinksArray.insert(food8);
	drinksArray.insert(food9);


	SortedArray dessertsArray; // Sorted array for desserts food items
	FoodItem food10(200, "Chocolate Cake", 5.99);
	FoodItem food11(201, "Ice Cream", 3.50);
	FoodItem food12(202, "Mango Sticky Rice", 5.00);

	// Adding of fooditem to desserts array
	dessertsArray.insert(food10);
	dessertsArray.insert(food11);
	dessertsArray.insert(food12);

	Category category1(1, "Main Course", mainCourseArray); // Category for main course
	Category category2(2, "Drinks", drinksArray);		   // Category for drinks
	Category category3(3, "Desserts", dessertsArray);	   // Category for desserts

	Queue newQueue;							 //New Queue
	Dictionary usersInfo;					 //HashTable to store Customer objects
	LinkedList_Customer orderList;			 // Linked list to track orders
	Admin admin("Admin", "admin", 12345678); //By default, create new admin
	Order* order;
	int orderID = 0; //Start at 0 by default, initial order ID
	// Initializing end //


	// Welcome Menu
	cout << "-----------------------------------" << endl;
	cout << "            Welcome!" << endl;
	cout << "-----------------------------------" << endl;

	int choice;
	do
	{

		string username, password; // for getting user input
		int phoneNum; // for customer input
		// admin case 4 //
		string catName, foodName;
		int foodID, maxID, minID, filterOption; // filter option for admins to decide if they want to filter or not, maxID for each cat
		string price, filterString; // string price to match regex, filterstring to get what admin wants to filter
		bool foundMatch; // to keep track if there is any matches, for searching/filtering
		FoodItem fooditem;
		SortedArray* selectedArray = nullptr;
		const regex numRegex("^[0-9]+(\\.[0-9]+)?$"); // regular expression for integers and doubles
		const regex stringRegex("^[A-Za-z\\s]+$"); // regular expression for strings (letters and spaces)
		// // // // // //

		Customer* newCustomer;
		Membership membership(Bronze, 0, 0); // All the new customers will start at this level


		do {
			// Part of Welcome Menu
			cout << endl;
			cout << "Please select an option:" << endl;
			cout << "1. Register" << endl;
			cout << "2. Login" << endl;
			cout << "3. Exit" << endl;
			cout << "-----------------------------------" << endl;
			cout << "Enter your choice (1, 2, or 3): ";

			if (!(cin >> choice))
			{
				invalidIntegerInput(); // error handling
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

				if (usersInfo.getCustomerByKey(username) != NULL || username == admin.getUserName()) // ensure there is no duplicate username
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
						cout << endl << "Enter the Order ID to view customer information: "; // get admin input for order ID
						
						while (!(cin >> orderIdToView) || orderIdToView < 0) { // ensure that OrderID is valid
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

							// Food Menu
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
									// Set the selected category to Main Course
									selectedArray = &category1.getCatArray();
									catName = category1.getCatName();
									selectedArray->print();
									minID = 0; // ensure user cant go under
									maxID = 99; // or above the category range
									break;
								case 2:
									// Set the selected category to Drinks
									selectedArray = &category2.getCatArray();
									catName = category2.getCatName();
									selectedArray->print();
									minID = 100; // ensure user cant go under
									maxID = 199; // or above the category range
									break;
								case 3:
									// Set the selected category to Desserts
									selectedArray = &category3.getCatArray();
									catName = category3.getCatName();
									selectedArray->print();
									minID = 200; // ensure user cant go under
									maxID = 299; // or above the category range
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

							cout << "Do you want to filter? (1 for yes) (2 for no): "; // get admin input if they want to filter or not
							cin >> filterOption;

							if (filterOption == 2) { // exits the loop
								break;
							}
							else if (filterOption == 1) {

								// filtering/searching by name
								while (true) {
									foundMatch = false;
									cout << "Enter Food Name to filter or type 'exit' to go exit: "; // get admin input if they want to continue filtering or not
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
												selectedArray->searchByIndex(i).printFoodItem(); // found fooditem that match the filter string
												foundMatch = true;
											}
										}
										if (!foundMatch) {
											cout << "No food name matches the search string: " << filterString << endl; // if there is food name that match the filter string
										}
									}
								}
							}
							else {
								invalidIntegerInput(); // error handling
							}
						};

						// sort price by ascending order
						while (true) {
							cout << "Do you want to sort the Menu by price in ascending order? (1 for yes, 2 for no): "; // get admin input if they want to sort the menu by price in ascending order
							cin >> filterOption;

							if (filterOption == 1) { 
								selectedArray->sortPriceAscending(); // calls the sorting function
								cout << endl << "Filtered results sorted by price in ascending order:" << endl;
								selectedArray->print(); // Print the sorted results
								cout << endl;
								break;
							}
							else if (filterOption == 2) { // exits the loop
								break;
							}
							else {
								invalidIntegerInput(); // error handling
							}
						}
						
						// error handling for Food ID
						while (true) {
							cout << "Enter Food ID: ";
							if (cin >> foodID) {
								if (foodID <= 0 || foodID > maxID || foodID < minID) { // ensure its a positive foodID and in range
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
								invalidIntegerInput(); // error handling
							}
						}

						// checks for Food ID duplicates
						if (selectedArray != nullptr) { // ensure select array contains something
							// do while loop
							cin.ignore(numeric_limits<streamsize>::max(), '\n'); // error handling
							do {
								cout << "Enter Food Name: ";
								getline(cin, foodName); // Read a full line of input

								// checks if its a valid string
								if (selectedArray->searchByFoodName(foodName).getFoodID() != -1) { // checks for duplicate foodName 
									cout << "Duplicate Food Name found. Please enter a unique Food Name." << endl;
									cin.clear();
								}

								else if (!regex_match(foodName, stringRegex)) { // ensure its a valid name by matching with the string regex
									cout << "Invalid input. Please enter a valid Food Name (letters & spaces only)." << endl; 
									cin.clear();
								}

								else {
									break;
								}
							} while (true);

							do {
								cout << "Enter Price: "; // get admin input for the price of new food item
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
						break;


					default:
						invalidIntegerInput();
					}
				} while (adminChoice1 != 5);
			}

			// Check if the user is a customer
			else if (usersInfo.getCustomerByKey(username) != NULL)
			{
				// Get the customer object based on the username
				Customer* customer = usersInfo.getCustomerByKey(username);

				// Check if the entered password is correct
				if (customer->getPassword() == password) 
				{
					bool unpaidOrdersExist = false; // Flag to track if there are unpaid orders
					int userChoice1;
					cout << endl << "Login successful. Welcome " << username << "!" << endl;
					
					// Main user interaction loop
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

						double totalAmountToPay = 0.0; // To track the total payment amount
						string paymentInput;
						bool case2Flag = false; // Flag to indicate if there are cancellable orders
						bool case4Flag = false; // Flag to indicate if there are orders eligible for payment

						switch (userChoice1)
						{
						case 1: // Browse menu and create new order
							cout << endl;
							cout << "------------------- Menu -----------------------" << endl << endl;
							cout << " Food ID |                 Food Name | Price ($)" << endl;
							cout << "------------------------------------------------" << endl;

							// Display food items from all categories
							category1.getCatArray().print(); // Main Course
							category2.getCatArray().print(); // Drinks
							category3.getCatArray().print(); // Desserts

							// Filtering/Searching
							while (true) { // Loop for filtering if customer wants to. 

								cout << endl << "Do you want to filter? (1 for yes) (2 for no): ";
								cin >> filterOption;

								if (filterOption == 2) { // Exits the loop if no filtering is desired
									break;
								}
								else if (filterOption == 1) {

									// Filtering/searching by name
									while (true) {
										foundMatch = false;
										cout << "Enter Food Name to filter or type 'exit' to go exit: ";
										cin >> filterString;

										if (!regex_match(filterString, stringRegex)) { // Checks if it contain letters and spacing only
											cout << "Invalid input. Please enter a valid Food Name (letters & spaces only)." << endl;
											foundMatch = true; // Prevent it to print
										}
										if (filterString == "exit") { // Exit the search
											break;
										}

										else {
											transform(filterString.begin(), filterString.end(), filterString.begin(), ::tolower); // Convert input to lowercase

											// For Main Course
											for (int i = 0; i < category1.getCatArray().getSize(); i++) {
												foodName = category1.getCatArray().searchByIndex(i).getFoodName();

												// Ensure that it is not case sensitive
												transform(foodName.begin(), foodName.end(), foodName.begin(), ::tolower); // Convert food name to lowercase
												if (foodName.find(filterString) != string::npos) {
													category1.getCatArray().searchByIndex(i).printFoodItem();
													foundMatch = true;
												}
											}

											// For Drinks
											for (int i = 0; i < category2.getCatArray().getSize(); i++) {
												foodName = category2.getCatArray().searchByIndex(i).getFoodName();

												// Ensure that it is not case sensitive
												transform(foodName.begin(), foodName.end(), foodName.begin(), ::tolower); // Convert food name to lowercase
												if (foodName.find(filterString) != string::npos) {
													category2.getCatArray().searchByIndex(i).printFoodItem();
													foundMatch = true;
												}
											}

											// For Desserts
											for (int i = 0; i < category3.getCatArray().getSize(); i++) {
												foodName = category3.getCatArray().searchByIndex(i).getFoodName();

												// ensure that it is not case sensitive
												transform(foodName.begin(), foodName.end(), foodName.begin(), ::tolower); // Convert food name to lowercase
												if (foodName.find(filterString) != string::npos) {
													category3.getCatArray().searchByIndex(i).printFoodItem();
													foundMatch = true;
												}
											}
											if (!foundMatch) {
												cout << "No food name matches the search string: " << filterString << endl;  // If there is no match
											}
										}
									}
								}
								else {
									invalidIntegerInput(); // Error handling for invalid input
								}
							};

							// Sort price by ascending order
							while (true) {
								cout << "Do you want to sort the Menu by price and category in ascending order? (1 for yes, 2 for no): ";
								cin >> filterOption;

								if (filterOption == 1) {
									// Sort the food items in each category by price in ascending order
									category1.getCatArray().sortPriceAscending();
									category2.getCatArray().sortPriceAscending();
									category3.getCatArray().sortPriceAscending();

									// Display formatted results with sorted prices
									cout << endl << "Filtered results sorted by price in ascending order:" << endl;

									category1.printDetails();
									category2.printDetails();
									category3.printDetails();	
									cout << endl;

									break; // Exit the loop after sorting and displaying
								}
								else if (filterOption == 2) { 
									break; // Exits the loop without sorting
								}
								else {
									invalidIntegerInput(); // Handle invalid input for menu choice
								}
							}

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

											// Determine category and add food item to order
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

											// Attempt to remove food item from cart
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
											cout << endl << "You have " << customer->getMembership().getCurrentLoyaltyPoints() << " points currently." << endl;
											cout << "Do you want to redeem your loyalty points? Enter \"yes\" to reedeem or any key to exit: ";
											cin >> response;
											if (response == "yes")
												customer->getMembership().redeemLoyaltyPoints(category1, category2, category3, *order);

											// Enqueue the order and update orderID
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

							// Loop through customer's orders to find orders that are "Not Prepared"
							for (int i = 0; i < customer->getOrderList().orderListGetLength(); i++)
								if (customer->getOrderList().getOrderByIndex(i)->getStatus() == "Not Prepared")
								{
									customer->getOrderList().getOrderByIndex(i)->printOrder();
									case2Flag = true;
								}

							// If no "Not Prepared" orders found, inform the user and exit
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

							// Check if the entered Order ID exists in the customer's order list
							if (customer->getOrderList().getOrderByOrderID(cancelOrder_OrderID) != NULL)
							{
								// Attempt to cancel the order using the cancelOrder method
								if (customer->cancelOrder(newQueue, cancelOrder_OrderID) == true) {}
							}
							else
								cout << "Invalid Order ID!" << endl;

							break;

						case 3: // View all orders
							// Check if the customer has any orders
							if (customer->getOrderList().orderListIsEmpty())
							{
								cout << endl << "You have no orders!" << endl;
								break;
							}

							// Print all orders in the customer's order list
							customer->getOrderList().orderListPrint();
							break;

						case 4: // Payment
							// Loop through the customer's orders to find "Prepared" orders
							for (int i = 0; i < customer->getOrderList().orderListGetLength(); i++)
								if (customer->getOrderList().getOrderByIndex(i)->getStatus() == "Prepared")
								{
									case4Flag = true; // Set flag if prepared orders are found
									customer->getOrderList().getOrderByIndex(i)->printOrder();
									totalAmountToPay += customer->getOrderList().getOrderByIndex(i)->getTotalPrice();
								}

							// If no "Prepared" orders found, inform the user and exit
							if (case4Flag == false)
							{
								cout << endl << "No orders to pay!" << endl;
								break;
							}

							cout << endl <<  "Total amount to pay: " << totalAmountToPay << endl;
							cout << "Enter \"yes\" to confirm your payment or any key to exit: ";
							cin >> paymentInput;

							// If user confirms payment
							if (paymentInput == "yes")
							{
								customer->getMembership().addLoyaltyPoints(totalAmountToPay);

								// Update the status of all "Prepared" orders to "Paid"
								for (int i = 0; i < customer->getOrderList().orderListGetLength(); i++)
									if (customer->getOrderList().getOrderByIndex(i)->getStatus() == "Prepared")
									{
										customer->getOrderList().getOrderByIndex(i)->setStatus(Paid);
									}
								cout << endl << "Payment successful!" << endl;
								unpaidOrdersExist = false; // No unpaid orders exist after payment
								customer->getMembership().printMembership(); // Print updated membership details
							}

							break;

						case 5:
							// Check if there are any "Prepared" orders remainin
							for (int i = 0; i < customer->getOrderList().orderListGetLength(); i++) {
								if (customer->getOrderList().getOrderByIndex(i)->getStatus() == "Prepared") {
									unpaidOrdersExist = true; // Set flag if unpaid orders are found
									break; // No need to continue checking if one unpaid order is found
								}
							}

							// If there are unpaid orders, inform the user that they cannot log out
							if (unpaidOrdersExist) {
								cout << "You have unpaid orders. You cannot log out until all orders are paid." << endl;
							}
							break;

						default: 
							invalidIntegerInput(); // Handle invalid input within the main loop
						}
					} while (userChoice1 != 5 || unpaidOrdersExist); // Continue loop until user logs out or unpaid orders exist
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