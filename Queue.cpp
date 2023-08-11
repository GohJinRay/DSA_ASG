#include "Queue.h"

Queue::Queue() { };

Queue::~Queue()
{
	while (!isEmpty())
	{
		dequeue();
	}
}

bool Queue::enqueue(Order& orderItem)
{
	Node* newNode = new Node;
	newNode->orderItem = orderItem;
	newNode->next = NULL;

	if (isEmpty())
	{
		frontNode = newNode;
	}

	else
	{
		backNode->next = newNode;
	}

	backNode = newNode;
	return true;
}

bool Queue::dequeue()
{
	if (isEmpty())
	{
		cout << "No nodes to dequeue!" << endl;
		return false;
	}

	else if (frontNode == backNode)
	{
		frontNode = NULL;
		backNode = NULL;

		delete frontNode;
	}

	else
	{
		Node* temp = frontNode;
		frontNode = frontNode->next;

		temp->next = NULL;
		delete temp;
	}
	return true;
}

bool Queue::dequeue(Order& orderItem)
{
	if (isEmpty())
	{
		cout << "No nodes to dequeue!" << endl;
		return false;
	}

	else if (frontNode == backNode)
	{
		orderItem = frontNode->orderItem;
		frontNode = NULL;
		backNode = NULL;

		delete frontNode;
	}

	else
	{
		Node* temp = frontNode;
		orderItem = temp->orderItem;
		frontNode = frontNode->next;

		temp->next = NULL;
		delete temp;
	}
	return true;
}

void Queue::getFront(Order& orderItem) 
{
	if (!isEmpty())
		orderItem = frontNode->orderItem;

	else
	{
		orderItem.setOrderID(-1);
	}
}

bool Queue::isEmpty()
{
	return (frontNode == NULL);
}

void Queue::displayItems() 
{
	if (isEmpty())
	{
		cout << "Queue is empty!" << endl << endl;
	}

	else
	{
		Node* curr = frontNode;
		while (curr != NULL)
		{
			curr->orderItem.printOrder();
			curr = curr->next;
		}
	}
}