#pragma once
#include <string>
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

	bool addItem(FoodItem&);
	bool addItem(int, FoodItem&);

	bool removeItem(int);

	FoodItem getItemByIndex(int);

	FoodItem getItemByFoodID(int);

	bool isEmpty();

	int getLength();

	void print();
};

