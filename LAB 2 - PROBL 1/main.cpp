#include <cstdio> //pentru printf
#include "NumberList.h"

int main()
{
	//Cream un obiect de tip NumberList
	NumberList lista;

	lista.Init();

	//Adaugam cateva numere
	lista.Add(1);
	lista.Add(8);
	lista.Add(7);
	lista.Add(2);
	lista.Add(5);

	//Afisam lista inainte de sortare
	printf("Inainte de sortare: ");
	lista.Print();

	lista.Sort();

	//Afisam lista dupa sortare
	printf("\nDupa sortare: ");
	lista.Print();

	//Incerc sa mai adaug in lista numere, astfel incat aceasta sa contina mai mult de 10 numere
	for (int i = 1; i <= 10; i++)
	{
		printf("\nVoi adauga numarul %d \n", i * 10);
		if (lista.Add(i * 10) == false)
		{
			printf("Lista este plina; nu se mai pot adauga numere. \n");
			break;
		}
		lista.Print(); //afisez lista dupa fiecare adaugare
	}

	return 0;
}