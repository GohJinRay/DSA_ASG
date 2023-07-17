#include "Order.h"

Order::Order() { }

Order::Order(int OrderID, time_t OrderDate, string Status, Customer Customer, LinkedList_Order FoodItemList)
{
	orderID = OrderID;
	orderDate = OrderDate;
	status = Status;
	customer = Customer;
	foodItemList = FoodItemList;
}

bool Order::addFoodItem() 
{
	return true;
}

bool Order::removeFoodItem() 
{
	return true;
}

void Order::setOrderID(int OrderID) { orderID = OrderID; }
void Order::setOrderDate(time_t OrderDate) { orderDate = OrderDate; }
void Order::setStatus(string Status) { status = Status; }

int Order::getOrderID() { return orderID; }
time_t Order::getOrderDate() { return orderDate; }
string Order::getStatus() { return status; }
Customer Order::getCustomer() { return customer; }
LinkedList_Order Order::getFoodItemList() { return foodItemList; }
