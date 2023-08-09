#pragma once
#include <iostream>
#include "Order.h"
using namespace std;

class Queue
{
private:
	struct Node
	{
		Order orderItem;
		Node* next;
	};

	Node* frontNode;
	Node* backNode;

public:
	Queue();
	~Queue();

	bool enqueue(Order& item);

	bool dequeue();
	bool dequeue(Order& item);

	void getFront(Order& item);

	bool isEmpty();
	
	void displayItems();
};

