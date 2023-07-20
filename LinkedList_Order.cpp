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

bool LinkedList_Order::addFoodItem(FoodItem& foodItem)
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

bool LinkedList_Order::addFoodItem(int index, FoodItem foodItem)
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

void LinkedList_Order::removeFoodItem(int index)
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

FoodItem LinkedList_Order::getFoodItem(int index)
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
}

bool LinkedList_Order::FoodItemListisEmpty()
{
	return size == 0;
}

int LinkedList_Order::FoodItemListgetLength()
{
	return size;
}

void LinkedList_Order::FoodItemListprint()
{
	Node* curr = firstNode;

	while (curr != NULL)
	{
		FoodItem item = curr->foodItem;

		int foodID = item.getFoodID();
		string foodName = item.getFoodName();
		double price = item.getPrice();
		bool isAvail = item.getIsAvail();

		cout << "Food ID: " << foodID << endl;
		cout << "Food Name: " << foodName << endl;
		cout << "Price: " << price << endl;
		cout << "Is Available? " << isAvail << endl;
		cout << endl;

		curr = curr->next;
	}
	cout << endl;
}