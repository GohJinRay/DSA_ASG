#include "Category.h"

// Default constructor for Category class
Category::Category() {}; 

/*
   Parameterized constructor to initialize Category attributes with provided values.

   Input Parameters:
   - CatID: The category ID.
   - CatName: The name of the category.
   - CatArray: The sorted array containing food items within the category.
*/
Category::Category(int CatID, string CatName, SortedArray CatArray)  
{
	catID = CatID;
	catName = CatName;
	catArray = CatArray;
}

// Add a food item to the sorted array within the category.
bool Category::addFoodItem(FoodItem foodItem)
{
	return catArray.insert(foodItem);
}

// Remove a food item from the sorted array within the category using its foodID.
bool Category::removeFoodItem(int foodID) 
{
	return catArray.remove(foodID);
}


// Retrieve a food item from the category's sorted array using its foodID.
FoodItem Category::getFoodItemByFoodID(int foodID) { return catArray.searchByFoodID(foodID); } 

// Retrieve the category's ID.
int Category::getCatID() { return catID; }

// Retrieve the category's name.
string Category::getCatName() { return catName; }

// Retrieve the reference to the sorted array of food items within the category.
SortedArray& Category::getCatArray() { return catArray; }

// Print the details of the category, including its food items.
void Category::printDetails() 
{
	cout << "Category ID: " << getCatID() << endl;
	cout << "Category Name: " << getCatName() << endl;
	cout << "Food Items in Category:" << endl;
	cout << "------------------------------------------------" << endl;
	getCatArray().print();
}
