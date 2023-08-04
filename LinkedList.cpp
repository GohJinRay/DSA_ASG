#include "LinkedList.h"
#include <iostream>
using namespace std;


LinkedList::LinkedList()
{ 
	firstNode = NULL;
	size = 0;
}

LinkedList::~LinkedList() 
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

bool LinkedList::addItem(ItemType& foodItem)
{
	Node* newNode = new Node;
	newNode->item = foodItem;
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

bool LinkedList::addItem(int index, ItemType foodItem)
{
	if (index >= 0 && index <= size)
	{
		Node* newNode = new Node;
		newNode->item = foodItem;
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

void LinkedList::removeItem(int index)
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

ItemType LinkedList::getItem(int index)
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
		return curr->item;
	}
}

bool LinkedList::isEmpty()
{
	return size == 0;
}

int LinkedList::getLength()
{
	return size;
}

void LinkedList::print()
{
	Node* curr = firstNode;

	while (curr != NULL)
	{
		curr->item.printFoodItem();
		curr = curr->next;
	}
}