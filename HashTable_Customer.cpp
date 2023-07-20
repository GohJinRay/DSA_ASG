#include "HashTable_Customer.h"
#include <iostream>
#include <string>

Dictionary::Dictionary() {
	size = 0;
	for (int i = 0; i < MAX_SIZE; i++) {
		items[i] = nullptr;
	}
}

Dictionary::~Dictionary() {
	for (int i = 0; i < MAX_SIZE; i++) {
		Node* currNode = items[i];
		while (currNode != nullptr) {
			Node* tempNode = currNode;
			currNode = currNode->next;
			delete tempNode;
		}
	}
}

int Dictionary::hash(KeyType key) {
    int sum = 0;

    string name = key;
    
    for (char c : name) {
        sum += static_cast<int>(c); // Convert char to ASCII and add to sum
    }

    int hashValue = sum % MAX_SIZE;

    return hashValue;
}

bool Dictionary::add(KeyType newKey, Customer customer) {
	int index = hash(newKey);

    Node* newNode = new Node;
    newNode->key = newKey;
    newNode->item= customer;
    newNode->next = nullptr;

    if (items[index] == nullptr) {
        items[index] = newNode;
    }
    else {
        Node* currNode = items[index];

        while (currNode->next != nullptr) {

            if (currNode->key == newKey) {
                delete newNode;
                return false;
            }
            currNode = currNode->next;
        }
        if (currNode->key == newKey) {
            delete newNode;
            return false;
        }
        currNode->next = newNode;
    }
    size++;
    return true;
}

void Dictionary::remove(KeyType key) {
    int index = hash(key);

    if (isEmpty()) { return; }
    else if (items[index] != nullptr) {

        Node* currNode = items[index];
        Node* prevNode = nullptr;
        while (currNode->key != key) {
            prevNode = currNode;
            currNode = currNode->next;
        }
        if (prevNode != nullptr) {
            prevNode->next = currNode->next;
        }
        else {
            items[index] = currNode->next;
        }
        delete currNode;
        size--;
    }
}

Customer Dictionary::get(KeyType key) {
        int index = hash(key);
    if (isEmpty()) {
        return ItemType();
    }

    Node* currNode = items[index];

    while (currNode != nullptr) {
        if (currNode->key == key) {
            return currNode->item;
        }
        currNode = currNode->next;
    }
    return ItemType();
}

bool Dictionary::isEmpty() {
	return size == 0;
}

int Dictionary::getLength() {
	return size;
}