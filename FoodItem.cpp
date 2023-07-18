#include "FoodItem.h"

FoodItem::FoodItem() { }

FoodItem::FoodItem(int FoodID, string FoodName, double Price, bool IsAvail)
{
	foodID = FoodID;
	foodName = FoodName;
	price = Price;
	isAvail = IsAvail;
}

void FoodItem::setFoodID(int FoodID) { foodID = FoodID; }
void FoodItem::setFoodName(string FoodName) { foodName = FoodName; }
void FoodItem::setPrice(double Price) { price = Price; }
void FoodItem::setIsAvail(bool IsAvail) { isAvail = IsAvail; }

int FoodItem::getFoodID() { return foodID; }
string FoodItem::getFoodName() { return foodName; }
double FoodItem::getPrice() { return price; }
bool FoodItem::getIsAvail() { return isAvail; }
