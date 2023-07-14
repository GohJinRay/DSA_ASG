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

	bool add(FoodItem foodItem);

	bool add(int index, FoodItem foodItem);

	void remove(int index);

	FoodItem get(int index);

	bool isEmpty();

	int getLength();

	void print();
};

