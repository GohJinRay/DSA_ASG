#include "Customer.h"

Customer::Customer() { };

Customer::Customer(LinkedList_Customer OrderList, int UserID, string Name, string Password, int PhoneNum, bool IsAdmin): User(UserID, Name, Password, PhoneNum, IsAdmin) 
{
	orderList = OrderList;
}

bool Customer::login()
{

}

void Customer::viewMenu()
{

}

bool Customer::createOrder(Order ) //Finish parameters
{

}

bool Customer::cancelOrder(Order ) //Finish parameters
{

}