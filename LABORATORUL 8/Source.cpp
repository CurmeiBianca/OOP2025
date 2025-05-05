#include <iostream> //pentru cout, cin
#include <fstream> 
#include <string>
#include <map> //pentru a numara cuvintele
#include <queue> //pentru coada cu prioritate
#include <cctype> //pentru fuctii de procesare a caracterelor (tolower)

using namespace std;

//Functie care verifica daca un caracter este separator
bool esteSeparator(char c)
{
	return c == ' ' || c == ',' || c == '.' || c == '?' || c == '!';
}

//Functie care transforma toate literele dintr-un string in litere mici
string transformare(string cuvant)
{
	for (int i = 0; i < cuvant.length(); i++)
		cuvant[i] = tolower(cuvant[i]); //convertim fiecare litera in litera mica

	return cuvant;
}

//Structura pentru a compara elementele din coada cu prioritate
class Comparator //clasa "Comparator" este utilizata pentru a defini o regula de comparare intre doua perechi pair<string, int>
{
public:
	bool operator() (pair<string, int> p1, pair<string, int> p2)
	{
		//"second" reprezinta numarul de aparitii a cuvantului in mapa; "first" reprezinta cuvantul in sine

		if (p1.second == p2.second) //daca numarul de aparitii al primului cuvant este egal cu numarul de aparitii al celui de-al doilea cuvant, ne uitam la ordinea lexicografica
			return p1.first > p2.first;

		return p1.second < p2.second; //verificam daca numarul de aparitii al primului cuvant este mai mic decat numarul de aparitii al celui de-al doilea cuvant
	}
};

int main()
{
	ifstream f("C:\\Users\\HP\\source\\repos\\LAB 8 - PROBL 1\\input.txt"); //deschidem fisierul de intrare

	if (!f)
	{
		printf("Eroare la deschiderea fisierului. \n");
		return -1;
	}

	string text, linie;

	//citim fiecare linie din fisier si o adaugam in variabila "text"
	while (getline(f, linie))
		text = text + linie + " "; 

	f.close();

	map<string, int> frecventa; //map pentru a numara aparitiile cuvintelor
	string cuvant = "";

	//Parcurgem fiecare caracter din text
	for (int i = 0; i < text.length(); i++)
	{
		if (esteSeparator(text[i])) //daca gasim un separator (spatiu, virgula, punct etc.)
		{
			if (!cuvant.empty())
			{
				cuvant = transformare(cuvant); //convertim cuvantul
				frecventa[cuvant]++; //incrementam numarul de aparitii
				cuvant = ""; //resetam cuvantul pentru a incepe altul
			}
		}
		else
			cuvant = cuvant + text[i];
	}

	//Verificam daca mai exista un cuvant neprocesat la finalul textului
	if (!cuvant.empty())
	{
		cuvant = transformare(cuvant);
		frecventa[cuvant]++;
	}

	//Coada cu prioritate pentru sortare
	priority_queue<pair<string, int>, vector<pair<string, int>>, Comparator> coada;

	for (auto pereche : frecventa) //atunci cand folosim "auto", compilatorul deduce exact tipul lui "pereche" pe baza elementelor pe care le contine "frecventa"
		coada.push(pereche);

	//Afisam cuvintele sortate
	while (!coada.empty())
	{
		printf("%s => %d\n", coada.top().first.c_str(), coada.top().second);
		coada.pop();
	}

	return 0;
}