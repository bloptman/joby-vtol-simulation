#include <iostream>
#include <fstream>
#include <random>
#include "Simulation.h"
#include "Constants.h"
#include "Aircraft.h"
#include "DeriviedAircraft.h"

Simulation::Simulation(float durationInHours, int numberOfAircrafts):
	m_Chargers({Charger(), Charger(), Charger()}),
	m_PossibleAircrafts({ new Alpha(), new Beta(), new Charlie(), new Delta(), new Echo() })
{

	m_Duration = durationInHours * Time::SecondsInHour;
	PopulateAircrafts(numberOfAircrafts);
}

Simulation::~Simulation()
{
	// Deallocate all Aircraft pointers used during the simulation.
	for (auto aircraft : m_Aircrafts)
	{
		delete aircraft;
		aircraft = nullptr;
	}

	for (auto aircraft : m_PossibleAircrafts)
	{
		delete aircraft;
		aircraft = nullptr;
	}
}

void Simulation::PopulateAircrafts(int numberOfAircrafts)
{
	float randomNumber = 0;

	for (int i = 0; i < numberOfAircrafts; ++i)
	{
		randomNumber = GetRandomNumber(0.0f, 1.0f);
		m_Aircrafts.push_back(CreateAircraft(randomNumber));
	}
}

Aircraft* Simulation::CreateAircraft(float value)
{
	return new Testing();
	/*
	if (0.0f <= value && value < 0.2f)
	{
		//std::cout << "Creating Alpha" << std::endl;
		return new Alpha();
	}
	else if (0.2f <= value && value < 0.4f)
	{
		//std::cout << "Creating Beta" << std::endl;
		return new Beta();
	}
	else if (0.4f <= value && value < 0.6f)
	{
		//std::cout << "Creating Chalrie" << std::endl;
		return new Charlie();
	}
	else if (0.6f <= value && value < 0.8f)
	{
		//std::cout << "Creating Delta" << std::endl;
		return new Delta();
	}
	else
	{
		//std::cout << "Creating Echo" << std::endl;
		return new Echo();
	}
	*/
}

void Simulation::Run()
{
	std::cout << "Begining Simulation!" << std::endl;

	while (m_Runtime < m_Duration)
	{
		UpdateAircraftStates();
		UpdateChargers();
		UpdateAircraftData();

		++m_Runtime;
	}
}

void Simulation::UpdateAircraftStates()
{
	for (auto& aircraft : m_Aircrafts)
	{
		aircraft->UpdateState(m_Chargers);
	}
}

void Simulation::UpdateChargers()
{
	for (auto& charger : m_Chargers)
	{
		charger.Update();
	}
}

void Simulation::UpdateAircraftData()
{
	for (auto& aircraft : m_Aircrafts)
	{
		aircraft->Update();
	}
}

void Simulation::CalculateResults()
{
	for (auto aircraft : m_Aircrafts)
	{
		aircraft->CalculateTotalMetrics();
	}

	for (auto aircraft : m_PossibleAircrafts)
	{
		aircraft->CalculateAverageMetrics();
	}
}

void Simulation::OutputResults(std::string fileName)
{
	std::cout << "Simulation Complete!" << std::endl;
	std::cout << "Outputting results to " << fileName << "!" << std::endl;

	std::ofstream outputFile(fileName);

	/*for (auto aircraft : m_PossibleAircrafts)
	{
		aircraft->OutputResult(outputFile);
	}
	*/

	Aircraft* t = new Testing();
	t->OutputResult(outputFile);
	outputFile.close();
}

int Simulation::GetRuntime() const
{
	return m_Runtime;
}

int Simulation::GetDuration() const
{
	return m_Duration;
}

std::vector<Aircraft*> Simulation::GetAircrafts() const
{
	return m_Aircrafts;
}

std::vector<Charger> Simulation::GetChargers() const
{
	return m_Chargers;
}


