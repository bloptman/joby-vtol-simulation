#include "Charger.h"
#include "Aircraft.h"

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
}

void Charger::AddToQueue(Aircraft* aircraft)
{
	m_ChargingQueue.push(aircraft);
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