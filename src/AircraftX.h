#ifndef AIRCRAFT_X_H
#define AIRCRAFT_X_H

#include <typeinfo>
#include "Aircraft.h"

// Using Curiosuly Recursive Template Pattern:

template <class X>
class AircraftX: public Aircraft
{
public:
	AircraftX(const AircraftParameters& params);

	//virtual void Update();

	virtual void CalculateTotalMetrics();
	virtual void CalculateAverageMetrics();
	virtual void OutputResult(std::ofstream& file) = 0;

	int GetNumberOfInstances() const;
	AircraftMetrics GetTotalMetrics() const;

protected:
	static int m_Instances;
	static AircraftMetrics m_TotalMetrics;
};

template <class X>
int AircraftX<X>::m_Instances = 0;

template <class X>
AircraftMetrics AircraftX<X>::m_TotalMetrics = AircraftMetrics();

template <class X>
AircraftX<X>::AircraftX(const AircraftParameters& params) : Aircraft(params)
{
	++m_Instances;
}

template <class X>
void AircraftX<X>::CalculateTotalMetrics()
{
	m_TotalMetrics = m_TotalMetrics + m_Metrics;
}

template <class X>
void AircraftX<X>::CalculateAverageMetrics()
{
	m_TotalMetrics = m_TotalMetrics / m_Instances;
}

/*
template <class X>
void AircraftX<X>::OutputResult(std::ofstream& file)
{
	file << typeid(X).name() << " Results: " << std::endl;
	file << m_TotalMetrics << std::endl;
}
*/

template <class X>
int AircraftX<X>::GetNumberOfInstances() const
{
	return m_Instances;
}

template <class X>
AircraftMetrics AircraftX<X>::GetTotalMetrics() const
{
	return m_TotalMetrics;
}

#endif