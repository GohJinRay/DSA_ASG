#include "Queue.h"

Queue::Queue() { };

Queue::~Queue()
{
	while (!isEmpty())
	{
		dequeue();
	}
}

bool Queue::enqueue(Order& order)
{
	Node* newNode = new Node;
	newNode->order = order;
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

bool Queue::dequeue(Order& order)
{
	if (frontNode == NULL)
	{
		cout << "No nodes to dequeue!" << endl;
		return false;
	}

	else if (frontNode == backNode)
	{
		order = frontNode->order;
		frontNode = NULL;
		backNode = NULL;

		delete frontNode;
	}

	else
	{
		Node* temp = frontNode;
		order = temp->order;
		frontNode = frontNode->next;

		temp->next = NULL;
		delete temp;
	}
	return true;
}

void Queue::getFront(Order& order)
{
	if (!isEmpty())
		order = frontNode->order;

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
		cout << "Queue is empty!" << endl;
	}

	else
	{
		Node* curr = frontNode;
		while (curr != NULL)
		{
			cout << "Order ID: " << curr->order.getOrderID() << endl;
			cout << "Order Date: " << curr->order.getOrderDate() << endl;
			cout << "Status: " << curr->order.getStatus() << endl << endl;
			//curr->order.getCustomer()->printDetails();
			cout << endl;
			cout << "Food Items: " << endl << endl;
			curr->order.getFoodItemList().print(); 
			cout << endl;
			curr = curr->next;
		}
		cout << endl;
	}
}