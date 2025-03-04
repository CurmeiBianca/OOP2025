#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int conversie(char* c)
{
	int rez = 0;
	int semn = 1;

	//in cazul in care avem numere negative
	if (*c == '-')
	{
		semn = -1;
		c++;
	}

	//convertim fiecare caracter intr-un numar
	while (*c != '\0')
	{
		if (*c >= 48 && *c <= 57) //verificam daca suntem la o cifra
		{
			rez = rez * 10 + (*c - '0'); //construim rezultatul
		}
		else
		{
			break;
		}
		c++;
	}

	return rez * semn; //returnam numarul construit
}

int main()
{
	FILE* file;
	char line[256];
	int suma = 0;
	errno_t err;

	//Deschidem fisierul folosind fopen_s
	err = fopen_s(&file, "C:\\Users\\HP\\source\\repos\\LABORATOR 1 - PROBLEMA 1\\x64\\Debug\\in.txt", "r");
	if (err != 0)
	{
		printf("Eroare: Nu s-a putut deschide fisierul.\n");
		return 1;
	}

	//Citim fiecare linie din fisier si modificam suma
	while (fgets(line, sizeof(line), file))
	{
		suma = suma + conversie(line);
	}

	//Inchidem fisierul
	fclose(file);

	//Afisam suma nmerelor
	printf("Suma numerelor este: %d\n", suma);

	return 0;
}