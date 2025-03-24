#include "Sort.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
	Sort sort1(10, 1, 100);
	printf("Valori random: ");
	sort1.Print();

	sort1.InsertSort(true);
	printf("Dupa InsertSort (ascendent): ");
	sort1.Print();

	sort1.BubbleSort(false);
	printf("Dupa BubbleSort (descendent): ");
	sort1.Print();

	sort1.QuickSort(true);
	printf("Dupa QuickSort (ascendent): ");
	sort1.Print();

	printf("\nNumarul de elemente: %d\n", sort1.GetElementCount());
	int index1 = rand() % 10;
	printf("Elementul de pe pozitia %d este %d\n", index1, sort1.GetElementFromIndex(index1));

	Sort sort2 ({ 7, 2, 10, 5, 3 });
	printf("\nInitialization list: ");
	sort2.Print();

	sort2.InsertSort(true);
	printf("Dupa InsertSort (ascendent): ");
	sort2.Print();

	sort2.BubbleSort(false);
	printf("Dupa BubbleSort (descendent): ");
	sort2.Print();

	sort2.QuickSort(true);
	printf("Dupa QuickSort (ascendent): ");
	sort2.Print();

	printf("\nNumarul de elemente: %d\n", sort2.GetElementCount());
	int index2 = rand() % 5;
	printf("Elementul de pe pozitia %d este %d\n", index2, sort2.GetElementFromIndex(index2));

	int vector[] = { 6, 4, 2, 9, 1 };
	Sort sort3(vector, 5);
	printf("\nFrom vector: ");
	sort3.Print();

	sort3.InsertSort(true);
	printf("Dupa InsertSort (ascendent): ");
	sort3.Print();

	sort3.BubbleSort(false);
	printf("Dupa BubbleSort (descendent): ");
	sort3.Print();

	sort3.QuickSort(false);
	printf("Dupa QuickSort (descendent): ");
	sort3.Print();

	printf("\nNumarul de elemente: %d\n", sort3.GetElementCount());
	int index3 = rand() % 10;
	printf("Elementul de pe pozitia %d este %d\n", index3, sort3.GetElementFromIndex(index3));

	Sort sort4({ 12, 50, 30, 8, 90, 65 });
	printf("\nFrom string: ");
	sort4.Print();

	sort4.InsertSort(true);
	printf("Dupa InsertSort (ascendent): ");
	sort4.Print();

	sort4.BubbleSort(true);
	printf("Dupa BubbleSort (ascendent): ");
	sort4.Print();

	sort4.QuickSort(false);
	printf("Dupa QuickSort (descendent): ");
	sort4.Print();

	printf("\nNumarul de elemente: %d\n", sort4.GetElementCount());
	int index4 = rand() % 10;
	printf("Elementul de pe pozitia %d este %d\n", index4, sort4.GetElementFromIndex(index4));

	Sort sort5(4, 5, 15, 25, 10);
	printf("\nFrom variadic parameters: ");
	sort5.Print();

	sort5.InsertSort(true);
	printf("Dupa InsertSort (ascendent): ");
	sort5.Print();

	sort5.BubbleSort(true);
	printf("Dupa BubbleSort (ascendent): ");
	sort5.Print();

	sort5.QuickSort(false);
	printf("Dupa QuickSort (descendent): ");
	sort5.Print();

	printf("\nNumarul de elemente: %d\n", sort5.GetElementCount());
	int index5 = rand() % 10;
	printf("Elementul de pe pozitia %d este %d\n", index5, sort5.GetElementFromIndex(index5));

	return 0;
}