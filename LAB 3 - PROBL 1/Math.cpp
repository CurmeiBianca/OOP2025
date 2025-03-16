#include "Math.h"
#include <iostream>
#include <stdarg.h> //librarie pentru functiile variadice
#include <string.h>
#include <stdlib.h> //pentru malloc/realloc

int Math::Add(int a, int b)
{
	return a + b;
}

int Math::Add(int a, int b, int c)
{
	return a + b + c;
}

int Math::Add(double a, double b)
{
	return static_cast <int> (a + b); //am folosit "static_cast" pentru ca functia retiurneaza o valoare de tip int, dar parametrii sunt de tipul double
}

int Math::Add(double a, double b, double c)
{
	return static_cast <int> (a + b + c);
}

int Math::Mul(int a, int b)
{
	return a * b;
}

int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}

int Math::Mul(double a, double b)
{
	return static_cast <int> (a * b);
}

int Math::Mul(double a, double b, double c)
{
	return static_cast <int> (a * b * c);
}

int Math::Add(int count, ...) //Adunare variadica (insumam un numar variabil de argumente)
{
	int suma = 0;

	va_list arguments;
	va_start(arguments, count); //Initializam lista de argumente

	//Adunam fiecare numar
	for (int i = 0; i < count; i++)
		suma = suma + va_arg(arguments, int); //obtinem urmatorul numar intreg

	va_end(arguments); //Inchidem lista de argumente
	return suma;
}

char* Math::Add(const char* sir1, const char* sir2) //Concatenare a doua stringuri
{
	if (sir1 == nullptr || sir2 == nullptr)
		return nullptr;

	//Alocam memorie pentru concatenarea celor doua siruri de caractere
	int lung1 = strlen(sir1);
	int lung2 = strlen(sir2);
	char* rezultat = new char[lung1 + lung2 + 1];

	strcpy_s(rezultat, lung1 + lung2 + 1, sir1);
	strcat_s(rezultat, lung1 + lung2 + 1, sir2);

	return rezultat;
}
