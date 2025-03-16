#include <stdio.h>
#include "Math.h"

int main()
{
	//Testam adunarile cu numere intregi
	printf("Add(3,4): %d\n", Math::Add(3, 4));
	printf("Add(1,2,3): %d\n", Math::Add(1, 2, 3));

	//Testam adunarile cu numere zecimale
	printf("Add(3.5, 4.5): %d\n", Math::Add(3.5, 4.5));
	printf("Add(3.5, 4.5, 2.0): %d\n", Math::Add(3.5, 4.5, 2.0));

	//Testam inmultirile cu numere intregi
	printf("Mul(2, 5): %d\n", Math::Mul(2, 5));
	printf("Mul(2, 5, 2): %d\n", Math::Mul(2, 5, 2));

	//Testam inmultirile cu numere zecimale
	printf("Mul(25.0, 0.1): %d\n", Math::Mul(25.0, 0.1));
	printf("Mul(25.0, 0.1, 0.1): %d\n", Math::Mul(25.0, 0.1, 0.1));

	//Testam adunarea variatica
	printf("Add(5, 1, 2, 3, 4, 5): %d\n", Math::Add(5, 1, 2, 3, 4, 5));

	//Testam concatenarea stringurilor
	char* rezultat = Math::Add("Curmmei ", "Bianca");
	printf("Concatenarea: %s\n", rezultat);

	//Eliberam memoria alocata pentru rezultatul concatenarii
	delete[] rezultat;

	return 0;
}