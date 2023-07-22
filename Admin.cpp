#include "Admin.h"
#include "QueuePtr.h"

Admin::Admin() { };

Admin::Admin(int UserID, string FullName, string Password, int PhoneNum, bool IsAdmin) : User(UserID, FullName, Password, PhoneNum, IsAdmin) { };

bool Admin::login()
{
    string username, password;
    string expectedUsername = "Admin";
    string expectedPassword = "hehehehaw";

    cout << "Please enter your username: ";
    cin >> username;

    cout << "Please enter your password: ";
    cin >> password;

    if (username == expectedUsername && password == expectedPassword)
    {
        cout << "Login successful. Welcome, Admin!" << endl;
        return true;
    }

    else
    {
        cout << "Invalid username or password. Login failed." << endl;
        return false;
    }
}

void Admin::printDetails()
{
	User::printDetails();
}

void Admin::viewOrders(QueuePtr& q)
{
    if (q.isEmpty()) { // check for incoming orders
        cout << "No incoming orders.";
        return;
    }
    q.displayItems();
}

bool Admin::updateStatus(LinkedList_Customer& orderList, QueuePtr& q)
{
    if (q.isEmpty()) { // check for incoming orders
        cout << "No incoming orders.";
        return false;
    }

    Order order;
    q.getFront(order); // get the first order 
    string prevStat = order.getStatus();
    order.setStatus("Prepared"); // set it to prepared
    Order* order1;
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
            int custID = order->getCustomer().getUserID();
            string custName = order->getCustomer().getFullName();
            int phoneNum = order->getCustomer().getPhoneNum();

            cout << "----- Customer Information -----" << endl;
            cout << "Customer ID:           " << custID << endl;
            cout << "Customer Name:         " << custName << endl;
            cout << "Customer Phone Number: " << phoneNum << endl;
        }
    }

}
