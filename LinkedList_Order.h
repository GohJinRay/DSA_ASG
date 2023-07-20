#pragma once
#include "FoodItem.h"
using namespace std;

class LinkedList_Order
{
private:
	struct Node
	{
		FoodItem foodItem;
		Node* next;
	};

	Node* firstNode;
	int size;

public:

	LinkedList_Order();

	~LinkedList_Order();

	bool addFoodItem(FoodItem& foodItem);

	bool addFoodItem(int index, FoodItem foodItem);

	void removeFoodItem(int index);

	FoodItem getFoodItem(int index);

	bool FoodItemListisEmpty();

	int FoodItemListgetLength();

	void FoodItemListprint();
};

