#pragma once
#include <string>
using namespace std;

class FoodItem
{
private:
	int foodID;
	string foodName;
	double price;
	bool isAvail;

public:
	FoodItem();
	FoodItem(int, string, double, bool);
	
	void setFoodID(int);
	void setFoodName(string);
	void setPrice(double);
	void setIsAvail(bool);

	int getFoodID();
	string getFoodName();
	double getPrice();
	bool getIsAvail();
};


