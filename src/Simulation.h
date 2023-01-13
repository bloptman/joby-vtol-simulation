#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include <string>
#include <algorithm>
#include "Charger.h"

class Aircraft;

class Simulation
{
public:
	Simulation(float durationInHours, int numberOfAircrafts);
	~Simulation();

	// Populates the simulation with the specified number of Aircrafts.
	void PopulateAircrafts(int numberOfAircrafts);

	// Creates an Aircraft depending on the provided value.
	Aircraft* CreateAircraft(float value);

	// Runs the simulation until completion.
	void Run();

	// Calculate results of the simulation.
	void CalculateResults();

	// Outputs the results of the simulation to the given file name.
	void OutputResults(std::string fileName);

	// Various Getters
	int GetRuntime() const;
	int GetDuration() const;
	std::vector<Aircraft*> GetAircrafts() const;
	std::vector<Charger> GetChargers() const;

private:

	void UpdateAircraftStates();
	void UpdateChargers();
	void UpdateAircraftData();

	int m_Runtime;
	int m_Duration;

	std::vector<Aircraft*> m_Aircrafts;
	std::vector<Aircraft*> m_PossibleAircrafts;
	std::vector<Charger> m_Chargers;

	friend std::ostream& operator<<(std::ostream& os, const Simulation& sim)
	{
		os << "Runtime Elapsed: " << sim.GetRuntime() << std::endl;
		return os;
	}
};


#endif // SIMULATION_H