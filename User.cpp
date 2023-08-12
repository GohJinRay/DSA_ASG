#include "User.h"

User::User() { };

User::User(string UserName, string Password, int PhoneNum)
{
	userName = UserName;
	password = Password;
	phoneNum = PhoneNum;
}

void User::printDetails() // print user details
{
	cout << "User Name: " << getUserName() << endl;
	cout << "Phone Number: " << getPhoneNum() << endl;
}

// getting methods for retrieving User attribute
string User::getUserName() { return userName; }
string User::getPassword() { return password; }
int User::getPhoneNum() { return phoneNum; }