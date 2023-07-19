#pragma once
using namespace std;

class Order; //Forward declaration

class LinkedList_Customer
{
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

	bool addOrder(Order* orderItem);

	bool addOrder(int index, Order* orderItem);

	void removeOrder(int index);

	Order* getOrder(int index);

	bool OrderListisEmpty();

	int OrderListgetLength();

	void OrderListprint();
};

