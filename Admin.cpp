#include "Admin.h"
#include "Queue.h"

Admin::Admin() { };

Admin::Admin(string UserName, string Password, int PhoneNum, bool IsAdmin) : User(UserName, Password, PhoneNum, IsAdmin) { };

void Admin::printDetails()
{
	User::printDetails();
}

void Admin::viewOrders(Queue& q)
{
    if (q.isEmpty()) { // check for incoming orders
        cout << "No incoming orders.";
        return;
    }
    q.displayItems();
}

bool Admin::updateStatus(Queue& q)
{
    if (q.isEmpty()) { // check for incoming orders
        cout << "No incoming orders.";
        return false;
    }

    Order order;
    Customer* customer;
    q.getFront(order); // get the first order 
    string prevStat = order.getStatus(); // saves the prev status
    order.setStatus("Prepared"); // set it to prepared

    customer = order.getCustomer(); // get customer from order
    order = customer->getOrder(); // changed the order from queue to order from Customer
    order.setStatus("Prepared"); // change it to prepared
    q.dequeue(); // remove it from the queue

    cout << "Order ID " << order.getOrderID() << " status changed from " << prevStat << " -> " << order.getStatus() << " sucessfully!" << endl;

    return true;
}

void Admin::viewCustInfo(Order& o)
{
    Customer* customer = o.getCustomer();
    string custName = customer->getUserName();
    int phoneNum = customer->getPhoneNum();

    cout << "----- Customer Information -----" << endl;
    cout << "Customer Name:         " << custName << endl;
    cout << "Customer Phone Number: " << phoneNum << endl;
}
