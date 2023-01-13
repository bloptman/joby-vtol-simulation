#include "Aircraft.h"

Aircraft::Aircraft(const AircraftParameters& parameters) :
	m_Parameters(parameters),
	m_IsCharging(false),
	m_IsWaiting(false),
	m_Battery(parameters.m_batteryCapacity, parameters.m_chargingRate, parameters.m_energyUse),
	m_State(AircraftState::FLYING)
{
	m_BatteryCharge = parameters.m_batteryCapacity;
}

void Aircraft::Update()
{
	// How the Aircraft is updated depends on what state it is in: 
	switch (m_State)
	{
		case AircraftState::WAITING:
		{
			Wait();
			break;
		}
		case AircraftState::CHARGING:
		{
			Charge();
			break;
		}
		case AircraftState::FLYING:
		{
			Fly();
			break;
		}
	}
}

void Aircraft::Wait()
{
	++m_Metrics.m_TimeWaiting;
}

void Aircraft::Charge()
{
	++m_Metrics.m_TimeCharing;
	m_Battery.Charge();
}

void Aircraft::Fly()
{
	++m_Metrics.m_TimeInFlight;
	m_Metrics.m_TotalDistanceTraveled = m_Metrics.m_TotalDistanceTraveled + (m_Parameters.m_cruiseSpeed * m_Parameters.m_passangerCount);
	CheckForFault(GetRandomNumber(0.0f, 1.0f));
	m_Battery.Discharge();
}

AircraftState Aircraft::GetState() const
{
	return m_State;
}

void Aircraft::SetState(AircraftState newState)
{
	m_State = newState;
}

void Aircraft::UpdateState(std::vector<Charger>& chargers)
{
	if (m_Battery.IsDead() && m_State != AircraftState::WAITING)
	{
		auto iter = GetShortestChargerQueue(chargers);
		iter->AddToQueue(this);

		SetState(AircraftState::WAITING);
	}

	else if (m_Battery.IsFull() && m_State == AircraftState::CHARGING)
	{
		SetState(AircraftState::FLYING);
	}
}

bool Aircraft::IsBatteryFull() const
{
	return m_Battery.IsFull();
	//return m_BatteryCharge == m_Parameters.m_batteryCapacity;
}

bool Aircraft::IsBatteryDead() const
{
	return m_BatteryCharge == 0.0f;
}

void Aircraft::CheckForFault(float value)
{
	if (0 <= value && value < m_Parameters.m_faultProbability)
	{
		++m_Metrics.m_NumberOfFaults;
	}
}

AircraftParameters Aircraft::GetParameters() const
{
	return m_Parameters;
}

std::ostream& operator<<(std::ostream& os, const Aircraft& aircraft)
{
	os << "Battery Charge: "   << aircraft.m_Battery.GetChargeLevel()        << std::endl;
	os << "Time in Flight: "   << aircraft.m_Metrics.m_TimeInFlight          << std::endl;
	os << "Distance Travled: " << aircraft.m_Metrics.m_TotalDistanceTraveled << std::endl;
	os << "Time Waiting: "     << aircraft.m_Metrics.m_TimeWaiting           << std::endl;
	os << "Time Charging: "    << aircraft.m_Metrics.m_TimeCharing           << std::endl;
	return os;
}