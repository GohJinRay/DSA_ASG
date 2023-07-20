#pragma once

#include <iostream>
using namespace std;

class Order;

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

	void removeOrder(int);

	Order* getOrder(int);

	bool OrderListisEmpty();

	int OrderListgetLength();

	void OrderListprint();

};