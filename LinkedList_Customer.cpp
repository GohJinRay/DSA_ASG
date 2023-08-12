#include "LinkedList_Customer.h"
using namespace std;

LinkedList_Customer::LinkedList_Customer() // constructor
{
	firstNode = NULL;
	size = 0;
}

LinkedList_Customer::~LinkedList_Customer() // deconstructor
{
	Node* curr = firstNode;
	while (curr != NULL)
	{
		Node* next = curr->next;
		curr = NULL;
		delete curr;
		curr = next;
	}
}

bool LinkedList_Customer::addOrder(Order* orderItem) // add order to linkedlist
{
	Node* newNode = new Node;
	newNode->orderItem = orderItem;
	newNode->next = NULL;

	if (size == 0)
		firstNode = newNode;
	else
	{
		Node* curr = firstNode;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = newNode;
	}
	size++;
	return true;
}

bool LinkedList_Customer::removeOrder(Order& orderItem) // remove order from linkedlist
{
	Node* curr = firstNode;
	Node* prev = NULL;

	while (curr != NULL)
	{
		if (curr->orderItem->getOrderID() == orderItem.getOrderID())
		{
			if (prev == NULL)
				firstNode = curr->next;
			else
				prev->next = curr->next;

			delete curr;
			size--;
			return true;
		}
		
		prev = curr;
		curr = curr->next;
	}
	
	cout << "Order not found in the linked list." << endl;
	return false;
}

Order* LinkedList_Customer::getOrderByOrderID(int orderID) // get order from linkedlist
{
	Node* curr = firstNode;

	while (curr != NULL)
	{
		if (curr->orderItem->getOrderID() == orderID)
		{
			return curr->orderItem;
		}
		curr = curr->next;
	}
	return NULL;
}

Order* LinkedList_Customer::getOrderByIndex(int index) // get order from linkedlist
{
	if (index >= 0 && index < size)
	{
		int counter = 0;
		Node* curr = firstNode;

		while (curr != NULL && counter < index)
		{
			curr = curr->next;
			counter++;
		}

		if (curr != NULL)
			return curr->orderItem;
	}

	return NULL;
}

bool LinkedList_Customer::orderListIsEmpty() // check if order is empty
{
	return size == 0;
}

int LinkedList_Customer::orderListGetLength() // get linkedlist length
{
	return size;
}

void LinkedList_Customer::orderListPrint() // print all orders from linkedlist
{
	Node* curr = firstNode;

	while (curr != NULL)
	{
		Order* order = curr->orderItem;

		order->printOrder();

		curr = curr->next;
	}
	cout << endl;
}