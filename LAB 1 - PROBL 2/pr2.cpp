#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Functie pentru compararea a doua cuvinte
int comparare(const void* a, const void* b)
{
	//Conversia pointer-ilor la pointeri de tip char
	char* word1 = *(char**)a;
	char* word2 = *(char**)b;

	//Compara lungimea cuvintelor (in ordine descrescatoare)
	int lung1 = strlen(word1);
	int lung2 = strlen(word2);

	if (lung1 != lung2)
		return lung2 - lung1; //Sorteaza dupa lungime, de la cel mai lung la cel mai scurt

	//Daca lungimile sunt egale, compara alfabetic 
	return strcmp(word1, word2);
}

int main()
{
	char input[1000];
	char* words[100];
	int nrcuv = 0;

	printf("Introdu o propozitie:");
	fgets(input, sizeof(input), stdin); //stdin - fluxul standard de intrare (tastatura)

	//Elimina caracterul de newline daca este prezent
	input[strcspn(input, "\n")] = '\0';

	//Contextul pentru strtok_s
	char* context = NULL;

	//Imparte propozitia in cuvinte
	char* cuvant = strtok_s(input, " \t\r\n", &context); //" \t\r\n -> setul de caractere de delimitatori; spatiul, tab-ul, caracterul de carriage return, caracterul de newline"
	while (cuvant != NULL)
	{
		words[nrcuv++] = cuvant;
		cuvant = strtok_s(NULL, " \t\r\n", &context); //se foloseste context (un pointer) pentru a sti de unde sa continuam
	}

	//Sorteaza cuvintele folosind qsort si functia de comparare personalizata 
	qsort(words, nrcuv, sizeof(char*), comparare); //qsort -> folosita pentru a sorta un tablou de siruri de caractere (words)

	//Afiseaza cuvintele sortate
	printf("Cuvintele sortate: \n");
	for (int i = 0; i < nrcuv; i++)
	{
		printf("%s\n", words[i]);
	}

	return 0;
}