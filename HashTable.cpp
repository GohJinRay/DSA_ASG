#include "HashTable.h"

// Constructor for Dictionary class
Dictionary::Dictionary() { 

    size = 0;

    for (int i = 0; i < MAX_SIZE; i++) {
        customers[i] = nullptr;
    }
}


// Deconstructor for Dictionary class
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


/*
   Hashing of key

   Parameters:
   - key: The key of the customer object.

   Return value:
   - hashValue: the hash value of the key
*/
int Dictionary::hash(KeyType key) { 

    int sum = 0;

    string name = key;

    for (char c : name) {
        sum += static_cast<int>(c); // Convert char to ASCII and add to sum
    }

    int hashValue = sum % MAX_SIZE;

    return hashValue;
}


/*
   Adding of Customer object into the Dictionary by using the key
   to indicate the position in the Dictionary

   Parameters:
   - newKey:   The key of the customer object.
   - customer: Customer object

   Return value:
   - True:  When its successfully added
   - False: When there's a duplicate key that exists in the Dictionary
*/
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


/*
   Removing of Customer object based on the key

   Parameters:
   - key:   The key of the customer object.

*/
void Dictionary::remove(KeyType key) { // remove customer based of key

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


/*
   Getting of Customer object based on the key

   Parameters:
   - Key:   The key of the customer object.

   Return value:
   - customer object
*/
Customer* Dictionary::get(KeyType key) { // get customer based of key

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


/*
   Getting of Customer object based on the their orderID

   Parameters:
   - orderID: ID of the order

   Return value:
   - customer object
*/
Customer* Dictionary::getCustomerByOrderID(int orderID) { // get the customer based off OrderID
    for (int i = 0; i < MAX_SIZE; i++) {
        Node* currNode = customers[i];
        while (currNode != nullptr) {
            LinkedList_Customer& orderList = currNode->item->getOrderList();
            Order* order = orderList.getOrderByOrderID(orderID);

            if (order != nullptr) {
                return currNode->item;
            }

            currNode = currNode->next;
        }
    }

    return nullptr;
}   

bool Dictionary::isEmpty() { // check if Dictionary is empty
    return size == 0;
}

int Dictionary::getLength() { // get Dictionary length
    return size;
}

void Dictionary::printAllOrders() { // print all orders via customer in the Dictionary
    for (int i = 0; i < MAX_SIZE; i++) {
        Node* curr = customers[i];
        while (curr != nullptr) {
            Customer* cust = curr->item;
            LinkedList_Customer& orderList = cust->getOrderList();

            for (int j = 0; j < orderList.orderListGetLength(); j++) {
                orderList.getOrderByIndex(j)->printOrder();
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