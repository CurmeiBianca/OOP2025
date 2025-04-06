#include "Circuit.h"

#include <stdlib.h>
#include <stdio.h>

Circuit::Circuit() : cars(nullptr), nrCars(0), lungime(0), weather(Weather::Sunny)
{ }

Circuit::~Circuit()
{
	//Eliberam memoria alocata pentru masini
	for (int i = 0; i < nrCars; i++)
		delete cars[i];
	delete[] cars; //eliberam si memoria pentru pointeri
}

void Circuit::setLungime(double lungime)
{
	this->lungime = lungime;
}

void Circuit::setWeather(Weather weather)
{
	this->weather = weather;
}

void Circuit::AddCar(Car* car)
{
	//Alocam mai multa memorie pentru masini
	Car** newCars = new Car * [nrCars + 1];

	//Copiem vechile masini
	for (int i = 0; i < nrCars; i++)
		newCars[i] = cars[i];

	//Adaugam noua masina
	newCars[nrCars] = car;

	//Eliberam vechea memorie si actualizam pointerul
	delete[] cars;
	cars = newCars;
	nrCars++;
}

void Circuit::Race()
{
	for (int i = 0; i < nrCars; i++)
	{
		double time = cars[i]->getTimeToFinish(lungime, weather);
		cars[i]->setRaceTime(time);
	}
}

void Circuit::ShowFinalRanks()
{
	//Sortam rezultatele in functie de timp (de la cel mai rapid la cel mai lent)
	for (int x = 0; x < nrCars - 1; x++)
		for (int y = 0; y < nrCars - 1 - x; y++)
			if (cars[y]->getRaceTime() > cars[y + 1]->getRaceTime())
			{
				//Schimbam elementele pentru a le ordona
				Car* aux = cars[y];
				cars[y] = cars[y + 1];
				cars[y + 1] = aux;
			}

	printf("Rezultatele finale ale cursei (pentru masinile care au terminat cursa): \n");
	for (int i = 0; i < nrCars; i++)
		if (cars[i]->getRaceTime() > 0)
			printf("->%s\n     -Timp: %.2f ore\n", cars[i]->getName(), cars[i]->getRaceTime());
}

void Circuit::ShowWhoDidNotFinish()
{
	printf("\n\nMasinile care nu au terminat cursa din cauza lipsei de combustibil: \n");
	for (int i = 0; i < nrCars; i++)
		if (cars[i]->getRaceTime() == -1)
		{
			double fuelNeeded = ((lungime / 100) * cars[i]->getFuelConsumption()) - cars[i]->getFuelCapacity();
			printf("->%s\n     -Volum necesar de combustibil pentru terminarea cursei: %.2f litri\n", cars[i]->getName(), fuelNeeded);
		}
}