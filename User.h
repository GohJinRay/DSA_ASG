#pragma once
#include <iostream>
using namespace std;

class User
{
private:
	int userID;
	string fullName;
	string password;
	int phoneNum;
	bool isAdmin;

public:
	User();
	User(int, string, string, int, bool);
	bool registerUser();
	virtual bool login() = 0;

	void setUserID(int);
	void setFullName(string);
	void setPassword(string);
	void setPhoneNum(int);

	int getUserID();
	string getFullName();
	string getPassword();
	int getPhoneNum();
	virtual void printDetails();
};