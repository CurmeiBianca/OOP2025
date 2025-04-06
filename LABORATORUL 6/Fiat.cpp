#include "Fiat.h"

Fiat::Fiat() : Car()
{ }

double Fiat::getFuelCapacity()
{
	return 45.0;
}

double Fiat::getFuelConsumption()
{
	return 6.0;
}

double Fiat::getAverageSpeed(Weather weather)
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
		return 60.0;
	}
}

const char* Fiat::getName()
{
	return "Fiat";
}