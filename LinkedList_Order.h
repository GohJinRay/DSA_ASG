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

	bool addItem(FoodItem& item);

	bool addItem(int index, FoodItem& item);

	void removeItem(int index);

	FoodItem getItem(int index);

	bool isEmpty();

	int getLength();

	void print();
};

