#include "User.h"

User::User() { };

User::User(string UserName, string Password, int PhoneNum, bool IsAdmin)
{
	userName = UserName;
	password = Password;
	phoneNum = PhoneNum;
	isAdmin = IsAdmin;
}

bool User::registerUser() // not done
{
	return true;
}

void User::printDetails()
{
	cout << "Customer Details:" << endl;
	cout << "User Name: " << getUserName() << endl;
	cout << "Phone Number: " << getPhoneNum() << endl << endl;
}

void User::setUserName(string UserName) { userName = UserName; }
void User::setPassword(string Password) { password = Password; }
void User::setPhoneNum(int PhoneNum) { phoneNum = PhoneNum; }

string User::getUserName() { return userName; }
string User::getPassword() { return password; }
int User::getPhoneNum() { return phoneNum; }