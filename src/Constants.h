#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <vector>
#include "AircraftDataStructs.h"
#include "Utility.h"

// Could not find identifier for this function for some reason.
// Requires further investigation.
AircraftParameters ConvertParametersToSeconds(AircraftParameters parameters);

class Aircraft;

const int NUMBER_OF_AIRCRAFT_TYPES = 5;
const int NUMBER_OF_CHARGERS = 3;

enum class AircraftType
{
	NONE,
	ALPHA, 
	BETA,
	CHARLIE,
	DETLA,
	ECHO,
};

enum class AircraftState
{
	WAITING,
	CHARGING,
	FLYING
};

// Conversion factors for common units of time.
namespace Time
{
	const int SecondsInMinute = 60;
	const int MinutesInHour   = 60;
	const int SecondsInHour   = 3600;
}

// Namespaces defining the various characteristics of each companies
// eVTOL aircraft as given in the assignment specification.

// Note: A better approach might be to instead keep this information in
// configuration files and read that data in at runtime.

// Cruise Speed: Miles-Per-Hour (MPH)
// Battery Capacity: Kilowatt-Hour (kWh)
// Time to Charge: Hours
// Energy Use: KWh/Mile
// Passanger Count: #
// Probability of Fault Per Hour: %/Hour

namespace AircraftCharacteristics
{
	namespace Alpha
	{
		const float CruiseSpeed = 120.0f;
		const float BatteryCapacity = 320.0f;
		const float ChargingTime = 0.6f;
		const float EnergyUse = 1.6f;
		const int   PassangerCount = 4;
		const float FaultProbability = 0.25f;

		const AircraftParameters Parameters
		(
			CruiseSpeed,
			BatteryCapacity,
			ChargingTime,
			EnergyUse,
			PassangerCount,
			FaultProbability
		);

		const AircraftParameters ConvertedParameters = ConvertParametersToSeconds(Parameters);
	}

	namespace Beta
	{
		const float CruiseSpeed = 100.0f;
		const float BatteryCapacity = 100.0f;
		const float ChargingTime = 0.2f;
		const float EnergyUse = 1.5f;
		const int   PassangerCount = 5;
		const float FaultProbability = 0.10f;

		const AircraftParameters Parameters
		(
			CruiseSpeed,
			BatteryCapacity,
			ChargingTime,
			EnergyUse,
			PassangerCount,
			FaultProbability
		);
		
		const AircraftParameters ConvertedParameters = ConvertParametersToSeconds(Parameters);
	}

	namespace Charlie
	{
		const float CruiseSpeed = 160.0f;
		const float BatteryCapacity = 220.0f;
		const float ChargingTime = 0.8f;
		const float EnergyUse = 2.2f;
		const int   PassangerCount = 3;
		const float FaultProbability = 0.05f;

		const AircraftParameters Parameters
		(
			CruiseSpeed,
			BatteryCapacity,
			ChargingTime,
			EnergyUse,
			PassangerCount,
			FaultProbability
		);

		const AircraftParameters ConvertedParameters = ConvertParametersToSeconds(Parameters);
	}

	namespace Delta
	{
		const float CruiseSpeed = 90.0f;
		const float BatteryCapacity = 120.0f;
		const float ChargingTime = 0.62f;
		const float EnergyUse = 0.8f;
		const int   PassangerCount = 2;
		const float FaultProbability = 0.22f;

		const AircraftParameters Parameters
		(
			CruiseSpeed,
			BatteryCapacity,
			ChargingTime,
			EnergyUse,
			PassangerCount,
			FaultProbability
		);

		const AircraftParameters ConvertedParameters = ConvertParametersToSeconds(Parameters);
	}

	namespace Echo
	{
		const float CruiseSpeed = 30.0f;
		const float BatteryCapacity = 150.0f;
		const float ChargingTime = 0.3f;
		const float EnergyUse = 5.8f;
		const int   PassangerCount = 2;
		const float FaultProbability = 0.61f;

		const AircraftParameters Parameters
		(
			CruiseSpeed,
			BatteryCapacity,
			ChargingTime,
			EnergyUse,
			PassangerCount,
			FaultProbability
		);

		const AircraftParameters ConvertedParameters = ConvertParametersToSeconds(Parameters);
	}

	namespace Testing
	{
		const float CruiseSpeed = 1.0f;
		const float BatteryCapacity = 3600.0f;
		const float ChargingTime = 3600.0f;
		const float EnergyUse = 1.0f;
		const int   PassangerCount = 2;
		const float FaultProbability = 0.5f;

		const AircraftParameters TestParameters
		(
			CruiseSpeed,
			BatteryCapacity,
			ChargingTime,
			EnergyUse,
			PassangerCount,
			FaultProbability
		);
	}
}

#endif // CONSTNATS_H