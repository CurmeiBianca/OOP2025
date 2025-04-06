#include "BMW.h"

BMW::BMW() : Car()
{ }

double BMW::getFuelCapacity()
{
	return 8.0;
}

double BMW::getFuelConsumption()
{
	return 10.0;
}

double BMW::getAverageSpeed(Weather weather)
{
	if (weather == Weather::Rain)
	{
		return 85.0;
	}
	else if (weather == Weather::Sunny)
	{
		return 130.0;
	}
	else if (weather == Weather::Snow)
	{
		return 70.0;
	}
}

const char* BMW::getName()
{
	return "BMW";
}
