#include <algorithm>
#include "Admin.h"
#include "Order.h"
#include "HashTable_Customer.h"

Admin::Admin() { };

Admin::Admin(int UserID, string Name, string Password, int PhoneNum, bool IsAdmin) : User(UserID, Name, Password, PhoneNum, IsAdmin) { };

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

	return true;
}

void Admin::printDetails()
{
	User::printDetails();
}

void Admin::viewOrders(LinkedList_Customer& orderList)
{
	int numOrders = orderList.OrderListgetLength();

	if (numOrders == 0) {
		cout << "There are no orders currently." << endl;
		return;
	}


	for (int i = 0; i < numOrders; i++)
	{
		Order* order = orderList.getOrder(i);

		if (order->getStatus() == "Prepared") {
			return;
		}

		int orderID = order->getOrderID();
		time_t orderDate = order->getOrderDate();
		string status = order->getStatus();

		cout << "Order List:" << endl;
		cout << "Order ID: " << orderID << endl;
		// Use ctime_s to print human-readable date
		char buffer[26];
		ctime_s(buffer, sizeof(buffer), &orderDate);
		cout << "Order Date: " << buffer;
		cout << "Status: " << status << endl << endl;
	}
}

bool Admin::updateStatus(LinkedList_Customer& orderList)
{
    int numOrders = orderList.OrderListgetLength();

    if (numOrders == 0) {
        cout << "There is no order." << endl;
        return false;
    }

    int id;
    while (true) {
        cout << "Which Order Status would you like to update? (Enter Order ID) ";
        if (cin >> id) { // Check if the input is a valid integer

            // Sequential Search starts here
            Order* orderToUpdate = nullptr;
            for (int i = 0; i < numOrders; i++) {
                Order* order = orderList.getOrder(i);
                if (id == order->getOrderID()) {
                    orderToUpdate = order;
                    break;
                }
            }
            // Sequential Search ends here


            if (orderToUpdate == nullptr) { // checks if order with specified ID exists
                cout << "Order with ID " << id << " not found. Please enter a valid Order ID" << endl;
            }
            else {
                string status;
                while (true) {
                    cout << "Enter the updated status (Prepared/Not Prepared) (Enter -1 to go back): ";
                    cin >> status;

                    if (status == "-1") {
                        cout << "Going back..." << endl << endl;
                        break;
                    }

                    // Check if the input status is valid
                    if (status == "Prepared" || status == "Not Prepared") {
                        orderToUpdate->setStatus(status);
                        cout << "Status updated successfully!" << endl << endl;
                        return true;
                    }
                    else {
                        cout << "Invalid status. Please enter either 'Prepared' or 'Not Prepared'." << endl;
                    }
                }
            }
        }
        else {
            cout << "Invalid input. Please enter a valid Order ID" << endl;
            cin.clear(); // clear error flag, able to read I/O input again
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore remaining characters up to '\n'
        }
    }
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
            string custName = order->getCustomer().getName();
            int phoneNum = order->getCustomer().getPhoneNum();

            cout << "----- Customer Information -----" << endl;
            cout << "Customer ID:           " << custID << endl;
            cout << "Customer Name:         " << custName << endl;
            cout << "Customer Phone Number: " << phoneNum << endl;
        }
    }

}
