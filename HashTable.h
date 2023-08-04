#pragma once
#include "Customer.h"
using namespace std;

const int MAX_SIZE = 100;
typedef string KeyType;
typedef Customer ItemType;

class Dictionary {

private:
	struct Node
	{
		KeyType key;
		ItemType item;
		Node* next;
	};

	Node* customers[MAX_SIZE];
	int size;

public:

	// constructor
	Dictionary();

	// destructor
	~Dictionary();

	int hash(KeyType key);

	bool add(KeyType newKey, Customer customer);

	void remove(KeyType key);

	Customer get(KeyType key);

	bool isEmpty();

	int getLength();

	void print();
};