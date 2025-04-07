#include <stdlib.h>
#include <stdio.h>

//Definirea literalului pentru Kelvin -> Celsius
float operator"" _Kelvin(unsigned long long int kelvin)
{
	return (kelvin - 273.15); //conversia din Kelvin in Celsius
}

//Definirea literalului pentru Fahrenheit -> Celsius
float operator"" _Fahrenheit(unsigned long long int fahrenheit)
{
	return ((fahrenheit - 32) / 1.8);
}

int main()
{
	float a = 300_Kelvin; //300 Kelvin in Celsius
	float b = 120_Fahrenheit; //120 Fahrenheit in Celsius

	//Afisam rezultatele conversiilor
	printf("300 Kelvin este %.2f grade Celsius\n", a);
	printf("120 Fahrenheit este %.2f grade Celsius\n", b);

	return 0;
}