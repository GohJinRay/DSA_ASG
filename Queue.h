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

	bool enqueue(Order&);

	bool dequeue();
	bool dequeue(Order&);

	void getFront(Order&);

	bool isEmpty();
	
	void displayItems();
};

