#include "User.h"

User::User() { };

User::User(int UserID, string FullName, string Password, int PhoneNum, bool IsAdmin)
{
	userID = UserID;
	fullName = FullName;
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
	cout << "User ID: " << getUserID() << endl;
	cout << "Full Name: " << getFullName() << endl;
	cout << "Password: " << getPassword() << endl;
	cout << "Phone Number: " << getPhoneNum() << endl;
}

void User::setUserID(int UserID) { userID = UserID; }
void User::setFullName(string FullName) { fullName = FullName; }
void User::setPassword(string Password) { password = Password; }
void User::setPhoneNum(int PhoneNum) { phoneNum = PhoneNum; }

int User::getUserID() { return userID; }
string User::getFullName() { return fullName; }
string User::getPassword() { return password; }
int User::getPhoneNum() { return phoneNum; }