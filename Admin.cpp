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

//bool Admin::updateStatus(LinkedList_Customer& orderList, QueuePtr& q)
//{
//    if (q.isEmpty()) { // check for incoming orders
//        cout << "No incoming orders.";
//        return false;
//    }
//
//    Order order;
//    q.getFront(order); // get the first order 
//    string prevStat = order.getStatus();
//    order.setStatus("Prepared"); // set it to prepared
//    Order* order1;
//    order1 = orderList.getOrder(order.getOrderID()); // change the status in linked list
//    order1->setStatus("Prepared");
//    q.dequeue(); // remove it from the queue
//
//    cout << "Order ID " << order.getOrderID() << " status changed from " << prevStat << " -> " << order.getStatus() << " sucessfully!" << endl;
//
//    return true;
//}

bool Admin::updateStatus(Queue& q)
{
    if (q.isEmpty()) { // check for incoming orders
        cout << "No incoming orders.";
        return false;
    }

    Order order;
    Customer* customer;
    q.getFront(order); // get the first order 
    customer = order.getCustomer();
    string prevStat = order.getStatus();
    order.setStatus("Prepared"); // set it to prepared
    Order* order1;
    LinkedList_Customer orderList = customer->getOrderList();
    order1 = orderList.getOrder(order.getOrderID()); // change the status in linked list
    order1->setStatus("Prepared");
    q.dequeue(); // remove it from the queue

    cout << "Order ID " << order.getOrderID() << " status changed from " << prevStat << " -> " << order.getStatus() << " sucessfully!" << endl;

    return true;
}

void Admin::viewCustInfo(LinkedList_Customer& orderList, int orderID) // not done
{
    int numOrders = orderList.OrderListgetLength();

    if (numOrders == 0) {
        cout << "There is no order." << endl;
        return;
    }

    for (int i = 0; i < numOrders;i++) {
        Order* order = orderList.getOrder(i);
        if (orderID == order->getOrderID()) {
            string custName = order->getCustomer()->getUserName();
            int phoneNum = order->getCustomer()->getPhoneNum();

            cout << "----- Customer Information -----" << endl;
            cout << "Customer Name:         " << custName << endl;
            cout << "Customer Phone Number: " << phoneNum << endl;
        }
    }

}
