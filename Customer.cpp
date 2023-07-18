#include "Customer.h"

Customer::Customer() { }

Customer::Customer(LinkedList_Customer OrderList,int UserID, string Name, string Password, int PhoneNum, bool IsAdmin) : User(UserID, Name, Password, PhoneNum, IsAdmin)
{
	orderList = OrderList;
}

bool Customer::login()
{
	return true;
}

void Customer::viewMenu()
{

}

bool Customer::createOrder() 
{
	return true;
}

bool Customer::cancelOrder() 
{
	return true;
}

