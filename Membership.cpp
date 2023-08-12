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

void Membership::redeemOption(Category& category1, Category& category2, Category& category3, Order& order, string& description, int requiredPoints)
{
	cout << description << " has been redeemed." << endl;

	if (description.find("discount") != string::npos) {
		double discountPercentage = 0.0;
		if (description.find("10%") != string::npos) discountPercentage = 0.1;
		else if (description.find("20%") != string::npos) discountPercentage = 0.2;
		else if (description.find("30%") != string::npos) discountPercentage = 0.3;

		order.setTotalPrice(order.getTotalPrice() * (1 - discountPercentage));
	}
	else {
		// Add food item based on description
		FoodItem foodItem;
		if (description == "Nasi Lemak (Main Course)") {
			foodItem = category1.getCatArray().searchByFoodName("Nasi Lemak");
		}
		else if (description == "Coca-Cola (Drink)") {
			foodItem = category2.getCatArray().searchByFoodName("Coca-Cola");
		}
		else if (description == "Mango Sticky Rice (Desserts)") {
			foodItem = category3.getCatArray().searchByFoodName("Mango Sticky Rice");
		}

		order.addFoodItem(foodItem);
		order.setTotalPrice(order.getTotalPrice() - foodItem.getPrice());
	}

	setCurrLoyaltyPoints(getCurrentLoyaltyPoints() - requiredPoints);
	cout << "Current Loyalty Points: " << getCurrentLoyaltyPoints() << endl;
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
	const int MAX_ITEMS = 6;

	string redemptionDescriptions[MAX_ITEMS] = {
		"10% discount off the order",
		"20% discount off the order",
		"30% discount off the order",
		"Nasi Lemak (Main Course)",
		"Coca-Cola (Drink)",
		"Mango Sticky Rice (Desserts)"
	};

	int redemptionPoints[MAX_ITEMS] = { 50, 90, 130, 25, 15, 25 };

	int option;

	while (true)
	{
		cout << endl;
		cout << "---------- Point redemption ---------- " << endl;
		for (int i = 0; i < MAX_ITEMS; i++) {
			cout << i + 1 << ". " << redemptionDescriptions[i] << " - " << redemptionPoints[i] << " points" << endl;
		}
		cout << "7. Exit" << endl << endl;

		cout << "Select option to redeem points: ";
		cin >> option;

		if (option >= 1 && option <= MAX_ITEMS)
		{
			int requiredPoints = redemptionPoints[option - 1];
			string description = redemptionDescriptions[option - 1];

			if (getCurrentLoyaltyPoints() >= requiredPoints) {
				redeemOption(category1, category2, category3, order, description, requiredPoints);
				break;
			}
			else {
				cout << "Insufficient loyalty points for this redemption." << endl << endl;
			}
		}
		else if (option == MAX_ITEMS + 1) { // Exit option
			return;
		}
		else {
			cout << "Invalid Option selected." << endl << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
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