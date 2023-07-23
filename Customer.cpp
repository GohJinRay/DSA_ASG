#include "Customer.h"
#include "Order.h"

Customer::Customer() { }

Customer::Customer(int UserID, string FullName, string Password, int PhoneNum, bool IsAdmin, LinkedList_Customer OrderList)
	: User(UserID, FullName, Password, PhoneNum, IsAdmin)
{
	orderList = OrderList;
}

bool Customer::login() // not done
{
	string fullname, password;

	cout << "Please enter your full name: ";
	cin >> fullname;

	cout << "Please enter your password: ";
	cin >> password;

	return true;
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

