#include "functii.h"
#include <string.h>

int compareByName(student* obj1, student* obj2)
{
	if (strcmp(obj1->GetNume(), obj2->GetNume()) == 0)
		return 0;
	if (strcmp(obj1->GetNume(), obj2->GetNume()) < 0)
		return 1;
	if (strcmp(obj1->GetNume(), obj2->GetNume()) > 0)
		return -1;
}

int compareByMathGrade(student* obj1, student* obj2)
{
	if (obj1->GetNotaMatematica() == obj2->GetNotaMatematica())
		return 0;
	if (obj1->GetNotaMatematica() > obj2->GetNotaMatematica())
		return 1;
	if (obj1->GetNotaMatematica() < obj2->GetNotaMatematica())
		return -1;
}

int compareByEnglishGrade(student* obj1, student* obj2)
{
	if (obj1->GetNotaEngleza() == obj2->GetNotaEngleza())
		return 0;
	if (obj1->GetNotaEngleza() > obj2->GetNotaEngleza())
		return 1;
	if (obj1->GetNotaEngleza() < obj2->GetNotaEngleza())
		return -1;
}

int compareByHistoryGrade(student* obj1, student* obj2)
{
	if (obj1->GetNotaIstorie() == obj2->GetNotaIstorie())
		return 0;
	if (obj1->GetNotaIstorie() > obj2->GetNotaIstorie())
		return 1;
	if (obj1->GetNotaIstorie() < obj2->GetNotaIstorie())
		return -1;
}

int compareByAverageGrade(student* obj1, student* obj2)
{
	if (obj1->Medie() == obj2->Medie())
		return 0;
	if (obj1->Medie() > obj2->Medie())
		return 1;
	if (obj1->Medie() < obj2->Medie())
		return -1;
}