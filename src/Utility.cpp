#include <random>
#include <cmath>
#include "Utility.h"

float GetRandomNumber(float min = 0.0f, float max = 1.0f)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(min, max);

	return dis(gen);
}

float SecondsToHours(int timeInSeconds)
{
	return timeInSeconds / Time::SecondsInHour;
}

float CalculateAverageValue(float value, int n)
{
	return value / n;
}

float ConvertProbability(float probabilityPerHour)
{
	// This conversion assumes each fault is an independent event.
	// Derivation of conversion here: https://math.stackexchange.com/questions/357242/calculating-probabilities-over-different-time-intervals

	float convertedProb = -1.0f * (probabilityPerHour - 1.0f);
	convertedProb = Root(convertedProb, Time::SecondsInHour);
	convertedProb = 1 - convertedProb;

	return convertedProb;
}

float Root(float value, float n)
{
	return std::pow(value, 1.0f / n);
}

AircraftParameters ConvertParametersToSeconds(AircraftParameters parameters)
{
	float CruiseSpeedPerSecond = parameters.m_cruiseSpeed / Time::SecondsInHour;         // Miles-Per-Second
	float ChargingRatePerSecond = (parameters.m_chargingRate) / Time::SecondsInHour;     // Seconds
	float EnergyUsePerSecond = parameters.m_energyUse * CruiseSpeedPerSecond;            // KWh/Second
	float FaultProbabilityPerSecond = ConvertProbability(parameters.m_faultProbability); // %/Second

	AircraftParameters convertedParameters = parameters;

	convertedParameters.m_cruiseSpeed = CruiseSpeedPerSecond;
	convertedParameters.m_chargingRate = ChargingRatePerSecond;
	convertedParameters.m_energyUse = EnergyUsePerSecond;
	convertedParameters.m_faultProbability = FaultProbabilityPerSecond;

	return convertedParameters;
}

std::ostream& operator<<(std::ostream& os, const AircraftMetrics& metrics)
{
	os << "Distance Traveled: "     << metrics.m_TotalDistanceTraveled << " miles"   << std::endl;
	os << "Time in Flight: "        << metrics.m_TimeInFlight          << " seconds" << std::endl;
	os << "Time Waiting: "          << metrics.m_TimeWaiting           << " seconds" << std::endl;
	os << "Time Charging: "         << metrics.m_TimeCharing           << " seconds" << std::endl;
	os << "Max Number of Faults: "  << metrics.m_NumberOfFaults        << std::endl;

	return os;
}

// Operators to help calculate the final results:

AircraftMetrics operator+(const AircraftMetrics& lhs, const AircraftMetrics& rhs)
{
	AircraftMetrics result;

	result.m_TotalDistanceTraveled = lhs.m_TotalDistanceTraveled + rhs.m_TotalDistanceTraveled;
	result.m_TimeInFlight =  lhs.m_TimeInFlight + rhs.m_TimeInFlight;
	result.m_TimeWaiting  =  lhs.m_TimeWaiting  + rhs.m_TimeWaiting;
	result.m_TimeCharing  =  lhs.m_TimeCharing  + rhs.m_TimeCharing;
	result.m_NumberOfFaults = std::max(lhs.m_NumberOfFaults, rhs.m_NumberOfFaults);

	return result;
}

AircraftMetrics operator/(const AircraftMetrics& metrics, int c)
{
	AircraftMetrics result;

	result.m_TotalDistanceTraveled = metrics.m_TotalDistanceTraveled / c;
	result.m_TimeInFlight = metrics.m_TimeInFlight / c;
	result.m_TimeWaiting = metrics.m_TimeWaiting / c;
	result.m_TimeCharing = metrics.m_TimeCharing / c;
	result.m_NumberOfFaults = metrics.m_NumberOfFaults;

	return result;
}