#pragma once
#include "Customer.h"
using namespace std;

const int MAX_SIZE = 100;
typedef string KeyType;

class Dictionary {

private:
	struct Node
	{
		KeyType key;
		Customer* item;
		Node* next;
	};

	Node* customers[MAX_SIZE];
	int size;

public:
	Dictionary();
	~Dictionary();

	int hash(KeyType);

	bool add(KeyType, Customer*);
	void remove(KeyType);

	Customer* get(KeyType);
	Customer* getCustomerByOrderID(int);

	bool isEmpty();

	int getLength();

	void printAllOrders();
	void print();
};