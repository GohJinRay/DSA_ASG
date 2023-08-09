#include "Admin.h"

Admin::Admin() { };

Admin::Admin(string UserName, string Password, int PhoneNum) : User(UserName, Password, PhoneNum) { };

void Admin::printDetails() // print admin details
{
	User::printDetails();
}

void Admin::viewOrders(Queue& q) // allow admin to view incoming orders
{
    // check for incoming orders
    if (q.isEmpty()) { 
        cout << "No incoming orders." << endl << endl;
        return;
    }
    cout << "Current orders in the queue: " << endl;
    q.displayItems();
}

void Admin::updateStatus(Queue& q) // allow admin to update orders in queue
{
    // check for incoming orders
    if (q.isEmpty()) {
        cout << "No incoming orders." << endl << endl;
        return;
    }
    viewOrders(q);

    int orderIdToUpdate;
    cout << "Enter the Order ID you want to update: ";
    cin >> orderIdToUpdate;

    Queue auxiliaryQueue;
    Order targetOrder;
    bool foundOrder = false;

    while (!q.isEmpty())
    {
        Order currOrder;
        q.getFront(currOrder);
        q.dequeue();

        if (currOrder.getOrderID() == orderIdToUpdate)
        {
            targetOrder = currOrder;
            foundOrder = true;
        }

        else
            auxiliaryQueue.enqueue(currOrder);
    }

    while (!auxiliaryQueue.isEmpty())
    {
        Order currOrder;
        auxiliaryQueue.getFront(currOrder);
        auxiliaryQueue.dequeue();
        q.enqueue(currOrder);
    }

    if (!foundOrder)
    {
        cout << "Order with ID " << orderIdToUpdate << " is not in the queue. Status update failed." << endl;
        return;
    }

    string prevStat = targetOrder.getStatus();
    targetOrder.setStatus(Prepared);

    // update the status of the corresponding order in the linked list
    LinkedList_Customer orderList = targetOrder.getCustomer()->getOrderList();
    Order* linkedOrder = orderList.getOrder(targetOrder.getOrderID());
    linkedOrder->setStatus(Prepared);

    cout << "Order ID " << targetOrder.getOrderID() << "'s status changed from " << prevStat << " -> " << targetOrder.getStatus() << " sucessfully!" << endl << endl;
}

void Admin::viewCustInfo(Dictionary& customerDictionary) // allow admin to view customer info via orderID
{   
    customerDictionary.printAllOrders();
    // Ask the admin to choose an order ID
    int chosenOrderID;
    cout << "Enter the Order ID you want to view customer info for: ";
    cin >> chosenOrderID;

    Customer* customer = customerDictionary.getCustomerByOrderID(chosenOrderID);
   
    if (customer != nullptr) {
        cout << "Customer Information:" << endl;
        customer->printDetails();
    }
    else {
        cout << "Order ID does not exist" << endl;
    }
}
