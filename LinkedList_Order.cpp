#include "LinkedList_Order.h"
#include <iostream>
using namespace std;

// Constructor for LinkedList_Order class
LinkedList_Order::LinkedList_Order()
{ 
	firstNode = NULL;
	size = 0;
}

// Destructor for LinkedList_Order class
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

/*
   Add a food item to the linked list.

   Parameters:
   - foodItem: Reference to the FoodItem object to be added.

   Return Value: True if the food item is successfully added, false otherwise.
*/
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
		curr->next = newNode; // Add the new node to the end
	}
	size++;
	return true;
}

/*
   Remove a food item from the linked list based on its foodID.

   Parameters:
   - foodID: The ID of the food item to be removed.

   Return Value: True if the food item is successfully removed, false if not found.
*/
bool LinkedList_Order::removeItem(int foodID) 
{
	if (firstNode == NULL)
		return false;

	Node* prev = NULL;
	Node* curr = firstNode;

	while (curr != NULL)
	{
		if (curr->foodItem.getFoodID() == foodID)
		{
			if (prev == NULL)
				firstNode = curr->next; // Update the first node if the matching node is the first one
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

/*
   Retrieve a food item from the linked list based on its index.

   Parameters:
   - index: Index of the food item to retrieve.

   Return Value: The FoodItem object at the specified index, or a default FoodItem object if index is out of bounds.
*/
FoodItem LinkedList_Order::getItemByIndex(int index)
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
		return curr->foodItem; 
	}

	return FoodItem(); // Return a default FoodItem object if index is out of bounds
}

/*
   Retrieve a food item from the linked list based on its foodID.

   Parameters:
   - foodID: The ID of the food item to retrieve.

   Return Value: The FoodItem object with the specified foodID, or a default FoodItem object if not found.
*/
FoodItem LinkedList_Order::getItemByFoodID(int foodID) 
{
	Node* curr = firstNode;

	while (curr != NULL)
	{
		if (curr->foodItem.getFoodID() == foodID)
			return curr->foodItem;
		curr = curr->next;
	}

	return FoodItem(); // Return a default FoodItem object if not found
}

/*
   Check if the linked list is empty.

   Return Value: True if the linked list is empty, false otherwise.
*/
bool LinkedList_Order::isEmpty() 
{
	return size == 0;
}

/*
   Get the length of the linked list.

   Return Value: The number of items in the linked list.
*/
int LinkedList_Order::getLength() 
{
	return size;
}

// Print all the food items in the linked list
void LinkedList_Order::print() 
{
	Node* curr = firstNode;

	while (curr != NULL)
	{
		FoodItem item = curr->foodItem;
		item.printFoodItem(); // Print details of the food item

		curr = curr->next;
	}
}