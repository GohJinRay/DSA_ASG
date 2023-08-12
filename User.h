#pragma once
#include <iostream>
using namespace std;

class User
{
private:
	string userName;
	string password;
	int phoneNum;

public:
	User();
	User(string, string, int);

	string getUserName();
	string getPassword();
	int getPhoneNum();

	virtual void printDetails();
};