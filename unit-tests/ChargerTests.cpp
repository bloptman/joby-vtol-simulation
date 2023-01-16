#include "pch.h"

TEST(ChargerTests, Update)
{
	Charger c;                                                  
	Testing t;

	c.Update();
	EXPECT_EQ(c.GetQueueSize(), 0);

	c.AddToQueue(&t);
	t.SetState(AircraftState::WAITING);
	c.Update();

	EXPECT_EQ(t.GetState(), AircraftState::CHARGING);
	EXPECT_EQ(c.GetQueueSize(), 0);
}

TEST(ChargerTests, AddToQueue)
{
	Charger c;
	EXPECT_EQ(c.GetQueueSize(), 0);

	Testing t;
	c.AddToQueue(&t);
	EXPECT_EQ(c.GetQueueSize(), 1);
}

TEST(ChargerTests, LessThan)
{
	Charger c1;
	Charger c2;

	EXPECT_FALSE(c1 < c2);

	Testing t;

	c2.AddToQueue(&t);

	EXPECT_TRUE(c1 < c2);
}

TEST(ChargerTests, GetShortestQueue)
{
	Charger c1;
	Charger c2;
	Charger c3;

	std::vector<Charger> chargers = {c1, c2, c3};
	
	// If multiple Chargers have the same size queue the first one in the vector is 
	// considered the shortest.
	EXPECT_EQ(GetShortestChargerQueue(chargers), chargers.begin());

	Testing t;

	chargers[0].AddToQueue(&t);
	chargers[2].AddToQueue(&t);
	chargers[2].AddToQueue(&t);

	EXPECT_EQ(GetShortestChargerQueue(chargers), chargers.begin() + 1);
}
