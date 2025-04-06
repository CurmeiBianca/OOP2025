#include "RangeRover.h"

RangeRover::RangeRover() : Car()
{ }

double RangeRover::getFuelCapacity()
{
	return 6.5;
}

double RangeRover::getFuelConsumption()
{
	return 8.5;
}

double RangeRover::getAverageSpeed(Weather weather)
{
	if (weather == Weather::Rain)
	{
		return 70.0;
	}
	else if (weather == Weather::Sunny)
	{
		return 100.0;
	}
	else if (weather == Weather::Snow)
	{
		return 50.0;
	}
}

const char* RangeRover::getName()
{
	return "Range Rover";
}

