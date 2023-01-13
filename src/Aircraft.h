#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <iostream>
#include <fstream>

#include "Charger.h"
#include "AircraftDataStructs.h"
#include "Constants.h"
#include "Battery.h"

class Aircraft
{
public:
	Aircraft(const AircraftParameters& parameters);

	// Update Functions
	virtual void Update();
	void UpdateState(std::vector<Charger>& chargers);

	// Functions to calculate/output final results:
	virtual void CalculateTotalMetrics() = 0;
	virtual void CalculateAverageMetrics() = 0;
	virtual void OutputResult(std::ofstream& file) = 0;

	// Battery Managment Functions
	void ChargeBattery();
	void DischargeBattery();
	bool IsBatteryFull() const;
	bool IsBatteryDead() const;

	// Possible States of the Aircraft
	void Charge();
	void Wait();
	void Fly();


	void CheckForFault(float value);

	bool IsCharging() const;
	bool IsWaiting() const;

	void SetChargingStatus(bool status);
	void SetWaitingStatus(bool status);

	AircraftState GetState() const;
	void SetState(AircraftState newState);

	AircraftParameters GetParameters() const;

protected:
	AircraftMetrics m_Metrics;
	AircraftParameters m_Parameters;

private:
	AircraftState m_State;
	Battery m_Battery;
	float m_BatteryCharge;
	bool m_IsCharging;
	bool m_IsWaiting;
	friend std::ostream& operator<<(std::ostream& os, const Aircraft& aircraft);
};

#endif // AIRCRAFT_H