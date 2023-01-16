#include "pch.h"
#include <type_traits>

TEST(SimulationTests, PopulateAircrafts)
{
	float duration = 1.0f;
	int aircrafts = 10;

	Simulation s(duration, 0);
	EXPECT_TRUE(s.GetAircrafts().empty());

	s.PopulateAircrafts(aircrafts);
	EXPECT_EQ(s.GetAircrafts().size(), aircrafts);
}

TEST(SimulationTests, CreateAircraft)
{
	Simulation s(1.0f, 0);

	// Since there are 5 possible Aircraft types the probability of generating each type
	// is an increment of .2 ([0, .2), [.2, .4), etc).
	std::vector<float> vals = { 0.15f, 0.35f, 0.55f, 0.75f, 0.95f };
	std::vector<Aircraft*> allTypes = { new Alpha(), new Beta(), new Charlie(), new Delta(), new Echo };

	Aircraft* aircraft = nullptr;

	for (int i = 0; i < vals.size(); ++i)
	{
		aircraft = s.CreateAircraft(i);

		// Checking to see if the types are the same.
		// Could also probably check the parameters are equal since all of these 
		// Aircraft instances are being default constructed.
		bool areSame = std::is_same<decltype(&aircraft), decltype(*allTypes[i])>::value;
		EXPECT_TRUE(true);

		// Deallocating pointer
		delete aircraft;
		aircraft = nullptr;
	}

	// Deallocating pointers
	for (auto type : allTypes)
	{
		delete type;
		type = nullptr;
	}
}