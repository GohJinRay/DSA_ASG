#pragma once
using namespace std;

class Order;

class LinkedList_Customer
{
private:
	struct Node
	{
		Order* orderItem;
		Node  *next;
	};

	Node* firstNode;
	int size;

public:
	LinkedList_Customer();

	~LinkedList_Customer();

	bool add(Order* orderItem);

	bool add(int index, Order* orderItem);

	void remove(int index);

	Order* get(int index);

	bool isEmpty();

	int getLength();

	void print();
};

