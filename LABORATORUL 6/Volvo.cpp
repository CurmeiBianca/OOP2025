#include "Volvo.h"

Volvo::Volvo() : Car()
{ }

double Volvo::getFuelCapacity()
{
	return 50.0; //capacitatea carburantului in litri
}

double Volvo::getFuelConsumption()
{
	return 8.0; //consum pe 100 de km
}

double Volvo::getAverageSpeed(Weather weather)
{
	if (weather == Weather::Rain)
	{
		return 80.0; //viteza medie in ploaie
	}
	else if (weather == Weather::Sunny)
	{
		return 120.0; //viteza medie pe vreme senina
	}
	else if (weather == Weather::Snow)
	{
		return 60.0; //viteza medie pe zapada
	}
}

const char* Volvo::getName()
{
	return "Volvo";
}
