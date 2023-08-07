#include "Category.h"

Category::Category() {};

Category::Category(int CatID, string CatName, SortedArray CatArray) 
{
	catID = CatID;
	catName = CatName;
	catArray = CatArray;
}

bool Category::addFoodItem(FoodItem foodItem)
{
	return catArray.insert(foodItem);
}

bool Category::removeFoodItem(int foodID)
{
	return catArray.remove(foodID);
}

FoodItem Category::getFoodItem(int foodID)
{
	return catArray.search(foodID);
}

int Category::getCatID()
{
	return catID;
}

string Category::getCatName()
{
	return catName;
}

SortedArray Category::getCatArray()
{
	return catArray;
}

void Category::printDetails()
{
	cout << "Category ID: " << getCatID() << endl;
	cout << "Category Name: " << getCatName() << endl;
	cout << "Food Items in Category:" << endl;
	cout << "------------------------------------------------" << endl;
	getCatArray().print();
}
