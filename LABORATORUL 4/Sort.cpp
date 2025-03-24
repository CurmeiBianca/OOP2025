#include "Sort.h"

#include <string.h>

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Constructor pentru a crea lista cu valori aleatorii dintr-un interval
Sort::Sort(int nrElements, int valMin, int valMax)
{
	srand(time(0));
	this->size = nrElements;
	this->data = new int[this->size]; //alocam memorie dinamic

	for (int i = 0; i < this->size; i++)
		this->data[i] = valMin + rand() % (valMax - valMin + 1);
}
//Constructor pentru a crea lista dintr-o lista de initializare
Sort::Sort(initializer_list<int> lista)
{
	this->size = lista.size();
	this->data = new int[this->size]; //alocam memorie dinamic

	int i = 0;
	for (int val : lista) //iteram direct prin lista de inlantuire
	{
		this->data[i] = val;
		i++;
	}
}

//Construtor pentru a crea lista dintr-un vector existent
Sort::Sort(int* vector, int nrElements)
{
	this->size = nrElements;
	this->data = new int[this->size];

	for (int i = 0; i < this->size; i++)
		this->data[i] = vector[i];
}

//Constructor pentru a crea lista folosind parametri variabili
Sort::Sort(int nrElements, ...)
{
	this->size = nrElements;
	this->data = new int[this->size];

	va_list vl;
	va_start(vl, nrElements);

	for (int i = 0; i < this->size; i++)
		this->data[i] = va_arg(vl, int);

	va_end(vl);
}

//Constructor pentru a crea lista dintr-un sir de caractere
Sort::Sort(char* sir)
{
	if (sir[0] == '\0')
	{
		this->size = 0;
		this->data = nullptr;
		return;
	}

	this->size = 1; //am cel putin un numar
	int i = 0;
	while (sir[i] != '\0')
	{
		if (sir[i] == ',')
			this->size++;
		i++;
	}

	this->data = new int[this->size];

	int nr = 0;
	int poz = 0; //pt lungimea vectorului de numere
	
	int j = 0;
	while (sir[j] != '\0')
	{
		if (sir[j] >= '0' && sir[j] <= '9')
			nr = nr * 10 + (sir[j] - '0');
		else
			if (sir[j] == ',')
			{
				this->data[poz] = nr;
				poz++;
				nr = 0; //resetez pt unrmatorul nr
			}
		j++;
	}
	poz++;
	this->data[poz] = nr; //pentru ultimul nr dupa care nu mai urmeaza ','
}

//InsertSort
void Sort::InsertSort(bool ascendent)
{
	for (int i = 0; i < this->size; i++)
	{
		int current = this->data[i];
		int j = i - 1;

		//Daca dorim sortare ascendenta (crescatoare)
		if (ascendent)
		{
			//Mutam elementele mai mari la dreapta
			while (j >= 0 && this->data[j] > current)
			{
				this->data[j + 1] = this->data[j];
				j = j - 1;
			}
		}
		else
		{
			//Daca dorim sortare descendenta; mutam elementele mai mici la dreapta
			while (j >= 0 && this->data[j] < current)
			{
				this->data[j + 1] = this->data[j];
				j = j - 1;
			}
		}
		//Pune elementul curent la locul sau corect
		this->data[j + 1] = current;
	}
}

int Sort::Partitie(int left, int right, bool ascendent)
{
	int pivot = this->data[right]; //luam ca pivot elementul cel mai din dreapta
	int i = left - 1;

	for (int j = left; j < right; j ++)
		if (ascendent) //sortare ascendenta
		{
			if (this->data[j] < pivot)
			{
				i++; //crestem indexul pentru elementul mai mic decat pivotul
				int aux = this->data[i];
				this->data[i] = this->data[j];
				this->data[j] = aux;
			}
		}
		else //sortare descendenta
		{
			if (this->data[j] > pivot)
			{
				i++;
				int aux = this->data[i];
				this->data[i] = this->data[j];
				this->data[j] = aux;
			}
		}
	//Punem pivotul in pozitia corecta (i+1)	
	int aux = this->data[i + 1];
	this->data[i + 1] = this->data[right];
	this->data[right] = aux;

	//Returnam indexul pivotului
	return i + 1;
}

void Sort::QuickSortHelp(int left, int right, bool ascendent)
{
	if (left < right)
	{
		//Obtinem indexul pivotului
		int pivot = Partitie(left, right, ascendent);

		//Sortam sublistele
		QuickSortHelp(left, pivot - 1, ascendent); //Sublista din stanga pivotului
		QuickSortHelp(pivot + 1, right, ascendent); //Sublista din drepta pivotului
	}
}

void Sort::QuickSort(bool ascendent)
{
	QuickSortHelp(0, this->size - 1, ascendent);
}

void Sort::BubbleSort(bool ascendent)
{
	for (int i = 0; i < this->size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
		{
			if (ascendent)
			{
				if (this->data[j] > this->data[j + 1])
				{
					int aux = this->data[j];
					this->data[j] = this->data[j + 1];
					this->data[j + 1] = aux;
				}
			}
			else
			{
				if (this->data[j] < this->data[j + 1])
				{
					int aux = this->data[j];
					this->data[j] = this->data[j + 1];
					this->data[j + 1] = aux;
				}
			}
		}
}

void Sort::Print()
{
	for (int i = 0; i < this->size; i++)
		printf("%d ", this->data[i]);
	printf("\n");
}

int Sort::GetElementCount()
{
	return this->size;
}

int Sort::GetElementFromIndex(int index)
{
	if (index < 0 || index >= this->size)
		return -1;
	return this->data[index];
}

Sort::~Sort()
{
	delete[] data;
}