#include "Circuit.h"
#include "Volvo.h"
#include "BMW.h"
#include "Seat.h"
#include "Fiat.h"
#include "RangeRover.h"

#include <stdlib.h>
#include <stdio.h>

int main()
{
	Circuit c;
	c.setLungime(100);
	c.setWeather(Weather::Snow);

	Weather weather = Weather::Snow;

	printf("   Caracteristicile circuitului: \n->distanta : %.2f km\n", 100.0);
	if (weather == Weather::Rain)
		printf("->Vremea pe care se desfasoara cursa : ploaie\n\n");
	else if (weather == Weather::Snow)
		printf("->Vremea pe care se desfasoara cursa : ninsoare\n\n");
	else if (weather == Weather::Sunny)
		printf("->Vremea pe care se desfasoara cursa : senin\n\n");

	//Adaugam masinile in cursa
	c.AddCar(new Volvo());
	c.AddCar(new BMW());
	c.AddCar(new Seat());
	c.AddCar(new Fiat());
	c.AddCar(new RangeRover());

	printf("   Caracteristicile masinilor aflate in cursa: \n");

	Volvo volvo;
	printf("->MASINA NR 1 : VOLVO\n");
	printf("   Volum carburant : %.2f litri\n   Consumul masinii : %.2f l/100 km\n   Viteza medie de deplasare : %.2f km/h\n", volvo.getFuelCapacity(), volvo.getFuelConsumption(), volvo.getAverageSpeed(weather));

	BMW bmw;
	printf("->MASINA NR 2 : BMW\n");
	printf("   Volum carburant : %.2f litri\n   Consumul masinii : %.2f l/100 km\n   Viteza medie de deplasare : %.2f km/h\n", bmw.getFuelCapacity(), bmw.getFuelConsumption(), bmw.getAverageSpeed(weather));

	Seat seat;
	printf("->MASINA NR 3 : SEAT\n");
	printf("   Volum carburant : %.2f litri\n   Consumul masinii : %.2f l/100 km\n   Viteza medie de deplasare : %.2f km/h\n", seat.getFuelCapacity(), seat.getFuelConsumption(), seat.getAverageSpeed(weather));

	Fiat fiat;
	printf("->MASINA NR 4 : FIAT\n");
	printf("   Volum carburant : %.2f litri\n   Consumul masinii : %.2f l/100 km\n   Viteza medie de deplasare : %.2f km/h\n", fiat.getFuelCapacity(), fiat.getFuelConsumption(), fiat.getAverageSpeed(weather));

	RangeRover rangerover;
	printf("->MASINA NR 5 : RANGE ROVER\n");
	printf("   Volum carburant : %.2f litri\n   Consumul masinii : %.2f l/100 km\n   Viteza medie de deplasare : %.2f km/h\n\n\n", rangerover.getFuelCapacity(), rangerover.getFuelConsumption(), rangerover.getAverageSpeed(weather));

	//Incepem cursa
	c.Race();
	c.ShowFinalRanks(); //afisam clasamentul final
	c.ShowWhoDidNotFinish(); //afisam masinile care nu au terminat cursa

	return 0;
}