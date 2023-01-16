#include "pch.h"

TEST(AircraftTests, Update)
{
	Testing t1;
	Testing t2;

	t2.Update();
	EXPECT_NE(t1.GetMetrics().m_TimeInFlight, t2.GetMetrics().m_TimeInFlight);

	t2.SetState(AircraftState::WAITING);
	t2.Update();
	EXPECT_NE(t1.GetMetrics().m_TimeWaiting, t2.GetMetrics().m_TimeWaiting);

	t2.SetState(AircraftState::CHARGING);
	t2.Update();
	EXPECT_NE(t1.GetMetrics().m_TimeCharing, t2.GetMetrics().m_TimeCharing);
}

TEST(AircraftTests, UpdateState)
{
	Testing t;
	std::vector<Charger> chargers;

	t.SetState(AircraftState::CHARGING);
	t.UpdateState(chargers);

	EXPECT_EQ(t.GetState(), AircraftState::FLYING);
}

TEST(AircraftTests, Charge)
{
	Testing t;

	t.Charge();
	EXPECT_EQ(t.GetMetrics().m_TimeCharing, 1);
}

TEST(AircraftTests, Wait)
{
	Testing t;

	t.Wait();
	EXPECT_EQ(t.GetMetrics().m_TimeWaiting, 1);
}

TEST(AircraftTests, Fly)
{
	Testing t;

	t.Fly();
	EXPECT_EQ(t.GetMetrics().m_TimeInFlight, 1);
}