#include "Customer.h"
#include "Order.h"

Customer::Customer() { }

Customer::Customer(string userName, string Password, int PhoneNum, bool IsAdmin, LinkedList_Customer OrderList)
	: User(userName, Password, PhoneNum, IsAdmin)
{
	orderList = OrderList;
}

void Customer::printDetails()
{
	User::printDetails();
}

void Customer::viewMenu() // not done
{

}

Order* Customer::createOrder(int orderID) 
{
	time_t now = time(0);
	char buffer[26]; // Use ctime_s to print human-readable date
	ctime_s(buffer, sizeof(buffer), &now);
	string currTime(buffer); //Convert to string format
	Order* newOrder = new Order(orderID, currTime, "Not Prepared", this);
	orderList.addOrder(newOrder);

	return newOrder;
}

bool Customer::cancelOrder() // not done
{
	return true;
}

LinkedList_Customer Customer::getOrderList()
{
	return orderList;
}

