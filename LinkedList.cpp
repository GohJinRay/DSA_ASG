#include "LinkedList.h"

List::List() {
	firstNode = NULL;
	size = 0;
}

List::~List() {
	Node* current = firstNode;
	while (current != NULL) {
		Node* temp = current;
		current = current->next;
		delete temp;
	}
}

bool List::add(ItemType item) {
	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;

	if (isEmpty()) {
		firstNode = newNode;
	}
	else {
		Node* currentNode = firstNode;
		while (currentNode->next != NULL) {
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
	}
	size++;
	return true;
}

bool List::add(int index, ItemType item) {

	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;

	if (isEmpty()) {
		firstNode = newNode;
	}
	else {
		int x = 0;
		Node* currentNode = firstNode;
		while (currentNode->next != NULL && x < index) {
			currentNode = currentNode->next;
			x++;
		}
		currentNode->next = newNode;
		size++;

	}
	return true;
}

void List::remove(int index) {
	if (isEmpty()) {
		return;
	}

	// if index is 0, remove the first node
	if (index == 0) {
		Node* temp = firstNode;
		firstNode = firstNode->next;
		delete temp;
		size--;
	}

	else {
		Node* prevNode = firstNode;
		Node* currNode = firstNode->next;
		int x = 1;
		while (currNode->next != NULL && x < index) {
			prevNode = currNode;
			currNode = currNode->next;
			x++;
		}


	}
}

ItemType List::get(int index) {
	if (isEmpty()) {
		return ItemType();
	}
	else {
		int x = 0;
		Node* currNode = firstNode;
		while (currNode->next != NULL && x < index) {
			currNode = currNode->next;
			x++;
		}
		return currNode->item;
	}
}

bool List::isEmpty() {
	return firstNode == NULL;
}

int List::getLength()
{
	return size;
}

void List::print() {
	if (isEmpty()) {
		cout << "List is empty.\n";
		return;
	}

	Node* current = firstNode;
	while (current != NULL) {
		cout << current->item << " ";
		current = current->next;
	}
	cout << endl;
}