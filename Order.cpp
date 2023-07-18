#include "Order.h"

Order::Order() { }

Order::Order(int OrderID, time_t OrderDate, string Status, Customer Customer)
	:orderID(OrderID), orderDate(OrderDate), status(Status), customer(Customer), foodItemList() { };

bool Order::addFoodItem(int option) 
{
	FoodItem newFoodItem1(1, "CCR", 12.90, false);
	FoodItem newFoodItem2(2, "AIDAN", 10.90, false);

	if (option == 1)
		foodItemList.addFoodItem(newFoodItem1);

	else if (option == 2)
		foodItemList.addFoodItem(newFoodItem2);

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
