#pragma once
#include <string>
#include "SortedArray.h"
#include "FoodItem.h"

using namespace std;

class Category
{
private:
	int catID;
	string catName;
	SortedArray catArray;

public:
	Category();
	Category(int, string, SortedArray);

	bool addFoodItem(FoodItem);
	bool removeFoodItem(int);
	FoodItem getFoodItem(int);
	int getCatID();
	string getCatName();
	SortedArray getCatArray();

	void printDetails();
	
};

