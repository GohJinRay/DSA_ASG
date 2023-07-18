#include "Admin.h"

Admin::Admin() { };

Admin::Admin(int UserID, string Name, string Password, int PhoneNum, bool IsAdmin) : User(UserID, Name, Password, PhoneNum, IsAdmin) { };

bool Admin::login()
{
	return true;
}

void Admin::viewOrders()
{

}

bool Admin::updateStatus() 
{
	return true;
}

void Admin::viewCustInfo() 
{

}