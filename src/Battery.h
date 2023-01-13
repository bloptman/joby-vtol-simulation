#ifndef BATTERY_H
#define BATTERY_H

#include <iostream>

class Battery
{
public:
	Battery(float cpacityInkWh, float chargeRatePerSec, float dischargeRatePerSec);

	void Charge();
	void Discharge();

	bool IsFull() const;
	bool IsDead() const;

	float GetChargeLevel() const;

private:
	float m_Capacity;
	float m_ChargeLevel;
	float m_ChargeRate;
	float m_DischargeRate;
	friend std::ostream& operator<<(std::ostream& os, const Battery& battery);
};



#endif // BATTERY_H