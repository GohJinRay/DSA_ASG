#include "Customer.h"

Customer::Customer() { }

Customer::Customer(string UserName, string Password, int PhoneNum, bool IsAdmin)
	: User(UserName, Password, PhoneNum, IsAdmin) { }

void Customer::printDetails()
{
	User::printDetails();
}

Order Customer::createOrder(int orderID) 
{
	LinkedList foodItemList;
	time_t now = time(0);
	char buffer[26]; // Use ctime_s to print human-readable date
	ctime_s(buffer, sizeof(buffer), &now);
	string currTime(buffer); //Convert to string format
	Order newOrder(orderID, currTime, "Not Prepared", this, foodItemList);
	return newOrder;
}

bool Customer::cancelOrder(Queue queue, int orderID) // not done
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
			foundOrder = true;
			cout << "Order with ID " << orderID << " has been canceled." << endl;
		}
		else
		{
			auxiliaryQueue.enqueue(currOrder);
		}
	}

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
