#include "Admin.h"

Admin::Admin() { };

Admin::Admin(string UserName, string Password, int PhoneNum, bool IsAdmin) : User(UserName, Password, PhoneNum, IsAdmin) { };

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

Order Admin::updateStatus(Queue& q)
{
    if (q.isEmpty()) { // check for incoming orders
        cout << "No incoming orders." << endl << endl;
        return Order(); //Return empty order object
    }

    Order order;
    q.getFront(order); // get the first order 
    string prevStat = order.getStatus(); // saves the prev status
    order.setStatus("Prepared"); // set it to prepared
    q.dequeue(); // remove it from the queue

    cout << "Order ID " << order.getOrderID() << "'s status changed from " << prevStat << " -> " << order.getStatus() << " sucessfully!" << endl << endl;

    return order;
}

void Admin::viewCustInfo(AVLTree avlTree, int orderID) // not done
{
    Order order;
    order = avlTree.search(orderID);
    Customer* customer = order.getCustomer();
    customer->printDetails();
}
