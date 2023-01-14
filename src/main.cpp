#include <iostream>
#include <string>
#include "Simulation.h"

int main()
{
	const float simulationDurationInHours = 3.0f;
	const int numberOfAircraft =  20;
	const std::string outputFile = "results.txt";

	Simulation simulation(simulationDurationInHours, numberOfAircraft);

	simulation.Run();
	simulation.CalculateResults();
	simulation.OutputResults(outputFile);

	return 0;
}