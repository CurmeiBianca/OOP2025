#pragma once

#include "Car.h"

class Volvo : public Car
{
public:
	Volvo(); //constructor

	double getFuelCapacity();
	double getFuelConsumption();
	double getAverageSpeed(Weather weather);

	const char* getName();
};

