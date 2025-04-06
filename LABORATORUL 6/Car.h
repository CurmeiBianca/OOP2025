#pragma once

#include "Weather.h"

class Car
{
protected:
	double raceTime; //timpul pentru a termina cursa

public:
	virtual ~Car() = default;

	virtual double getFuelCapacity() = 0; //capacitatea de carburant
	virtual double getFuelConsumption() = 0; //consum de carburant
	virtual double getAverageSpeed(Weather weather) = 0; //viteza medie in functie de conditiile meteo

	//Calculeaza timpul necesar pentru a parcurge o distanta
	double getTimeToFinish(double distance, Weather weather)
	{
		double speed = getAverageSpeed(weather);

		if (speed == 0)
			return -1; //daca viteza este 0, returneaza -1 (nu poate termina cursa)

		double fuelNeeded = (distance / 100) * getFuelConsumption();
		if (fuelNeeded > getFuelCapacity())
			return -1; //daca nu are suficien carburant, nu poate termina cursa

		return distance / speed;
	}

	void setRaceTime(double time)
	{
		raceTime = time;
	}

	double getRaceTime()
	{
		return raceTime;
	}

	virtual const char* getName() = 0;
};
