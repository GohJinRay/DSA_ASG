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

	bool addItem(ItemType& foodItem);

	bool addItem(int index, ItemType foodItem);

	void removeItem(int index);

	ItemType getItem(int index);

	bool isEmpty();

	int getLength();

	void print();
};

