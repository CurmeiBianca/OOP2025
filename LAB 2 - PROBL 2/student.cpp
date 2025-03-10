#include "student.h"

void student::SetNume(const char* inputNume, int inputNumeSize)
{
	this->nume = new char[inputNumeSize + 1];
	memcpy(this->nume, inputNume, inputNumeSize);
	this->nume[inputNumeSize] = '\0';
}

const char* student::GetNume()
{
	return this->nume;
}

void student::SetNotaMatematica(float notaMatematica)
{
	if (notaMatematica >= 1.0f && notaMatematica <= 10.0f)
		this->notaMatematica = notaMatematica;
	else
		printf("Nota invalida! \n");
}

float student::GetNotaMatematica()
{
	return this->notaMatematica;
}

void student::SetNotaEngleza(float notaEngleza)
{
	if (notaEngleza >= 1.0f && notaEngleza <= 10.0f)
		this->notaEngleza = notaEngleza;
	else
		printf("Nota invalida! \n");
}

float student::GetNotaEngleza()
{
	return this->notaEngleza;
}

void student::SetNotaIstorie(float notaIstorie)
{
	if (notaIstorie >= 1.0f && notaIstorie <= 10.0f)
		this->notaIstorie = notaIstorie;
	else
		printf("Nota invalida! \n");
}

float student::GetNotaIstorie()
{
	return this->notaIstorie;
}

float student::Medie()
{
	float media = (this->notaMatematica + this->notaEngleza + this->notaIstorie) / 3.0;
	return media;
}
