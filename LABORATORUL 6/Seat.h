#pragma once

#include "Car.h"

class Seat : public Car
{
public:
	Seat(); //constructor

	double getFuelCapacity();
	double getFuelConsumption();
	double getAverageSpeed(Weather weather);

	const char* getName();
};

