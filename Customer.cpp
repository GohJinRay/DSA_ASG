#include "Customer.h"
#include "Order.h"

Customer::Customer() { }

Customer::Customer(string userName, string Password, int PhoneNum, bool IsAdmin, AVLTree BinTree)
	: User(userName, Password, PhoneNum, IsAdmin)
{
	binTree = BinTree;
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
	return newOrder;
}

bool Customer::cancelOrder() // not done
{
	return true;
}

Order Customer::getOrder() {
	return;
}
