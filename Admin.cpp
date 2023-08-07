#include "Admin.h"

Admin::Admin() { };

Admin::Admin(string UserName, string Password, int PhoneNum) : User(UserName, Password, PhoneNum) { };

void Admin::printDetails()
{
	User::printDetails();
}

void Admin::viewOrders(Queue& q)
{
    // check for incoming orders
    if (q.isEmpty()) { 
        cout << "No incoming orders." << endl << endl;
        return;
    }
    q.displayItems();
}

void Admin::updateStatus(Queue& q) 
{
    // check for incoming orders
    if (q.isEmpty()) { 
        cout << "No incoming orders." << endl << endl;
        return;
    }

    // Get the front order from the queue
    Order order;
    q.getFront(order); 
    OrderStatus prevStat = order.getStatus(); 

    // Update the status of the front order in the queue and dequeue it
    order.setStatus(Prepared);
    q.dequeue(); 
    
    // update the status of the corresponding order in the linked list
    LinkedList_Customer orderList = order.getCustomer()->getOrderList();
    Order* linkedOrder = orderList.getOrder(0); 
    linkedOrder->setStatus(Prepared);

    cout << "Order ID " << order.getOrderID() << "'s status changed from " << prevStat << " -> " << order.getStatus() << " sucessfully!" << endl << endl;
}

void Admin::viewCustInfo(int orderID) // not done
{
    Order order;
    Customer* customer = order.getCustomer();
    customer->printDetails();
}
