#include "Queue.h"

typedef Order ItemType;

Queue::Queue() { };

Queue::~Queue()
{
	while (!isEmpty())
	{
		dequeue();
	}
}

bool Queue::enqueue(ItemType order)
{
	Node* newNode = new Node;
	newNode->item = order;
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
	if (frontNode == NULL)
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

bool Queue::dequeue(ItemType order)
{
	if (frontNode == NULL)
	{
		cout << "No nodes to dequeue!" << endl;
		return false;
	}

	else if (frontNode == backNode)
	{
		order = frontNode->item;
		frontNode = NULL;
		backNode = NULL;

		delete frontNode;
	}

	else
	{
		Node* temp = frontNode;
		order = temp->item;
		frontNode = frontNode->next;

		temp->next = NULL;
		delete temp;
	}
	return true;
}

void Queue::getFront(ItemType order)
{
	if (!isEmpty())
		order = frontNode->item;

	else
	{
		order.setOrderID(-1);
		order.setOrderDate("");
		order.setStatus("Not prepared");
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
			curr->item.printOrder();
			curr = curr->next;
		}
	}
}