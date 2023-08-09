#include "HashTable.h"

Dictionary::Dictionary() {

    size = 0;

    for (int i = 0; i < MAX_SIZE; i++) {
        customers[i] = nullptr;
    }
}

Dictionary::~Dictionary() {

    for (int i = 0; i < MAX_SIZE; i++) {
        Node* currNode = customers[i];

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

bool Dictionary::add(KeyType newKey, Customer* customer) {

	int index = hash(newKey);

    Node* newNode = new Node;
    newNode->key = newKey;
    newNode->item = customer;
    newNode->next = nullptr;

    if (customers[index] == nullptr) {
        customers[index] = newNode;
    }

    else {
        Node* currNode = customers[index];

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

    if (isEmpty()) {
        cout << "No customers." << endl;
        return;
    }

    else if (customers[index] != nullptr) {

        Node* currNode = customers[index];
        Node* prevNode = nullptr;
        while (currNode->key != key) {
            prevNode = currNode;
            currNode = currNode->next;
        }
        if (prevNode != nullptr) {
            prevNode->next = currNode->next;
        }
        else {
            customers[index] = currNode->next;
        }
        delete currNode;
        size--;
    }
}

Customer* Dictionary::get(KeyType key) {

    int index = hash(key);

    if (isEmpty()) {
        return NULL;
    }

    Node* currNode = customers[index];

    while (currNode != nullptr) {

        if (currNode->key == key) {
            return currNode->item;
        }

        currNode = currNode->next;
    }
    return NULL;
}

Customer* Dictionary::getCustomerByOrderID(int orderID) {
    for (int i = 0; i < MAX_SIZE; i++) {
        Node* currNode = customers[i];
        while (currNode != nullptr) {
            LinkedList_Customer& orderList = currNode->item->getOrderList();
            Order* order = orderList.getOrder(orderID);

            if (order != nullptr) {
                return currNode->item;
            }

            currNode = currNode->next;
        }
    }

    return nullptr;
}   

bool Dictionary::isEmpty() {
    return size == 0;
}

int Dictionary::getLength() {
    return size;
}

void Dictionary::printAllOrders() {
    for (int i = 0; i < MAX_SIZE; i++) {
        Node* curr = customers[i];
        while (curr != nullptr) {
            Customer* cust = curr->item;
            LinkedList_Customer& orderList = cust->getOrderList();

            for (int j = 0; j < orderList.orderListGetLength(); j++) {
                orderList.orderListPrint();
            }
            curr = curr->next;
        }
    }
}

void Dictionary::print() {  // print all the customer belonging in the Dictionary
    for (int i = 0; i < MAX_SIZE; i++) {
        Node* curr = customers[i];
        while (curr != nullptr) {
            Customer* cust = curr->item;
            cust->printDetails();
            curr = curr->next;
        }
    }
}