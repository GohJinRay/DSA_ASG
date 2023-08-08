#include "User.h"

User::User() { };

User::User(string UserName, string Password, int PhoneNum)
{
	userName = UserName;
	password = Password;
	phoneNum = PhoneNum;
}

void User::printDetails()
{
	cout << "User Name: " << getUserName() << endl;
	cout << "Phone Number: " << getPhoneNum() << endl << endl;
}

void User::setUserName(string UserName) { userName = UserName; }
void User::setPassword(string Password) { password = Password; }
void User::setPhoneNum(int PhoneNum) { phoneNum = PhoneNum; }

string User::getUserName() { return userName; }
string User::getPassword() { return password; }
int User::getPhoneNum() { return phoneNum; }