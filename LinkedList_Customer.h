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

	bool removeOrder(Order&);

	Order* getOrderByOrderID(int);

	Order* getOrderByIndex(int);

	bool orderListIsEmpty();

	int orderListGetLength();

	void orderListPrint();
};