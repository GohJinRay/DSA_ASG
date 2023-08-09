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

	// constructor
	Dictionary();

	// destructor
	~Dictionary();

	int hash(KeyType key);

	bool add(KeyType newKey, Customer* customer);

	void remove(KeyType key);

	Customer* get(KeyType key);

	Customer* getCustomerByOrderID(int orderID);

	bool isEmpty();

	int getLength();

	void printAllOrders();

	void print();
};