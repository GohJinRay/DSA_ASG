#include "Customer.h"

Customer::Customer() { }

Customer::Customer(string UserName, string Password, int PhoneNum, LinkedList_Customer OrderList)
	: User(UserName, Password, PhoneNum) 
{ 
	orderList = OrderList;
}

void Customer::printDetails()
{
	User::printDetails();
}

Order* Customer::createOrder(int orderID) 
{
	LinkedList_Order foodItemList;
	time_t now = time(0);
	char buffer[26]; // Use ctime_s to print human-readable date
	ctime_s(buffer, sizeof(buffer), &now);
	string currTime(buffer); //Convert to string format
	Order* newOrder = new Order(orderID, currTime, "Not Prepared", this, foodItemList);
	orderList.addOrder(newOrder);
	return newOrder;
}

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
			orderList.removeOrder(currOrder); //Remove order from linked list 
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

LinkedList_Customer Customer::getOrderList()
{
	return orderList;
}
