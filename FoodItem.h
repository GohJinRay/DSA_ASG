#pragma once
#include <string>
#include <iostream>
using namespace std;

class FoodItem
{
private:
	int foodID;
	string foodName;
	double price;

public:
	FoodItem();
	FoodItem(int, string, double);
	
	void printFoodItem();

	int getFoodID();
	string getFoodName();
	double getPrice();
};


