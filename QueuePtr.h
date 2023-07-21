#pragma once
#include "Order.h"
using namespace std;
class QueuePtr
{
private:
	struct Node
	{
		Order order;
		Node* next;
	};

	Node* frontNode;
	Node* backNode;

public:
	QueuePtr();

	~QueuePtr();

	bool enqueue(Order& order);

	bool dequeue();

	bool dequeue(Order& order);

	void getFront(Order& order);

	bool isEmpty();
	
	void displayItems();
};

