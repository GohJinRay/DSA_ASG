#pragma once
#include <iostream>
#include <string>
#include "Order.h"
#include "Category.h"
using namespace std;

// Enumeration representing different membership status levels.
enum MembershipStatus
{
	Bronze,
	Silver,
	Gold
};

class Membership
{
private:
	MembershipStatus membershipStatus;
	int currLoyaltyPoints;
	int totalLoyaltyPointsEarned;

public:
	Membership();
	Membership(MembershipStatus, int, int);

	void setMembershipStatus(MembershipStatus);
	void setCurrLoyaltyPoints(int);
	void setTotalLoyaltyPointsEarned(int);
	string getMembershipStatus();
	int getCurrentLoyaltyPoints();
	int getTotalLoyaltyPointsEarned();
	void addLoyaltyPoints(double);
	void redeemOption(Category&, Category&, Category&, Order&, string&, int);
	void redeemLoyaltyPoints(Category&, Category&, Category&, Order&);
	int calculatePointsEarned(double);
	void printMembership();
};

