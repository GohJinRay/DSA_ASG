#include "LinkedList_Customer.h"
#include "Order.h"
#include <iostream>
using namespace std;

LinkedList_Customer::LinkedList_Customer() 
{ 
	firstNode = NULL;
	size = 0;
}

LinkedList_Customer::~LinkedList_Customer() 
{
	/*Node* curr = firstNode;
	Node* next;
	while (curr != NULL)
	{
		next = curr->next;
		delete curr;
		curr = next;
	}*/
}

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
		curr->next = newNode;
	}
	size++;
	return true;
}

bool LinkedList_Customer::addOrder(int index, Order* orderItem)
{
	if (index >= 0 && index <= size)
	{
		Node* newNode = new Node;
		newNode->orderItem = orderItem;
		newNode->next = NULL;
		int counter = 0;

		if (index == 0)
		{
			newNode->next = firstNode;
			firstNode = newNode;
		}
		else
		{
			Node* curr = firstNode;
			while (curr->next != NULL && counter < index - 1)
			{
				curr = curr->next;
				counter++;
			}
			newNode->next = curr->next;
			curr->next = newNode;
		}
		size++;
		return true;
	}
	else
		return false;
}

void LinkedList_Customer::removeOrder(int index)
{
	if (index >= 0 && index < size)
	{
		int counter = 0;
		Node* curr = firstNode->next;
		Node* prev = firstNode;

		if (index == 0)
		{
			firstNode = prev->next;
			delete prev;
		}
		else
		{
			while (curr->next != NULL && counter < index - 1)
			{
				prev = curr;
				curr = curr->next;
				counter++;
			}
			prev->next = curr->next;
			delete curr;
		}
		size--;
	}
}

Order* LinkedList_Customer::getOrder(int index)
{
	if (index >= 0 && index < size)
	{
		int counter = 0;
		Node* curr = firstNode;

		while (curr->next != NULL && counter < index)
		{
			curr = curr->next;
			counter++;
		}
		return curr->orderItem;
	}
}

bool LinkedList_Customer::OrderListisEmpty()
{
	return size == 0;
}

int LinkedList_Customer::OrderListgetLength()
{
	return size;
}

void LinkedList_Customer::OrderListprint()
{
	Node* curr = firstNode;

	while (curr != NULL)
	{
		Order* order = curr->orderItem;
		int orderID = order->getOrderID();
		time_t orderDate = order->getOrderDate();
		string status = order->getStatus();

		cout << "Order ID: " << orderID << endl;
		cout << "Order Date: " << orderDate << endl;
		cout << "Status: " << status << endl << endl;
		
		order->getFoodItemList().FoodItemListprint();

		curr = curr->next;
	}
	cout << endl;
}