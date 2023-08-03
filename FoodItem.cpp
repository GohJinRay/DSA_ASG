#include "FoodItem.h"

FoodItem::FoodItem() { }

FoodItem::FoodItem(int FoodID, string FoodName, double Price)
{
	foodID = FoodID;
	foodName = FoodName;
	price = Price;
}

void FoodItem::printFoodItem()
{
	cout << "Food ID: " << getFoodID() << endl;
	cout << "Food Name: " << getFoodName() << endl;
	cout << "Price: " << getPrice() << endl << endl;
}

void FoodItem::setFoodID(int FoodID) { foodID = FoodID; }
void FoodItem::setFoodName(string FoodName) { foodName = FoodName; }
void FoodItem::setPrice(double Price) { price = Price; }

int FoodItem::getFoodID() { return foodID; }
string FoodItem::getFoodName() { return foodName; }
double FoodItem::getPrice() { return price; }
