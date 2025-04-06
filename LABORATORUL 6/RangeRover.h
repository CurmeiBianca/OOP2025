#pragma once

#include "Car.h"

class RangeRover : public Car
{
public:
	RangeRover(); //constructor

	double getFuelCapacity();
	double getFuelConsumption();
	double getAverageSpeed(Weather weather);

	const char* getName();
};

