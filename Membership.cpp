#include "Membership.h"

// Default constructor for Membership class
Membership::Membership() { }

/*
   Constructor to initialize Membership attributes with provided values.

   Input Parameters:
   - MembershipStatus: The membership status (Bronze, Silver, Gold).
   - CurrLoyaltyPoints: The current loyalty points of the member.
   - TotalLoyaltyPointsEarned: The total loyalty points earned by the member.
*/
Membership::Membership(MembershipStatus MembershipStatus, int CurrLoyaltyPoints, int TotalLoyaltyPointsEarned)
{
	membershipStatus = MembershipStatus;
	currLoyaltyPoints = CurrLoyaltyPoints;
	totalLoyaltyPointsEarned = TotalLoyaltyPointsEarned;
}

// Set the membership status of the member.
void Membership::setMembershipStatus(MembershipStatus MembershipStatus) { membershipStatus = MembershipStatus; }

// Set the current loyalty points of the member.
void Membership::setCurrLoyaltyPoints(int LoyaltyPoints) { currLoyaltyPoints = LoyaltyPoints; }

// Set the total loyalty points earned by the member.
void Membership::setTotalLoyaltyPointsEarned(int LoyaltyPoints) { totalLoyaltyPointsEarned = LoyaltyPoints; }

// Retrieve the membership status as a string representation.
string Membership::getMembershipStatus()
{
	switch (membershipStatus)
	{
	case Bronze:
		return "Bronze";

	case Silver:
		return "Silver";

	case Gold:
		return "Gold";

	default:
		return "Unknown";
	}
}

// Retrieve the current loyalty points of the member.
int Membership::getCurrentLoyaltyPoints() { return currLoyaltyPoints; }

// Retrieve the total loyalty points earned by the member.
int Membership::getTotalLoyaltyPointsEarned() { return totalLoyaltyPointsEarned; }

/*
   Add loyalty points based on the total price of an order.

   Input Parameters:
   - totalPrice: The total price of an order.
*/
void Membership::addLoyaltyPoints(double totalPrice)
{
	// Calculate points earned based on membership status
	int pointsEarned = calculatePointsEarned(totalPrice);

	// Update current and total loyalty points earned
	setCurrLoyaltyPoints(pointsEarned + getCurrentLoyaltyPoints());
	setTotalLoyaltyPointsEarned(pointsEarned + getTotalLoyaltyPointsEarned());

	// Check for membership status upgrade
	if (getTotalLoyaltyPointsEarned() >= 1000 && getMembershipStatus() == "Silver")
	{
		setMembershipStatus(Gold);
		cout << "Congulations! You have attained the " << getMembershipStatus() << "!" << endl;
	}
		
	else if (getTotalLoyaltyPointsEarned() >= 200 && getMembershipStatus() == "Bronze")
	{
		setMembershipStatus(Silver);
		cout << "Congulations! You have attained the " << getMembershipStatus() << "!" << endl;
	}

	else
		return;
}

