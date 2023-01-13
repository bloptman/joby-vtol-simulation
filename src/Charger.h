#pragma once

#include <iostream>
#include <vector>
#include <queue>

class Aircraft;

class Charger
{
public:
	Charger();
	void Update();
	void AddToQueue(Aircraft* aircraft);

	int GetQueueSize() const;

	friend std::ostream& operator<<(std::ostream& os, const Charger& charger);

private:
	// Queue of Aircrafts waiting at the Charger.
	std::queue<Aircraft*> m_ChargingQueue;
};

// Returns an iterator to the Charger with the shortest queue.
std::vector<Charger>::iterator GetShortestChargerQueue(std::vector<Charger>& chargers);

// Comparison operator for Chargers.
bool operator<(const Charger& lhs, const Charger& rhs);