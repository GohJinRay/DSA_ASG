#include "Admin.h"

Admin::Admin() { };

Admin::Admin(string UserName, string Password, int PhoneNum) : User(UserName, Password, PhoneNum) { };

void Admin::printDetails()
{
	User::printDetails();
}

void Admin::viewOrders(Queue& q)
{
    if (q.isEmpty()) { // check for incoming orders
        cout << "No incoming orders." << endl << endl;
        return;
    }
    q.displayItems();
}

void Admin::updateStatus(Queue& q) // not done
{
    if (q.isEmpty()) { // check for incoming orders
        cout << "No incoming orders." << endl << endl;
        return;
    }

    Order order;
    q.getFront(order); // get the first order 
    string prevStat = order.getStatus(); // saves the prev status
    order.setStatus("Prepared"); // set it to prepared
    q.dequeue(); // remove it from the queue
    
    Order* order1;
    LinkedList_Customer orderList = order.getCustomer()->getOrderList();
    order1 = orderList.getOrder(0); // gets the order in linked list
    order1->setStatus("Prepared");

    cout << "Order ID " << order.getOrderID() << "'s status changed from " << prevStat << " -> " << order.getStatus() << " sucessfully!" << endl << endl;
}

void Admin::viewCustInfo(int orderID) // not done
{
    Order order;
    Customer* customer = order.getCustomer();
    customer->printDetails();
}
