#include "FoodItem.h"

// Default constructor for FoodItem class
FoodItem::FoodItem() { } 

/*
   Initialize the food item with the given FoodID, FoodName, and Price.

   Input Parameters:
   - FoodID: The unique identifier for the food item.
   - FoodName: The name of the food item.
   - Price: The price of the food item.
*/
FoodItem::FoodItem(int FoodID, string FoodName, double Price) 
{
	foodID = FoodID;
	foodName = FoodName;
	price = Price;
}

/*
   Print the food item with a formatted display.
   The output format: "FoodID |       FoodName        | $Price"
*/
void FoodItem::printFoodItem() 
{
	// Set the width and format of the output for each attribute
	cout.width(8);
	cout << getFoodID();
	cout << " | ";
	cout.width(25);
	cout << getFoodName();
	cout << " | $";
	cout.precision(2);
	cout << fixed;
	cout << getPrice() << endl;
}

/*
   Modify the food item's FoodID.

   Input Parameters:
   - FoodID: The new FoodID value to set.
*/
void FoodItem::setFoodID(int FoodID) { foodID = FoodID; }

/*
   Modify the food item's FoodName.

   Input Parameters:
   - FoodName: The new FoodName value to set.
*/
void FoodItem::setFoodName(string FoodName) { foodName = FoodName; }

/*
   Modify the food item's Price.

   Input Parameters:
   - Price: The new Price value to set.
*/
void FoodItem::setPrice(double Price) { price = Price; }

/*
   Retrieve the food item's FoodID.

   Return Value:
   The FoodID of the food item.
*/
int FoodItem::getFoodID() { return foodID; }

/*
   Retrieve the food item's FoodName.

   Return Value:
   The FoodName of the food item.
*/
string FoodItem::getFoodName() { return foodName; }

/*
   Retrieve the food item's Price.

   Return Value:
   The Price of the food item.
*/
double FoodItem::getPrice() { return price; }
