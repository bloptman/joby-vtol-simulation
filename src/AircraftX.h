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
	virtual ~AircraftX();

	//virtual void Update();

	virtual void CalculateTotalMetrics();
	virtual void CalculateAverageMetrics();
	virtual void OutputResult(std::ofstream& file);

	static int GetNumberOfInstances();
	static AircraftMetrics GetTotalMetrics();

protected:
	static int m_Instances;
	static AircraftMetrics m_TotalMetrics;
};

// Start at -1 to account for the additional instance of the Aircraft type being 
// created to loop over all possible Aircraft types.
template <class X>
int AircraftX<X>::m_Instances = -1;

template <class X>
AircraftMetrics AircraftX<X>::m_TotalMetrics = AircraftMetrics();

template <class X>
AircraftX<X>::AircraftX(const AircraftParameters& params) : Aircraft(params)
{
	++m_Instances;
}

template<class X>
AircraftX<X>::~AircraftX()
{
	--m_Instances;
}

template <class X>
void AircraftX<X>::CalculateTotalMetrics()
{
	m_TotalMetrics = m_TotalMetrics + m_Metrics;
}

template <class X>
void AircraftX<X>::CalculateAverageMetrics()
{
	// If there are no instances of the class then calculating the average
	// does not make sense (division by zero).
	if (m_Instances > 0)
	{
		m_TotalMetrics = m_TotalMetrics / m_Instances;
	}
}


template <class X>
void AircraftX<X>::OutputResult(std::ofstream& file)
{
	file << typeid(X).name() << " Results: " << std::endl;
	file << "Total Instances: " << m_Instances << std::endl;
	file << m_TotalMetrics << std::endl;
}

template <class X>
int AircraftX<X>::GetNumberOfInstances()
{
	return m_Instances;
}

template <class X>
AircraftMetrics AircraftX<X>::GetTotalMetrics()
{
	return m_TotalMetrics;
}

#endif