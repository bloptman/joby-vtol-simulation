#ifndef AIRCRAFT_DATA_STRUCTS_H
#define AIRCRAFT_DATA_STRUCTS_H

#include <algorithm>

struct AircraftParameters
{
	AircraftParameters
	(
		float cruiseSpeed,
		float batteryCapacity,
		float chargingTime,
		float energyUse,
		int passangerCount,
		float faultProbability
	) :
		m_cruiseSpeed(cruiseSpeed),
		m_batteryCapacity(batteryCapacity),
		m_energyUse(energyUse),
		m_passangerCount(passangerCount),
		m_faultProbability(faultProbability)
	{
		m_chargingRate = m_batteryCapacity / chargingTime;
	}

	float m_cruiseSpeed;
	float m_batteryCapacity;
	float m_chargingRate;
	float m_energyUse;
	int   m_passangerCount;
	float m_faultProbability;
};

struct AircraftMetrics
{
	AircraftMetrics() :
		m_TimeInFlight(0.0f),
		m_TimeCharing(0.0f),
		m_TimeWaiting(0.0f),
		m_NumberOfFaults(0),
		m_TotalDistanceTraveled(0.0f)
	{
		// Empty
	}

	float m_TimeInFlight;
	float m_TimeCharing;
	float m_TimeWaiting;
	int   m_NumberOfFaults;
	float m_TotalDistanceTraveled;
};

#endif // AIRCRAFT_DATA_STRUCTS_H