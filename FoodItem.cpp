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
	cout << "------------------------------------------------" << endl;
	cout.width(8);
	cout << getFoodID();
	cout << " | ";
	cout.width(25);
	cout << getFoodName();
	cout << " | $";
	cout.precision(2);
	cout << fixed;
	cout << getPrice();
	cout << endl;
}

void FoodItem::setFoodID(int FoodID) { foodID = FoodID; }
void FoodItem::setFoodName(string FoodName) { foodName = FoodName; }
void FoodItem::setPrice(double Price) { price = Price; }

int FoodItem::getFoodID() { return foodID; }
string FoodItem::getFoodName() { return foodName; }
double FoodItem::getPrice() { return price; }
