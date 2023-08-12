#include "User.h"

// Default constructor for User class
User::User() { };

/*
   Constructor to initialize User object with provided values.

   Input Parameters:
   - UserName: The username of the user.
   - Password: The password of the user (to be used for log in). 
   - PhoneNum: The phone number of the user.
*/
User::User(string UserName, string Password, int PhoneNum)
{
	userName = UserName;
	password = Password;
	phoneNum = PhoneNum;
}

/*
   Print the user's details, including username and phone number.
*/
void User::printDetails() 
{
	cout << "User Name: " << getUserName() << endl;
	cout << "Phone Number: " << getPhoneNum() << endl;
}

/*
   Retrieve the user's username.
*/
string User::getUserName() { return userName; }

/*
   Retrieve the user's password.
*/
string User::getPassword() { return password; }

/*
   Retrieve the user's phone number.
*/
int User::getPhoneNum() { return phoneNum; }