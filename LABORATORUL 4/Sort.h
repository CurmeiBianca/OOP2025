#pragma once

#include <iostream>

#include <string.h>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <stdarg.h>

using namespace std;

class Sort
{
	//add data members
	int* data;
	int size;
public:
	//add constructors

	Sort(int nrElements, int valMin, int valMax); //constructor cu valori aleatorii
	Sort(initializer_list<int> lista); //constructor cu lista de initializare
	Sort(int* vector, int nrElements); //constructor cu vector
	Sort(int nrElements, ...); //constructor cu parametri variabili
	Sort(char* sir); //constructor cu sir de caractere

	//Destrutor pentru a elibera memoria
	~Sort();

	void InsertSort(bool ascendent = false);
	void QuickSort(bool ascendent = false);
	void BubbleSort(bool ascendent = false);

	void Print();
	
	int GetElementCount();
	int GetElementFromIndex(int index);

private:
	void QuickSortHelp(int left, int right, bool ascendent = false);
	int Partitie(int left, int right, bool asceendent = false);
};