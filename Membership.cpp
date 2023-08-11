#include "Membership.h"

Membership::Membership() { }

Membership::Membership(MembershipStatus MembershipStatus, int CurrLoyaltyPoints, int TotalLoyaltyPointsEarned)
{
	membershipStatus = MembershipStatus;
	currLoyaltyPoints = CurrLoyaltyPoints;
	totalLoyaltyPointsEarned = TotalLoyaltyPointsEarned;
}

void Membership::setMembershipStatus(MembershipStatus MembershipStatus) { membershipStatus = MembershipStatus; }

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

int Membership::getCurrentLoyaltyPoints() { return currLoyaltyPoints; }

int Membership::getTotalLoyaltyPointsEarned() { return totalLoyaltyPointsEarned; }

void Membership::addLoyaltyPoints(int loyaltyPoints)
{
	currLoyaltyPoints += loyaltyPoints;
	totalLoyaltyPointsEarned += loyaltyPoints;

	if (totalLoyaltyPointsEarned >= 1000 && membershipStatus == Silver)
		membershipStatus = Gold;

	else if (totalLoyaltyPointsEarned >= 200 && membershipStatus == Bronze)
		membershipStatus = Silver;

	else
		return;

	cout << "Congulations! You have attained the " << membershipStatus << "!" << endl;
}

void Membership::redeemLoyaltyPoints(Category& category1, Category& category2, Category& category3, Order& order, int loyaltyPoints)
{
	int option;
	cout << "---------- Point redemption ---------- " << endl;
	cout << "1. 10% discount off the order - 50 points" << endl;
	cout << "2. 20% discount off the order - 90 points" << endl;
	cout << "3. 30% discount off the order - 130 points" << endl;
	cout << "4. Nasi Lemak (Main Course) - 25 points" << endl;
	cout << "5. Coca-Cola (Drink) - 15 points" << endl;
	cout << "6. Mango Sticky Rice (Desserts) - 25 points" << endl << endl;
	cout << "Select option to redeem points (1, 2, 3, 4, 5 or 6): ";
	cin >> option;

	bool flag = false;

	if (option == 1)
		if (loyaltyPoints >= 50)
		{
			order.setTotalPrice(order.getTotalPrice() * (1 - 0.1));
			cout << "10% discount applied to the order." << endl;
			loyaltyPoints -= 50;
		}
		else
			flag = true;

	else if (option == 2)
		if (loyaltyPoints >= 90)
		{
			order.setTotalPrice(order.getTotalPrice() * (1 - 0.2));
			cout << "20% discount applied to the order." << endl;
			loyaltyPoints -= 90;
		}
		else
			flag = true;

	else if (option == 3)
		if (loyaltyPoints >= 130)
		{
			order.setTotalPrice(order.getTotalPrice() * (1 - 0.3));
			cout << "30% discount applied to the order." << endl;
			loyaltyPoints -= 130;
		}
		else
			flag = true;

	else if (option == 4)
		if (loyaltyPoints >= 25)
		{
			order.addFoodItem(category1.getCatArray().searchByFoodName("Nasi Lemak"));
			cout << "Nasi Lemak (Main course) has been added to the order" << endl;
			loyaltyPoints -= 25;
		}
		else
			flag = true;

	else if (option == 5)
		if (loyaltyPoints >= 15)
		{
			order.addFoodItem(category2.getCatArray().searchByFoodName("Coca-Cola"));
			cout << "Coca-Cola (Drink) has been added to the order" << endl;
			loyaltyPoints -= 15;
		}
		else
			flag = true;

	else if (option == 6)
		if (loyaltyPoints >= 25)
		{
			order.addFoodItem(category3.getCatArray().searchByFoodName("Mango Sticky Rice"));
			cout << "Mango Sticky Rice (Dessert) has been added to the order" << endl;
			loyaltyPoints -= 25;
		}
		else
			flag = true;

	else
		cout << "Invalid Option selected." << endl;
	
	if (flag == true)
		cout << "Insufficient loyalty points for this redemption." << endl;
}

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
