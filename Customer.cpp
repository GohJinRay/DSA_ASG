#include "Customer.h"

Customer::Customer() { }

Customer::Customer(string UserName, string Password, int PhoneNum, bool IsAdmin)
	: User(UserName, Password, PhoneNum, IsAdmin) { }

void Customer::printDetails()
{
	User::printDetails();
}

void Customer::viewMenu() // not done
{
	cout << "----- Menu -----" << endl;
}

Order Customer::createOrder(int orderID) 
{
	LinkedList foodItemList;
	time_t now = time(0);
	char buffer[26]; // Use ctime_s to print human-readable date
	ctime_s(buffer, sizeof(buffer), &now);
	string currTime(buffer); //Convert to string format
	Order newOrder(orderID, currTime, "Not Prepared", this, foodItemList);
	return newOrder;
}

bool Customer::cancelOrder() // not done
{
	return true;
}
