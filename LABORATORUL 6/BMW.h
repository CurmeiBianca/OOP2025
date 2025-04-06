#pragma once

#include "Car.h"

class BMW : public Car
{
public:
	BMW(); //constructor

	double getFuelCapacity();
	double getFuelConsumption();
	double getAverageSpeed(Weather weather);

	const char* getName();
};

