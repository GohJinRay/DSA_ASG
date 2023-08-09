#include "LinkedList_Order.h"
#include <iostream>
using namespace std;

LinkedList_Order::LinkedList_Order() // constructor
{ 
	firstNode = NULL;
	size = 0;
}

LinkedList_Order::~LinkedList_Order() // deconstructor
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

bool LinkedList_Order::addItem(FoodItem& foodItem) // add fooditem into linkedlist
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

bool LinkedList_Order::addItem(int index, FoodItem& foodItem) // add fooditem into linkedlist based on index
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

bool LinkedList_Order::removeItem(int foodID) // remove food item from linked list based on item id
{
	if (firstNode == NULL)
		return false;

	Node* prev = NULL;
	Node* curr = firstNode;

	while (curr != NULL)
	{
		if (curr->foodItem.getFoodID() == foodID)
		{
			if (prev == NULL) // if it's the first node
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
	cout << endl << "Food item with " << foodID << " not found in cart!" << endl;
	return false;
}

FoodItem LinkedList_Order::getItem(int index) // get fooditem via index
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

bool LinkedList_Order::isEmpty() // checks if linkedlist is empty
{
	return size == 0;
}

int LinkedList_Order::getLength() // get length of linkedlist
{
	return size;
}

void LinkedList_Order::print() // print all the fooditem in the linkedlist
{
	Node* curr = firstNode;

	while (curr != NULL)
	{
		FoodItem item = curr->foodItem;
		item.printFoodItem();

		curr = curr->next;
	}
	cout << endl;
}