#pragma once
#include <string>
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
	string getName();
};