#pragma once

#include "Car.h"
#include "Weather.h"

class Circuit
{
private:
	Car** cars; //tablou dinamic de pointeri la masini
	int nrCars = 0;

	double lungime;
	Weather weather;

public:
	Circuit(); //constructor
	~Circuit(); //destructor
	
	void setLungime(double lungime);
	void setWeather(Weather weather);
	void AddCar(Car* car);

	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