/*
   Redeem loyalty points for various rewards.

   Input Parameters:
   - category1: The first category of food items.
   - category2: The second category of food items.
   - category3: The third category of food items.
   - order: The order for which points are being redeemed.
*/
void Membership::redeemLoyaltyPoints(Category& category1, Category& category2, Category& category3, Order& order)
{
	int option;

	while (true)
	{
		cout << "---------- Point redemption ---------- " << endl;
		cout << "1. 10% discount off the order - 50 points" << endl;
		cout << "2. 20% discount off the order - 90 points" << endl;
		cout << "3. 30% discount off the order - 130 points" << endl;
		cout << "4. Nasi Lemak (Main Course) - 25 points" << endl;
		cout << "5. Coca-Cola (Drink) - 15 points" << endl;
		cout << "6. Mango Sticky Rice (Desserts) - 25 points" << endl;
		cout << "7. Exit" << endl << endl;
		cout << "Select option to redeem points (1, 2, 3, 4, 5, 6 or 7): ";
		cin >> option;

		bool flag = false;

		if (option == 1)
			if (getCurrentLoyaltyPoints() >= 50)
			{
				order.setTotalPrice(order.getTotalPrice() * (1 - 0.1));
				cout << "10% discount applied to the order." << endl;
				setCurrLoyaltyPoints(getCurrentLoyaltyPoints() - 50);
				cout << "Current Loyalty Points: " << getCurrentLoyaltyPoints() << endl;
				break;
			}
			else
				flag = true;

		else if (option == 2)
			if (getCurrentLoyaltyPoints() >= 90)
			{
				order.setTotalPrice(order.getTotalPrice() * (1 - 0.2));
				cout << "20% discount applied to the order." << endl;
				setCurrLoyaltyPoints(getCurrentLoyaltyPoints() - 90);
				cout << "Current Loyalty Points: " << getCurrentLoyaltyPoints() << endl;
				break;
			}
			else
				flag = true;

		else if (option == 3)
			if (getCurrentLoyaltyPoints() >= 130)
			{
				order.setTotalPrice(order.getTotalPrice() * (1 - 0.3));
				cout << "30% discount applied to the order." << endl;
				setCurrLoyaltyPoints(getCurrentLoyaltyPoints() - 130);
				cout << "Current Loyalty Points: " << getCurrentLoyaltyPoints() << endl;
				break;
			}
			else
				flag = true;

		else if (option == 4)
			if (getCurrentLoyaltyPoints() >= 25)
			{
				order.addFoodItem(category1.getCatArray().searchByFoodName("Nasi Lemak"));
				cout << "Nasi Lemak (Main course) has been added to the order." << endl;
				setCurrLoyaltyPoints(getCurrentLoyaltyPoints() - 25);
				order.setTotalPrice(order.getTotalPrice() - category1.getCatArray().searchByFoodName("Nasi Lemak").getPrice());
				cout << "Current Loyalty Points: " << getCurrentLoyaltyPoints() << endl;
				break;
			}
			else
				flag = true;

		else if (option == 5)
			if (getCurrentLoyaltyPoints() >= 15)
			{
				order.addFoodItem(category2.getCatArray().searchByFoodName("Coca-Cola"));
				cout << "Coca-Cola (Drink) has been added to the order." << endl;
				setCurrLoyaltyPoints(getCurrentLoyaltyPoints() - 15);
				order.setTotalPrice(order.getTotalPrice() - category1.getCatArray().searchByFoodName("Coca-Cola").getPrice());
				cout << "Current Loyalty Points: " << getCurrentLoyaltyPoints() << endl;
				break;
			}
			else
				flag = true;

		else if (option == 6)
			if (getCurrentLoyaltyPoints() >= 25)
			{
				order.addFoodItem(category3.getCatArray().searchByFoodName("Mango Sticky Rice"));
				cout << "Mango Sticky Rice (Dessert) has been added to the order." << endl;
				setCurrLoyaltyPoints(getCurrentLoyaltyPoints() - 25);
				order.setTotalPrice(order.getTotalPrice() - category1.getCatArray().searchByFoodName("Mango Sticky Rice").getPrice());
				cout << "Current Loyalty Points: " << getCurrentLoyaltyPoints() << endl;
				break;
			}
			else
				flag = true;

		else if (option == 7)
			break;

		else
		{
			cout << "Invalid Option selected." << endl << endl;
			cin.clear(); // Clear error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
		}

		if (flag == true)
		{
			cout << "Insufficient loyalty points for this redemption." << endl << endl;
		}
	}
}

/*
   Calculate points earned based on the total price of an order.

   Input Parameters:
   - totalPrice: The total price of an order.

   Return Value:
   The points earned based on the total price and membership status.
*/
int Membership::calculatePointsEarned(double totalPrice)
{
	int pointsEarned;
	if (membershipStatus == Bronze)
		pointsEarned = totalPrice;
	else if (membershipStatus == Silver)
		pointsEarned = totalPrice * 2;
	else
		pointsEarned = totalPrice * 3;

	cout << "Congulations! You have earned " << pointsEarned << " points!" << endl;
	return pointsEarned;
}


// Print the details of the membership status and loyalty points.
void Membership::printMembership()
{
	cout << "Membership Status: " << getMembershipStatus() << endl;
	cout << "Current Loyalty Points: " << getCurrentLoyaltyPoints() << endl;
	cout << "Total Loyalty Points Earned: " << getTotalLoyaltyPointsEarned() << endl;
}