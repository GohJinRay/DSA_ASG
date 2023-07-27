#include "Order.h"

Order::Order() { }

Order::Order(int OrderID, string OrderDate, string Status, Customer* Customer)
	:orderID(OrderID), orderDate(OrderDate), status(Status), customer(Customer), foodItemList() { };

bool Order::addFoodItem(int option) 
{
	//Main course
	FoodItem newFoodItem1(1, "Hainanese Chicken Rice", 4.50, true);
	FoodItem newFoodItem2(2, "Steak", 15.99, true);
	FoodItem newFoodItem3(3, "Nasi Lemak", 5.80, true);
	FoodItem newFoodItem4(4, "Mee Goreng", 6.99, true);
	FoodItem newFoodItem5(5, "Tom Yum Soup", 7.50, true);

	//Drinks
	FoodItem newFoodItem6(6, "Coca-Cola", 2.00, true);
	FoodItem newFoodItem7(7, "Ice Lemon Tea", 2.30, true);
	FoodItem newFoodItem8(8, "Bandung", 1.80, true);
	FoodItem newFoodItem9(9, "Thai Iced Tea", 2.20, true);

	//Deserts
	FoodItem newFoodItem10(10, "Chocolate Cake", 5.99, true);
	FoodItem newFoodItem11(11, "Ice Cream", 3.50, true);
	FoodItem newFoodItem12(12, "Mango Sticky Rice", 5.00, true);

	if (option == 1)
		foodItemList.addFoodItem(newFoodItem1);

	else if (option == 2)
		foodItemList.addFoodItem(newFoodItem2);
	

	return true;
}

bool Order::removeFoodItem(int option) //Not done
{
	if (foodItemList.FoodItemListgetLength() == 0) {
		return false;
	}

	foodItemList.removeFoodItem(option);
	return true;
}

void Order::setOrderID(int OrderID) { orderID = OrderID; }
void Order::setOrderDate(string OrderDate) { orderDate = OrderDate; }
void Order::setStatus(string Status) { status = Status; }

int Order::getOrderID() { return orderID; }
string Order::getOrderDate() { return orderDate; }
string Order::getStatus() { return status; }
Customer* Order::getCustomer() { return customer; }
LinkedList_Order Order::getFoodItemList() { return foodItemList; }
