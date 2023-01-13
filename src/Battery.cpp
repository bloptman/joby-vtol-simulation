#include "Battery.h"

Battery::Battery(float capacityInkWh, float chargeRatePerSec, float dischargeRatePerSec) :
	m_Capacity(capacityInkWh),
	m_ChargeLevel(capacityInkWh),
	m_ChargeRate(chargeRatePerSec),
	m_DischargeRate(dischargeRatePerSec)
{
	// Empty
}

void Battery::Charge()
{
	m_ChargeLevel = m_ChargeLevel + m_ChargeRate;

	// Battery cannot be charged over its capacity!
	if (m_ChargeLevel > m_Capacity)
	{
		m_ChargeLevel = m_Capacity;
	}
} 

void Battery::Discharge()
{
	// Battery cannot have less than zero charge!
	m_ChargeLevel = m_ChargeLevel - m_DischargeRate;

	if (m_ChargeLevel < 0.0f)
	{
		m_ChargeLevel = 0.0f;
	}
}

bool Battery::IsFull() const
{
	return m_ChargeLevel == m_Capacity;
}

bool Battery::IsDead() const
{
	return m_ChargeLevel == 0.0f;
}

float Battery::GetChargeLevel() const
{
	return m_ChargeLevel;
}

std::ostream& operator<<(std::ostream& os, const Battery& battery)
{
	os << "Charge Level: " << battery.GetChargeLevel() << std::endl;
	return os;
}