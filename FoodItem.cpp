#include "FoodItem.h"

FoodItem::FoodItem() { } // Default constructor

FoodItem::FoodItem(int FoodID, string FoodName, double Price) // Initialize the food item with the given FoodID, FoodName, and Price
{
	foodID = FoodID;
	foodName = FoodName;
	price = Price;
}

void FoodItem::printFoodItem() // print the fooditem with format
{
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

// setting methods that modify fooditem attributes
void FoodItem::setFoodID(int FoodID) { foodID = FoodID; }
void FoodItem::setFoodName(string FoodName) { foodName = FoodName; }
void FoodItem::setPrice(double Price) { price = Price; }

// getting methods for retrieving fooditem attributes
int FoodItem::getFoodID() { return foodID; }
string FoodItem::getFoodName() { return foodName; }
double FoodItem::getPrice() { return price; }
