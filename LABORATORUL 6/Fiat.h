#pragma once

#include "Car.h"

class Fiat : public Car
{
public:
	//Constructor
	Fiat();

	double getFuelCapacity();
	double getFuelConsumption();
	double getAverageSpeed(Weather weather);

	const char* getName();
};

