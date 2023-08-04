#pragma once
#include <iostream>
#include "Order.h"
using namespace std;

typedef Order ItemType;

class Queue
{
private:
	struct Node
	{
		ItemType item;
		Node* next;
	};

	Node* frontNode;
	Node* backNode;

public:
	Queue();

	~Queue();

	bool enqueue(ItemType order);

	bool dequeue();

	bool dequeue(ItemType order);

	void getFront(ItemType order);

	bool isEmpty();
	
	void displayItems();
};

