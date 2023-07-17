#pragma once

#include<string>
#include<iostream>
using namespace std;

class User 
{
private:
	int id;
	string name;
	string password;
	int phoneNum;
	bool isAdmin;

public:
	User();
	User(int, string, string, int, bool);
	bool registerUser();
	bool login();

};