#include "pch.h"

TEST(UtilityTests, GetRandomNumber)
{
	float min = 0.0f;
	float max = 1.0f;

	float randomNum1 = GetRandomNumber(min, max);
	float randomNum2 = GetRandomNumber(min, max);

	// Very unlikely to get two values that are equal.
	EXPECT_NE(randomNum1, randomNum2);

	// Random value should be in the range [min, max).
	EXPECT_GE(randomNum1, min);
	EXPECT_LT(randomNum1, max);
}

TEST(UtilityTests, TimeConversion)
{
	float hours = 1.0f;
	int seconds = hours * Time::SecondsInHour;

	EXPECT_FLOAT_EQ(SecondsToHours(seconds), hours);
}

TEST(UtilityTests, CalculateAverage)
{
	float value = 0.0f;
	float x     = 5.0f;
	int i       = 0;

	for (i = 0; i < 10; ++i)
	{
		value = value + 5.0f;
	}

	EXPECT_FLOAT_EQ(CalculateAverageValue(value, i), x);
}

TEST(UtilityTests, CalculateProbability)
{
	// The answers will be very small so these are probably the easiest values to test.

	float probPerHour = 1.0f;
	EXPECT_FLOAT_EQ(ConvertProbability(probPerHour), 1.0f);

	probPerHour = 0.0f;
	EXPECT_FLOAT_EQ(ConvertProbability(probPerHour), 0.0f);
}

TEST(UtilityTests, ConvertParametersToSeconds)
{
	float speedInMPH = 1.0f;
	float batteryCapacity = 1.0f; // Shouldn't be converted since it does not depend on time in anyway.
	float chargingTimeInHours = 1.0f;
	float energyUsePerMile = 1.0f;
	int   passangers = 1;         // Shouldn't be converted since it does not depend on time in anyway.
	float faultProbPerHour = 1.0f;

	AircraftParameters params
	(
		speedInMPH,
		batteryCapacity,
		chargingTimeInHours,
		energyUsePerMile,
		passangers,
		faultProbPerHour
	);

	AircraftParameters convertedParams = ConvertParametersToSeconds(params);

	EXPECT_FLOAT_EQ(convertedParams.m_cruiseSpeed, 1.0f / Time::SecondsInHour);
	EXPECT_FLOAT_EQ(convertedParams.m_batteryCapacity, 1.0f);
	EXPECT_FLOAT_EQ(convertedParams.m_chargingRate, 1.0f / Time::SecondsInHour);
	EXPECT_FLOAT_EQ(convertedParams.m_energyUse, 1.0f / Time::SecondsInHour);
	EXPECT_EQ      (convertedParams.m_passangerCount, 1);
	EXPECT_FLOAT_EQ(convertedParams.m_faultProbability, 1.0f);
}

TEST(UtilityTests, Root)
{
	// When n = 2 we are just taking the square root.
	float n = 2.0f; 
	float value = 16.0f;
	
	EXPECT_FLOAT_EQ(Root(value, n), std::sqrt(value));
}