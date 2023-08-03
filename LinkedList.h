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

	bool addItem(FoodItem& foodItem);

	bool addItem(int index, FoodItem foodItem);

	void removeItem(int index);

	FoodItem getItem(int index);

	bool isEmpty();

	int getLength();

	void print();
};

