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

	FoodItem getFoodItemByFoodID(int);
	int getCatID();
	string getCatName();
	SortedArray& getCatArray();

	void printDetails();
	
};

