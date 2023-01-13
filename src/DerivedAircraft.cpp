#include "DeriviedAircraft.h"

void Alpha::OutputResult(std::ofstream& file)
{
	file << "Alpha Results: " << std::endl;
	file << "Number of Instances: " << Alpha::m_Instances << std::endl;
	file << Alpha::m_TotalMetrics << std::endl;
}

void Beta::OutputResult(std::ofstream& file)
{
	file << "Beta Results: " << std::endl;
	file << "Number of Instances: " << Beta::m_Instances << std::endl;
	file << Beta::m_TotalMetrics << std::endl;
}

void Charlie::OutputResult(std::ofstream& file)
{
	file << "Charlie Results: " << std::endl;
	file << "Number of Instances: " << Charlie::m_Instances << std::endl;
	file << Charlie::m_TotalMetrics << std::endl;
}

void Delta::OutputResult(std::ofstream& file)
{
	file << "Delta Results: " << std::endl;
	file << "Number of Instances: " << Delta::m_Instances << std::endl;
	file << Delta::m_TotalMetrics << std::endl;
}

void Echo::OutputResult(std::ofstream& file)
{
	file << "Echo Results: " << std::endl;
	file << "Number of Instances: " << Echo::m_Instances << std::endl;
	file << Echo::m_TotalMetrics << std::endl;
}

void Testing::OutputResult(std::ofstream& file)
{
	file << "Testing Results: " << std::endl;
	file << "Number of Instances: " << Testing::m_Instances << std::endl;
	file << Testing::m_TotalMetrics << std::endl;
}