#include "LinkedList_Order.h"
#include <iostream>
using namespace std;

LinkedList_Order::LinkedList_Order()
{ 
	firstNode = NULL;
	size = 0;
}

LinkedList_Order::~LinkedList_Order()
{ 
	Node* curr = firstNode;
	Node* next;
	while (curr != NULL)
	{
		next = curr->next;
		curr = NULL;
		delete curr;
		curr = next;
	}
	firstNode = NULL;
}

bool LinkedList_Order::addItem(FoodItem& foodItem)
{
	Node* newNode = new Node;
	newNode->foodItem = foodItem;
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

bool LinkedList_Order::addItem(int index, FoodItem& foodItem)
{
	if (index >= 0 && index <= size)
	{
		Node* newNode = new Node;
		newNode->foodItem = foodItem;
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

void LinkedList_Order::removeItem(int index)
{
	if (index >= 0 && index < size)
	{
		int counter = 0;
		Node* prev = firstNode;
		Node* curr = firstNode->next;

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

FoodItem LinkedList_Order::getItem(int index)
{
	if (index >= 0 && index < size)
	{
		int counter = 0;
		Node* curr = firstNode;

		while (curr->next != NULL && counter <= index)
		{
			curr = curr->next;
			counter++;
		}
		return curr->foodItem;
	}

	return FoodItem();
}

bool LinkedList_Order::isEmpty()
{
	return size == 0;
}

int LinkedList_Order::getLength()
{
	return size;
}

void LinkedList_Order::print()
{
	Node* curr = firstNode;

	while (curr != NULL)
	{
		FoodItem item = curr->foodItem;

		item.printFoodItem();
		cout << endl;

		curr = curr->next;
	}
	cout << endl;
}