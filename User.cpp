#include "User.h"

User::User() { };

User::User(int UserID, string Name, string Password, int PhoneNum, bool IsAdmin)
{
	userID = UserID;
	name = Name;
	password = Password;
	phoneNum = PhoneNum;
	isAdmin = IsAdmin;
}

bool User::registerUser()
{
	return true;
}

string User::getName() 
{
	return name;
}