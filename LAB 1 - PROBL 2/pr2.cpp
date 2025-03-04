#include <stdio.h>
#include <string.h>

int comparare(char* c1, char* c2)
{
	int lung1 = strlen(c1);
	int lung2 = strlen(c2);

	if (lung1 != lung2)
		return lung1 > lung2;

	return strcmp(c1, c2) > 0;
}

void sortare(char cuvinte[][100], int nrcuv)
{
	for (int i = 0; i < nrcuv - 1; i ++)
		for (int j = i + 1; j < nrcuv; j ++)
			if (comparare(cuvinte[i], cuvinte[j]) == 0)
			{
				char aux[100];
				strcpy_s(aux, sizeof(aux), cuvinte[i]);
				strcpy_s(cuvinte[i], sizeof(cuvinte[i]), cuvinte[j]);
				strcpy_s(cuvinte[j], sizeof(cuvinte[j]), aux);
			}
}

int main()
{
	char input[1000];
	char cuvinte[100][100];
	int nrcuv = 0;

	printf("Introdu o propozitie: ");
	fgets(input, sizeof(input), stdin);

	input[strlen(input) - 1] = NULL;

	char* context = NULL;

	char* p = strtok_s(input, " ", &context);
	while (p != NULL)
	{
		strcpy_s(cuvinte[nrcuv], sizeof(cuvinte[nrcuv]), p);
		nrcuv++;
		p = strtok_s(NULL, " ", &context);
	}

	sortare(cuvinte, nrcuv);

	printf("Cuvintele sortate: \n");
	for (int i = 0; i < nrcuv; i++)
		printf("%s \n", cuvinte[i]);

	return 0;
}