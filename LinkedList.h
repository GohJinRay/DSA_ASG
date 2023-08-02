#pragma once
#include "FoodItem.h"
using namespace std;

class LinkedList
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

	LinkedList();

	~LinkedList();

	bool addFoodItem(FoodItem& foodItem);

	bool addFoodItem(int index, FoodItem foodItem);

	void removeFoodItem(int index);

	FoodItem getFoodItem(int index);

	bool isEmpty();

	int getLength();

	void print();
};

