#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include "Constants.h"
#include "AircraftDataStructs.h"

// Gets a random uniformly distribued floating point number 
// between [min, max).
float GetRandomNumber(float min, float max);

// Converts a given number of seconds to hours.
float SecondsToHours(int timeInSeconds);

// Calculates the average value of a given value.
float CalculateAverageValue(float val, int n);

// Converts a given probability of an event occuring per hour
// to the probability of the event occuring per second.
float ConvertProbability(float probabilityPerHour);

// Computes the nth root of value.
float Root(float value, float n);

// Converts the the members of an AircraftParameters object to the their
// corresponding values per second.
AircraftParameters ConvertParametersToSeconds(AircraftParameters parameters);

// Operators to help calculat the final results:
std::ostream& operator<<(std::ostream& os, const AircraftMetrics& metrics);
AircraftMetrics operator+(const AircraftMetrics& lhs, const AircraftMetrics& rhs);
AircraftMetrics operator/(const AircraftMetrics& metrics, int c);

#endif // UTILITY_H