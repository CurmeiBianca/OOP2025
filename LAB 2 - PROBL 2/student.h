#pragma once
#include <stdlib.h>
#include <string>

class student
{
	char* nume;
	float notaMatematica;
	float notaEngleza;
	float notaIstorie;
public:
	void SetNume(const char* inputNume, int inputNumeSize);
	const char* GetNume();
	void SetNotaMatematica(float notaMatematica);
	float GetNotaMatematica();
	void SetNotaEngleza(float notaEngleza);
	float GetNotaEngleza();
	void SetNotaIstorie(float notaIstorie);
	float GetNotaIstorie();

	float Medie();
};

