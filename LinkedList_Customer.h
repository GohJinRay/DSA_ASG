#pragma once
#include "Order.h"
using namespace std;

class LinkedList_Customer {
private:
	struct Node
	{
		Order* orderItem;
		Node* next;
	};

	Node* firstNode;
	int size;

public:
	LinkedList_Customer();
	~LinkedList_Customer();

	bool addOrder(Order*);
	bool addOrder(int, Order*);

	void removeOrder(Order&);

	Order* getOrder(int);

	bool orderListIsEmpty();

	int orderListGetLength();

	void orderListPrint();
};