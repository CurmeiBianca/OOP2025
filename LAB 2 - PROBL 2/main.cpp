#include <stdio.h>
#include "student.h"
#include "functii.h"
using namespace std;

int main()
{
	student Student1;
	Student1.SetNume("Popescu Vasile", strlen ("Popescu Vasile"));
	printf("Student1.nume este %s \n\n", Student1.GetNume());
	Student1.SetNotaMatematica(3.5);
	printf("Student1.notaMatematica este %.2f \n", Student1.GetNotaMatematica());
	Student1.SetNotaEngleza(9.5);
	printf("Student1.notaEngleza este %.2f \n", Student1.GetNotaEngleza());
	Student1.SetNotaIstorie(10.0);
	printf("Student1.notaIstorie este %.2f \n\n", Student1.GetNotaIstorie());

	student Student2;
	Student2.SetNume("Anton Ioana", strlen ("Anton Ioana"));
	printf("Student2.nume este %s \n\n", Student2.GetNume());
	Student2.SetNotaMatematica(7.5);
	printf("Student2.notaMatematica este %.2f \n", Student2.GetNotaMatematica());
	Student2.SetNotaEngleza(6.5);
	printf("Student2.notaEngleza este %.2f \n", Student2.GetNotaEngleza());
	Student2.SetNotaIstorie(4.5);
	printf("Student2.notaIstorie este %.2f \n\n", Student2.GetNotaIstorie());

	int rez;

	rez = compareByName(&Student1, &Student2);
	if (rez == 0)
		printf("Studentii au acelasi nume. \n\n");
	if (rez == 1)
		printf("Numele studentului 1 este inaintea numelui studentului 2. \n\n");
	if (rez == -1)
		printf("Numele studentului 2 este inaintea numelui studentului 1. \n\n");

	rez = compareByAverageGrade(&Student1, &Student2);
	if (rez == 0)
		printf("Studentii au aceeasi medie. \n");
	if (rez == 1)
		printf("Studentul 1 are media mai mare decat studentul 2. \n");
	if (rez == -1)
		printf("Studentul 1 are media mai mica decat studentul 2. \n");

	return 0;
}