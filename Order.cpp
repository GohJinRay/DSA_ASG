#include "Order.h"

Order::Order() { } // Default constructor

Order::Order(int OrderID, string OrderDate, OrderStatus Status, double TotalPrice, Customer* Customer, LinkedList_Order FoodItemList) 
{
	// Constructor to initialize Order attributes with provided values
	// OrderID, OrderDate, Status, Customer pointer, and FoodItemList.

	orderID = OrderID;
	orderDate = OrderDate;
	status = Status; 
	totalPrice = TotalPrice;
	customer = Customer;
	foodItemList = FoodItemList;
}

bool Order::addFoodItem(FoodItem foodItem)  // add fooditem to order
{
	foodItemList.addItem(foodItem);
	totalPrice += foodItem.getPrice();
	cout << "Food item has been added to the order." << endl;
	return true;
}

bool Order::removeFoodItem(int foodID)  // remove fooditem via id
{
	if (foodItemList.getLength() == 0) {
		cout << "Food Item List is empty." << endl;
		return false;
	}

	FoodItem removedItem = foodItemList.getItemByFoodID(foodID);
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

void Order::printOrder() // printing the orders
{
	cout << endl;
	cout << "|Order ID: " << getOrderID() << endl;
	cout << "|Order Date: " << getOrderDate();
	cout << "|Status: " << getStatus() << endl;
	cout << "|Total Price: $" << getTotalPrice() << endl << endl;
	cout << " Food ID |                 Food Name | Price ($)" << endl;
	cout << "------------------------------------------------" << endl;
	getFoodItemList().print();
}

// setting methods that modify order attributes
void Order::setOrderID(int OrderID) { orderID = OrderID; }
void Order::setOrderDate(string OrderDate) { orderDate = OrderDate; }
void Order::setStatus(OrderStatus Status) { status = Status; }
void Order::setTotalPrice(double TotalPrice) { totalPrice = TotalPrice; }

// getting methods for retrieving order attributes
int Order::getOrderID() { return orderID; }
string Order::getOrderDate() { return orderDate; }
string Order::getStatus() 
{ 
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
double Order::getTotalPrice() { return totalPrice; }
Customer* Order::getCustomer() { return customer; }
LinkedList_Order Order::getFoodItemList() { return foodItemList; }
