#pragma once
#include <iostream>

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
};

