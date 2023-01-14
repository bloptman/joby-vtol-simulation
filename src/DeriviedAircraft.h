#ifndef DERIVED_AIRCRAFTS_H
#define DERIVED_AIRCRAFTS_H

#include "AircraftX.h"
#include "Constants.h"

// Derivied Aircraft Types:

class Alpha : public AircraftX<Alpha>
{
public:
	Alpha() : AircraftX(AircraftCharacteristics::Alpha::ConvertedParameters)
	{
		// Empty
	}
};

class Beta : public AircraftX<Beta>
{
public:
	Beta() : AircraftX(AircraftCharacteristics::Beta::ConvertedParameters)
	{
		// Empty
	}
};

class Charlie : public AircraftX<Charlie>
{
public:
	Charlie() : AircraftX(AircraftCharacteristics::Charlie::ConvertedParameters)
	{
		// Empty
	}
};

class Delta : public AircraftX<Delta>
{
public:
	Delta() : AircraftX(AircraftCharacteristics::Beta::ConvertedParameters)
	{
		// Empty
	}
};

class Echo : public AircraftX<Echo>
{
public:
	Echo() : AircraftX(AircraftCharacteristics::Echo::ConvertedParameters)
	{
		// Empty
	}
};

class Testing : public AircraftX<Testing>
{
public:
	Testing() : AircraftX(AircraftCharacteristics::Testing::TestParameters)
	{
		// Empty
	}
};

#endif // DERIVED_AIRCRAFTS_H