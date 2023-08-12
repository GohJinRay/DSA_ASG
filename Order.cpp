#include "Order.h"

// Default constructor for Order class
Order::Order() { } 

/*
   Constructor to initialize Order object with provided values.

   Input Parameters:
   - OrderID: The unique identifier for the order.
   - OrderDate: The date of the order.
   - Status: The status of the order (Prepared, NotPrepared, Paid).
   - TotalPrice: The total price of the order.
   - Customer: Pointer to the customer object associated with the order.
   - FoodItemList: The linked list of food items in the order.
*/
Order::Order(int OrderID, string OrderDate, OrderStatus Status, double TotalPrice, Customer* Customer, LinkedList_Order FoodItemList) 
{
	orderID = OrderID;
	orderDate = OrderDate;
	status = Status; 
	totalPrice = TotalPrice;
	customer = Customer;
	foodItemList = FoodItemList;
}

/*
   Add a food item to the order and update the total price.

   Input Parameters:
   - foodItem: The food item to be added to the order.

   Return Value:
   Returns true after successfully adding the food item.
*/
bool Order::addFoodItem(FoodItem foodItem)  
{
	// Add the provided food item to the food item list of the order
	foodItemList.addItem(foodItem);

	// Update the total price of the order by adding the food item's price
	totalPrice += foodItem.getPrice();

	cout << "Food item has been added to the order." << endl;
	return true;
}

/*
   Remove a food item from the order and update the total price.

   Input Parameters:
   - foodID: The ID of the food item to be removed.

   Return Value:
   Returns true if the food item was successfully removed.
   Returns false if the food item is not found in the order.
*/
bool Order::removeFoodItem(int foodID)  
{
	if (foodItemList.getLength() == 0) {
		cout << "Food Item List is empty." << endl;
		return false;
	}

	// Get the removed food item using its ID
	FoodItem removedItem = foodItemList.getItemByFoodID(foodID);

	// Remove the food item from the food item list and update the total price
	if (foodItemList.removeItem(foodID) == true)
	{
		totalPrice -= removedItem.getPrice();
		cout << "Food item has been removed!" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

/*
   Print the details of the order and its associated food items.
   Displays order ID, order date, status, total price, and food items.
*/
void Order::printOrder() 
{
	cout << endl;
	cout << "|Order ID: " << getOrderID() << endl;
	cout << "|Order Date: " << getOrderDate();
	cout << "|Status: " << getStatus() << endl;
	cout << "|Total Price: $" << getTotalPrice() << endl << endl;
	cout << " Food ID |                 Food Name | Price ($)" << endl;
	cout << "------------------------------------------------" << endl;

	// Print the list of food items in the order
	getFoodItemList().print();
}

// Set method to modify the order's OrderID
void Order::setOrderID(int OrderID) { orderID = OrderID; }

// Set method to modify the order's OrderDate
void Order::setOrderDate(string OrderDate) { orderDate = OrderDate; }

// Set method to modify the order's Status
void Order::setStatus(OrderStatus Status) { status = Status; }

// Set method to modify the order's TotalPrice
void Order::setTotalPrice(double TotalPrice) { totalPrice = TotalPrice; }

// Get method to retrieve the order's OrderID
int Order::getOrderID() { return orderID; }

// Get method to retrieve the order's OrderDate
string Order::getOrderDate() { return orderDate; }

// Get method to retrieve the order's Status
string Order::getStatus() 
{ 
	// Translate the order status enum to a human-readable string
	switch (status)
	{
		case Prepared:
			return "Prepared";

		case NotPrepared:
			return "Not Prepared";

		case Paid:
			return "Paid";

		default:
			return "Unknown";
	}
}

// Get method to retrieve the order's TotalPrice
double Order::getTotalPrice() { return totalPrice; }

// Get method to retrieve the order's associated Customer
Customer* Order::getCustomer() { return customer; }

// Get method to retrieve the order's FoodItemList
LinkedList_Order Order::getFoodItemList() { return foodItemList; }
