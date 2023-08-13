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

/*
   Retrieve a food item from the category's sorted array using its foodID.

   Parameters:
   - foodID: The ID of the food item to retrieve.

   Return Value: The FoodItem object if found, otherwise a default FoodItem object.
*/
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
	cout << endl;
	cout << "Category ID: " << getCatID() << endl;
	cout << "Category Name: " << getCatName() << endl;
	cout << "------------------------------------------------" << endl;
	cout << " Food ID |                 Food Name | Price ($)" << endl;
	cout << "------------------------------------------------" << endl;
	getCatArray().print();
}
