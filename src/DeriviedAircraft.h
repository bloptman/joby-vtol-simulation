#ifndef DERIVED_AIRCRAFTS_H
#define DERIVED_AIRCRAFTS_H

#include "Aircraft.h"
#include "AircraftX.h"
#include "AircraftDataStructs.h"
#include "Constants.h"

// Derivied Aircraft Types:

class Alpha : public AircraftX<Alpha>
{
public:
	Alpha() : AircraftX(AircraftCharacteristics::Alpha::ConvertedParameters)
	{
		// Empty
	}

	virtual void OutputResult(std::ofstream& file);
};

class Beta : public AircraftX<Beta>
{
public:
	Beta() : AircraftX(AircraftCharacteristics::Beta::ConvertedParameters)
	{
		// Empty
	}
	virtual void OutputResult(std::ofstream& file);
};

class Charlie : public AircraftX<Charlie>
{
public:
	Charlie() : AircraftX(AircraftCharacteristics::Charlie::ConvertedParameters)
	{
		// Empty
	}
	virtual void OutputResult(std::ofstream& file);
};

class Delta : public AircraftX<Delta>
{
public:
	Delta() : AircraftX(AircraftCharacteristics::Beta::ConvertedParameters)
	{
		// Empty
	}
	virtual void OutputResult(std::ofstream& file);
};

class Echo : public AircraftX<Echo>
{
public:
	Echo() : AircraftX(AircraftCharacteristics::Echo::ConvertedParameters)
	{
		// Empty
	}
	virtual void OutputResult(std::ofstream& file);
};

class Testing : public AircraftX<Testing>
{
public:
	Testing() : AircraftX(AircraftCharacteristics::Testing::TestParameters)
	{
		// Empty
	}
	virtual void OutputResult(std::ofstream& file);
};
/*
class Alpha: public Aircraft
{
public:
	Alpha() : Aircraft(AircraftCharacteristics::Alpha::ConvertedParameters)
	{
		++m_NumberOfInstances;
	}


	static int GetNumberOfInstances()
	{
		return m_NumberOfInstances;
	}

private:
	static int m_NumberOfInstances;
};

class Beta : public Aircraft
{
public:
	Beta() : Aircraft(AircraftCharacteristics::Beta::ConvertedParameters)
	{
		++m_NumberOfInstances;
	}

	static int GetNumberOfInstances()
	{
		return m_NumberOfInstances;
	}

private:
	static int m_NumberOfInstances;
};

class Charlie : public Aircraft
{
public:
	Charlie() : Aircraft(AircraftCharacteristics::Charlie::ConvertedParameters)
	{
		++m_NumberOfInstances;
	}

	static int GetNumberOfInstances()
	{
		return m_NumberOfInstances;
	}

private:
	static int m_NumberOfInstances;
};

class Delta : public Aircraft
{
public:
	
	Delta() : Aircraft(AircraftCharacteristics::Delta::ConvertedParameters)
	{
		++m_NumberOfInstances;
	}

	static int GetNumberOfInstances()
	{
		return m_NumberOfInstances;
	}

private:
	static int m_NumberOfInstances;
};

class Echo : public Aircraft
{
public:
	Echo() : Aircraft(AircraftCharacteristics::Echo::ConvertedParameters)
	{
		++m_NumberOfInstances;
	}

	static int GetNumberOfInstances()
	{
		return m_NumberOfInstances;
	}

private:
	static int m_NumberOfInstances;
};
*/
#endif // DERIVED_AIRCRAFTS_H