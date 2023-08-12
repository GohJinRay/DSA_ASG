#include "Queue.h"

// Default constructor for Queue class
Queue::Queue() { };

// Destructor for Queue class
Queue::~Queue()
{
	while (!isEmpty())
	{
		dequeue();
	}
}

/*
   Enqueue an order item to the back of the queue.

   Input Parameters:
   - orderItem: The Order object to be enqueued.

   Return Value:
   Returns true after successfully enqueuing the order item.
*/
bool Queue::enqueue(Order& orderItem)
{
	Node* newNode = new Node;
	newNode->orderItem = orderItem;
	newNode->next = NULL;

	if (isEmpty())
	{
		frontNode = newNode;
	}

	else
	{
		backNode->next = newNode;
	}

	backNode = newNode;
	return true;
}

/*
   Dequeue an order item from the front of the queue.

   Return Value:
   Returns true after successfully dequeuing an order item.
   Returns false if the queue is empty.
*/
bool Queue::dequeue()
{
	if (isEmpty())
	{
		cout << "No nodes to dequeue!" << endl;
		return false;
	}

	else if (frontNode == backNode)
	{
		frontNode = NULL;
		backNode = NULL;

		delete frontNode;
	}

	else
	{
		Node* temp = frontNode;
		frontNode = frontNode->next;

		temp->next = NULL;
		delete temp;
	}
	return true;
}

/*
   Retrieve the order item at the front of the queue without dequeuing it.

   Input/Output Parameters:
   - orderItem: A reference to an Order object to store the front order item.
*/
void Queue::getFront(Order& orderItem) 
{
	if (!isEmpty())
		orderItem = frontNode->orderItem;

	else
	{
		// If the queue is empty, set a default Order object with an ID of -1
		orderItem.setOrderID(-1);
	}
}

/*
   Check if the queue is empty.

   Return Value:
   Returns true if the queue is empty, otherwise false.
*/
bool Queue::isEmpty()
{
	return (frontNode == NULL);
}

/*
   Display the details of all order items in the queue.
   Calls the printOrder() function for each order item to print the fooditems in the order too.
*/
void Queue::displayItems() 
{
	if (isEmpty())
	{
		cout << "Queue is empty!" << endl << endl;
	}

	else
	{
		Node* curr = frontNode;
		while (curr != NULL)
		{
			curr->orderItem.printOrder();
			curr = curr->next;
		}
	}
}