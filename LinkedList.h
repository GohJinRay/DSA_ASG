#pragma once
#include "FoodItem.h"
using namespace std;

typedef FoodItem ItemType;

class LinkedList
{
private:
	struct Node
	{
		ItemType item;
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

