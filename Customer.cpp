#include "Customer.h"
#include "Order.h"

Customer::Customer() { }

Customer::Customer(int UserID, string Name, string Password, int PhoneNum, bool IsAdmin)
	: User(UserID, Name, Password, PhoneNum, IsAdmin), orderList() {}

bool Customer::login()
{
	return true;
}

void Customer::printDetails()
{
	User::printDetails();
}

void Customer::viewMenu()
{

}

Order* Customer::createOrder(int orderID) 
{
	time_t orderDate = time(0);
	Order* newOrder = new Order(orderID, orderDate, "Not preapred", *this);
	orderList.addOrder(newOrder);

	return newOrder;
}

bool Customer::cancelOrder() 
{
	return true;
}

LinkedList_Customer Customer::getOrderList()
{
	return orderList;
}

