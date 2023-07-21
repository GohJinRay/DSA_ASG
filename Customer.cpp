#include "Customer.h"
#include "Order.h"

Customer::Customer() { }

Customer::Customer(int UserID, string Name, string Password, int PhoneNum, bool IsAdmin)
	: User(UserID, Name, Password, PhoneNum, IsAdmin), orderList() {}

bool Customer::login() // not done
{
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
	time_t orderDate = time(0);
	Order* newOrder = new Order(orderID, orderDate, "Not prepared", *this);
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

