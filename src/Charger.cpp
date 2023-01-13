#include "Charger.h"
#include "Aircraft.h"

std::set<Aircraft*> Charger::m_AircraftsAtChargers;

Charger::Charger()
{
	// Empty
}

void Charger::Update()
{
	if (m_ChargingQueue.empty())
	{
		return;
	}

	m_ChargingQueue.front()->SetState(AircraftState::CHARGING);

	if (m_ChargingQueue.front()->IsBatteryFull())
	{
		m_ChargingQueue.pop();
	}

	/*
	if (m_ChargingQueue.empty())
	{
		std::cout << "Charge is empty!" << std::endl;
		return;
	}

	else if (m_ChargingQueue.front()->IsBatteryFull())
	{
		std::cout << "Battery Full!" << std::endl;

		m_AircraftsAtChargers.erase(m_ChargingQueue.front());
		m_ChargingQueue.front()->SetChargingStatus(false);
		m_ChargingQueue.pop();

		if (!m_ChargingQueue.empty())
		{
			m_ChargingQueue.front()->SetChargingStatus(true);
			m_ChargingQueue.front()->SetWaitingStatus(false);
		}

		return;
	}

	m_ChargingQueue.front()->SetChargingStatus(true);
	m_ChargingQueue.front()->SetWaitingStatus(false);

	ChargeBattery(m_ChargingQueue.front());
	*/
}

void Charger::AddToQueue(Aircraft* aircraft)
{
	m_ChargingQueue.push(aircraft);
	//aircraft->SetWaitingStatus(true);
}

void Charger::ChargeBattery(Aircraft* aircraft)
{
	aircraft->ChargeBattery();
}

int Charger::GetQueueSize() const
{
	return m_ChargingQueue.size();
}

std::vector<Charger>::iterator GetShortestChargerQueue(std::vector<Charger>& chargers)
{

	return std::min_element(chargers.begin(), chargers.end());
}

bool operator<(const Charger& lhs, const Charger& rhs)
{
	return lhs.GetQueueSize() < rhs.GetQueueSize();
}

std::ostream& operator<<(std::ostream& os, const Charger& charger)
{
	os << "Queue size: " << charger.GetQueueSize() << std::endl;
	return os;
}