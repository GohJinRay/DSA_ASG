#pragma once
#include <iostream>
#include <string>
using namespace std;

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
	string getMembershipStatus();
	int getCurrentLoyaltyPoints();
	int getTotalLoyaltyPointsEarned();
	void addLoyaltyPoints(int);
	void redeemLoyaltyPoints(int);
	int calculatePointsEarned(double);
};

