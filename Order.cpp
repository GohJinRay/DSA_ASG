#include "Order.h"

Order::Order() { }

Order::Order(int OrderID, string OrderDate, string Status, Customer* Customer, LinkedList FoodItemList)
{
	orderID = OrderID;
	orderDate = OrderDate;
	status = Status; 
	customer = Customer;
	foodItemList = FoodItemList;
}

bool Order::addFoodItem(FoodItem foodItem, int option) 
{
	if (option >= 1 && option <= maxFoodItems)
	{
		foodItemList.addItem(foodItem);
		cout << "Food item has been added to the order." << endl << endl;
		return true;
	}

	cout << "Invalid Food Item!" << endl << endl;
	return false;
}

bool Order::removeFoodItem(int option) 
{
	if (foodItemList.getLength() == 0) {
		cout << "Food Item List is empty." << endl << endl;
		return false;
	}

	if (option < 1 || option > foodItemList.getLength())
	{
		cout << "Invalid option!" << endl << endl;
		return false;
	}

	foodItemList.removeItem(option);
	cout << "Food item has been removed!" << endl << endl;
	return true;
}

void Order::printOrder()
{
	cout << "|Order ID: " << getOrderID() << endl;
	cout << "|Order Date: " << getOrderDate();
	cout << "|Status: " << getStatus() << endl << endl;
	cout << "Food Items:" << endl;
	cout << "-----------" << endl;
	getFoodItemList().print();
}

void Order::setOrderID(int OrderID) { orderID = OrderID; }
void Order::setOrderDate(string OrderDate) { orderDate = OrderDate; }
void Order::setStatus(string Status) { status = Status; }

int Order::getOrderID() { return orderID; }
string Order::getOrderDate() { return orderDate; }
string Order::getStatus() { return status; }
Customer* Order::getCustomer() { return customer; }
LinkedList Order::getFoodItemList() { return foodItemList; }
