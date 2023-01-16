#include "pch.h"

TEST(BatteryTests, Discharge)
{
	float capacity = 1.0f;
	float chargeRate = 1.0f;
	float dischargeRate = 1.0f;

	Battery b(capacity, chargeRate, dischargeRate);

	b.Discharge();
	EXPECT_FALSE(b.IsFull());
	EXPECT_TRUE(b.IsDead());

	// Charge level should not go below zero.
	b.Discharge();
	EXPECT_EQ(b.GetChargeLevel(), 0);
}

TEST(BatteryTests, Charge)
{
	float capacity = 1.0f;
	float chargeRate = 1.0f;
	float dischargeRate = 1.0f;

	Battery b(capacity, chargeRate, dischargeRate);

	b.Discharge();
	EXPECT_TRUE(b.IsDead());

	b.Charge();
	EXPECT_TRUE(b.IsFull());
	EXPECT_FALSE(b.IsDead());
	
	// Charge level should not go above capacity.
	b.Charge();
	EXPECT_EQ(b.GetChargeLevel(), capacity);
}