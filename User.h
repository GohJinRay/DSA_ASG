#pragma once
#include <string>
#include <iostream>
using namespace std;

class User
{
private:
	int userID;
	string name;
	string password;
	int phoneNum;
	bool isAdmin;

public:
	User();
	User(int, string, string, int, bool);
	bool registerUser();
	virtual bool login() = 0;
	void setUserID(int);
	void setName(string);
	void setPassword(string);
	void setPhoneNum(int);
	int getUserID();
	string getName();
	string getPassword();
	int getPhoneNum();
	virtual void printDetails();
};