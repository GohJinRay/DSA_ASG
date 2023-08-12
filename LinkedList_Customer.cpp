#include "LinkedList_Customer.h"
using namespace std;

// Constructor for LinkedList_Customer class
LinkedList_Customer::LinkedList_Customer() 
{
	firstNode = NULL;
	size = 0;
}

// Destructor for LinkedList_Customer class
LinkedList_Customer::~LinkedList_Customer() 
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

/*
	Add an order to the linked list.

	Parameters:
	- orderItem: Pointer to the Order object to be added.

	Return Value: True if the order is successfully added, false otherwise.
*/

bool LinkedList_Customer::addOrder(Order* orderItem) 
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
		curr->next = newNode;  // Adding the new node at the end of the list
	}
	size++;
	return true;
}

/* 
	Remove an order from the linked list.

	Parameters:
	- orderItem: Reference to the Order object to be removed.

	Return Value: True if the order is successfully removed, false if the order is not found.
*/
bool LinkedList_Customer::removeOrder(Order& orderItem) 
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

/*
	Get an order from the linked list based on its orderID.

	Parameters:
	- orderID: The ID of the order to retrieve.

	Return Value: Pointer to the Order object if found, NULL otherwise.
*/
Order* LinkedList_Customer::getOrderByOrderID(int orderID) 
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

/*
	Get an order from the linked list based on its index.

	Parameters:
	- index: Index of the order to retrieve.

	Return Value: Pointer to the Order object if found, NULL if index is out of bounds.
*/
Order* LinkedList_Customer::getOrderByIndex(int index)
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

/*
	Check if the order list is empty.

	Return Value: True if the order list is empty, false otherwise.
*/
bool LinkedList_Customer::orderListIsEmpty() 
{
	return size == 0;
}

/*
	Get the length of the linked list.
	Return Value: The number of orders in the linked list.
*/
int LinkedList_Customer::orderListGetLength() 
{
	return size;
}

// Print all orders in the linked list.
void LinkedList_Customer::orderListPrint() 
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