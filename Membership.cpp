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

void Membership::redeemLoyaltyPoints(int loyaltyPoints)
{
	cout << "---------- Point redemption ---------- " << endl;
	cout << "1. 10% discount off the order - 50 points" << endl;
	cout << "2. 20% discount off the order - 90 points" << endl;
	cout << "3. 30% discount off the order - 130 points" << endl;
	cout << "4. Nasi Lemak - 15 points" << endl;
	cout << "5. Coca-Cola - 5 points" << endl;
	cout << "6. Mango Sticky Rice - 15 points" << endl << endl;
	cout << "Select option to redeem points (1, 2, 3, 4, 5 or 6): ";
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
