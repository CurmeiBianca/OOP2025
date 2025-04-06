#include "Seat.h"

Seat::Seat() : Car()
{ }

double Seat::getFuelCapacity()
{
	return 40.0;
}

double Seat::getFuelConsumption()
{
	return 7.5;
}

double Seat::getAverageSpeed(Weather weather)
{
	if (weather == Weather::Rain)
	{
		return 75.0;
	}
	else if (weather == Weather::Sunny)
	{
		return 110.0;
	}
	else if (weather == Weather::Snow)
	{
		return 55.0;
	}
}

const char* Seat::getName()
{
	return "Seat";
}
