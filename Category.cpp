#include "Category.h"

Category::Category() {}; // Default constructor

Category::Category(int CatID, string CatName, SortedArray CatArray)  // Parameterized constructor that initializes Cateogry
{
	catID = CatID;
	catName = CatName;
	catArray = CatArray;
}

bool Category::addFoodItem(FoodItem foodItem) // Add fooditem to sorted array
{
	return catArray.insert(foodItem);
}

bool Category::removeFoodItem(int foodID) // remove fooditem via foodID in sorted array
{
	return catArray.remove(foodID);
}


// getting methods for retrieving category array attributes
FoodItem Category::getFoodItem(int foodID) {return catArray.search(foodID);} // get fooditem via foodID
int Category::getCatID() {return catID;}
string Category::getCatName() {return catName;}
SortedArray Category::getCatArray() {return catArray;}

void Category::printDetails() // print fooditem details
{
	cout << "Category ID: " << getCatID() << endl;
	cout << "Category Name: " << getCatName() << endl;
	cout << "Food Items in Category:" << endl;
	cout << "------------------------------------------------" << endl;
	getCatArray().print();
}
