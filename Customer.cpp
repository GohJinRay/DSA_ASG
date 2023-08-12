#include "Customer.h"

//Defaut constructor for Customer class
Customer::Customer() { } 

/*	
	Constructor to initialize Customer properties.

	Input Parameters:
	UserName: The username of the customer.
	Password: The password of the customer.
	PhoneNum: The phone number of the customer.
	Membership: The membership object of the customer.
	OrderList: The linked list of orders associated with the customer. 
*/
Customer::Customer(string UserName, string Password, int PhoneNum, Membership Membership, LinkedList_Customer OrderList)
	: User(UserName, Password, PhoneNum) 
{ 
	membership = Membership;
	orderList = OrderList;
}

// Print details of the customer
void Customer::printDetails() 
{
	User::printDetails();
	membership.printMembership();
}

/*
	Create a new order and add it to the order linked list associated with the customer.
	
	Input Parameters:
	orderID: The unique identifier for the order.
	
	Return Value:
	Pointer to the newly created Order object.
*/
Order* Customer::createOrder(int orderID) 
{
	time_t now = time(0);
	char buffer[26]; // Use ctime_s to print human-readable date
	ctime_s(buffer, sizeof(buffer), &now);
	string currTime(buffer); //Convert to string format

	Order* newOrder = new Order(orderID, currTime, NotPrepared, 0.0, this, LinkedList_Order());
	
	// Add the newly created order to the order list
	orderList.addOrder(newOrder);

	return newOrder;
}

/*
	Cancel an order and remove it from the order linked list associated with the customer.

	Input Parameters:
	queue: The queue containing incoming orders.
	orderID: The ID of the order to be cancelled.

	Return Value:
	Returns true if the order was found and cancelled, otherwise false.
*/
bool Customer::cancelOrder(Queue& queue, int orderID) 
{
	Queue auxiliaryQueue;
	bool foundOrder = false;

	while (!queue.isEmpty())
	{
		Order currOrder;
		queue.getFront(currOrder);
		queue.dequeue();

		if (currOrder.getOrderID() == orderID)
		{
			// Remove the cancelled order from the linked list of orders associated with the customer
			orderList.removeOrder(currOrder); 
			foundOrder = true;
			cout << "Order with ID " << orderID << " has been cancelled." << endl;
		}
		else
			auxiliaryQueue.enqueue(currOrder);
	}

	// Re-enqueue the remaining orders back to the original queue
	while (!auxiliaryQueue.isEmpty())
	{
		Order currOrder;
		auxiliaryQueue.getFront(currOrder);
		auxiliaryQueue.dequeue();
		queue.enqueue(currOrder);
	}

	if (!foundOrder)
		cout << "Order with ID " << orderID << " is not in the queue. Cancellation failed." << endl;

	return foundOrder;
}
	
/*
	Get the membership object of the customer.

	Return Value:
	Reference to the Membership object associated with the customer.
*/
Membership& Customer::getMembership() { return membership; }

/*
	Get the linked list of orders associated with the customer.

	Return Value:
	Reference to the LinkedList_Customer containing customer's orders.
*/
LinkedList_Customer& Customer::getOrderList() 
{
	return orderList;
}
