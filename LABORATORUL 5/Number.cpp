#include "Number.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//CONSTRUCTORI
//folositi pt a initializa o instanta de tipul clasei, in functie de parametri dati

Number::Number(const char* value, int base) //creez o instanta Number dintr-un sir de caractere
{
	this->base = base;
	this->digits = new char[strlen(value) + 1];

	memcpy(this->digits, value, strlen(value) + 1); //destinatie, sursa, nr octeti
}

Number::Number(int value)
{
	this->base = 10; //un nr int e implicit considerat in baza 10

	int d = value;
	int nr = 0;
	while (d > 0)
	{
		nr++;
		d = d / 10;
	}
	this->digits = new char[nr + 1];
	this->digits[nr] = '\0';

	for (int i = nr - 1; i >= 0; i--)
	{
		this->digits[i] = '0' + (value % 10); //transform cifra in caracter
		value = value / 10;
	}
}


Number::Number(const Number& other) //copy constructor
{
	//parametru - o referinta constanta la un obiect de tip Number 

	this->base = other.base; //copiez baza din obiectul sursa in obiectul nou
	this->digits = new char[strlen(other.digits) + 1]; //aloc memorie obiectului copiat

	memcpy(this->digits, other.digits, strlen(other.digits) + 1);
}

Number::Number(Number&& other) //move constructor
{
	this->base = other.base;
	this->digits = other.digits;
	
	other.digits = nullptr; //pentru ca l-am mutat
}

//Operator de atribuire din int
Number& Number::operator=(int number) //sterge vechiul sir, pune noul int ca sir
{
	delete[] this->digits; //sterge vechiul sir din memorie

	//convertesc numar in sir
	int d = number;
	int nr = 0;

	while (d > 0)
	{
		nr++;
		d = d / 10;
	}

	this->digits = new char[nr + 1];
	this->digits[nr] = '\0';

	for (int i = nr - 1; i >= 0; i--)
	{
		this->digits[i] = '0' + (number % 10);
		number = number / 10;
	}

	this->base = 10; //fiind int este in baza 10

	return *this; //pointer catre obiectul modificat
}

//Operator de atribuire din sir
Number& Number::operator=(const char* sir) //cand ai deja un nr creat ca sir si ii atribui un nou sir de caractere
{
	delete[] this->digits;

	this->digits = new char[strlen(sir) + 1];
	memcpy(this->digits, sir, strlen(sir) + 1);

	//baza ramane neschimbata (obiectul deja exista intr-o baza, doar ii inlocuiesc valoarea cu un alt string)

	return *this;
}

//move assisment (tot operator= dpar ca are ca parametru un obiect de tipul clasei)
Number& Number::operator=(Number&& object)
{
	if (this != &object)
	{
		delete[] this->digits;
		this->digits = object.digits;
		this->base = object.base;
		object.digits = nullptr;
	}

	return *this;
}

Number::~Number() //destructor
{
	delete[] digits;
}

//METODE

void Number::SwitchBase(int newBase)
{
	int base10 = toDecimal(this->digits, this->base); // convertește la baza 10
	delete[] this->digits; // eliberează memoria veche

	if (base10 == 0)
	{
		this->digits = new char[2];
		this->digits[0] = '0';
		this->digits[1] = '\0';
		this->base = newBase;
		return;
	}

	// Calculează câte caractere sunt necesare pentru numărul în baza nouă
	int nr_aux = 0;
	int aux = base10;
	while (aux > 0)
	{
		nr_aux++;
		aux = aux / newBase;
	}

	// Alocă memorie pentru noul șir
	this->digits = new char[nr_aux + 1];
	this->digits[nr_aux] = '\0'; 

	// Construiește șirul în noua bază
	for (int i = nr_aux - 1; i >= 0; i--)
	{
		int cifra = base10 % newBase;
		if (cifra < 10)
			this->digits[i] = '0' + cifra;
		else
			this->digits[i] = 'A' + (cifra - 10); 
		base10 = base10 / newBase;
	}
	this->base = newBase; // actualizează baza
}

void Number::Print()
{
	printf("%s ( in baza %d )\n", digits, base);
}

int Number::GetDigitsCount()
{
	return strlen(digits);
}

int Number::GetBase()
{
	return base;
}

//FRIEND

Number operator+(const Number& left, const Number& right)
{
	int a = Number::toDecimal(left.digits, left.base);
	int b = Number::toDecimal(right.digits, right.base);
	int rez = a + b;

	int baza_noua;
	if (right.base > left.base)
		baza_noua = right.base;
	else
		baza_noua = left.base;

	//nr cifre rezultat in noua baza
	int nr_aux = 0;
	int aux = rez;

	while (aux > 0)
	{
		nr_aux++;
		aux = aux / baza_noua;
	}

	char* sir = new char[nr_aux + 1]; //aloc spatiu pt sirul rezultat din adunarea numerelor
	sir[nr_aux] = '\0';

	//Transform valoarea in baza noua
	aux = rez;
	for (int i = nr_aux - 1; i >= 0; i--)
	{
		int cifra = aux % baza_noua;
		if (cifra < 10)
			sir[i] = '0' + cifra;
		else
			sir[i] = 'A' + (cifra - 10);
		aux = aux / baza_noua;
	}
	Number rezultat(sir, baza_noua); //creez noul obiect prin constructir folosind sirul si baza
	delete[] sir; //apeland constructorul se face noul obiect si nu mai avem nevoie de acest sir

	return rezultat;
}

Number operator-(const Number& left, const Number& right)
{
	int a = Number::toDecimal(left.digits, left.base);
	int b = Number::toDecimal(right.digits, right.base);
	int rez = a - b;

	int baza_noua;
	if (right.base > left.base)
		baza_noua = right.base;
	else
		baza_noua = left.base;

	//nr cifre rezultat in noua baza
	int nr_aux = 0;
	int aux = rez;

	while (aux > 0)
	{
		nr_aux++;
		aux = aux / baza_noua;
	}

	char* sir = new char[nr_aux + 1]; //aloc spatiu pt sirul rezultat din adunarea numerelor
	sir[nr_aux] = '\0';

	//Transform valoarea in baza noua
	aux = rez;
	for (int i = nr_aux - 1; i >= 0; i--)
	{
		int cifra = aux % baza_noua;
		if (cifra < 10)
			sir[i] = '0' + cifra;
		else
			sir[i] = 'A' + (cifra - 10);
		aux = aux / baza_noua;
	}
	Number rezultat(sir, baza_noua); //creez noul obiect prin constructor folosind sirul si baza
	delete[] sir; //apeland constructorul se face noul obiect si nu mai avem nevoie de acest sir

	return rezultat;
}

//OPERATORI

char Number::operator[](int index)
{
	return this->digits[index];
}

bool Number::operator>(const Number& object)
{
	if (toDecimal(this->digits, this->base) > toDecimal(object.digits, object.base))
		return true;
	return false;
}

bool Number::operator<(const Number& object)
{
	if (toDecimal(this->digits, this->base) < toDecimal(object.digits, object.base))
		return true;
	return false;
}

bool Number::operator>=(const Number& object)
{
	if (toDecimal(this->digits, this->base) >= toDecimal(object.digits, object.base))
		return true;
	return false;
}

bool Number::operator<=(const Number& object)
{
	if (toDecimal(this->digits, this->base) <= toDecimal(object.digits, object.base))
		return true;
	return false;
}

bool Number::operator==(const Number& object)
{
	if (toDecimal(this->digits, this->base) == toDecimal(object.digits, object.base))
		return true;
	return false;
}

Number& Number::operator--() // --i
{
	if (strlen(this->digits) <= 1) // dacă avem doar un caracter
	{
		delete[] this->digits; 
		this->digits = new char[2]; 
		memcpy(this->digits, "0", 2); 
	}
	else
	{
		// Eliminăm primul caracter
		int i = 0;
		while (this->digits[i] != '\0')
		{
			this->digits[i] = this->digits[i + 1]; 
			i++;
		}
	}
	return *this;
}

Number Number::operator--(int) //i--
{
	Number aux = *this; //copie
	if (strlen(this->digits) <= 1)
	{
		delete[] this->digits;
		this->digits = new char[2];
		memcpy(this->digits, "0", 2);
	}
	else
		this->digits[strlen(this->digits) - 1] = '\0'; //sterg ultimul caracter; EXEMPLU : in loc de 16 se pune 1
	return aux;
}

Number& Number::operator++() // ++i
{
	bool carry = true; //pentru overflow

	// Incrementăm de la dreapta la stânga
	for (int i = strlen(this->digits) - 1; i >= 0; i--)
	{
		if (this->digits[i] < '9') // Dacă cifra este mai mică decât 9
		{
			this->digits[i]++; // Incrementează cifra
			carry = false; // Nu mai avem carry
			break;
		}
		else
		{
			this->digits[i] = '0'; // Dacă cifra este 9, o facem 0
			carry = true; // Continuăm cu carry
		}
	}

	// Dacă carry este încă adevărat, înseamnă că trebuie să adăugăm un '1' la începutul șirului
	if (carry)
	{
		// Alocăm un nou șir cu o dimensiune mai mare
		char* newDigits = new char[strlen(this->digits) + 2]; // +2 pentru a adăuga '1' și '\0'
		newDigits[0] = '1'; 

		// Copiem vechiul șir în noul șir, la poziția 1 (după '1')
		memcpy(newDigits + 1, this->digits, strlen(this->digits) + 1); 

		delete[] this->digits; 
		this->digits = newDigits; 
	}

	return *this; // Returnăm obiectul modificat
}

Number Number::operator++(int) // i++
{
	Number aux = *this; // copie
	bool carry = true;

	// Incrementăm de la dreapta la stânga
	for (int i = strlen(this->digits) - 1; i >= 0; i--)
	{
		if (this->digits[i] < '9') // Dacă cifra este mai mică decât 9
		{
			this->digits[i]++; // Incrementează cifra
			carry = false; // Nu mai avem carry
			break;
		}
		else
		{
			this->digits[i] = '0'; // Dacă cifra este 9, o facem 0
			carry = true; // Continuăm cu carry
		}
	}

	// Dacă carry este adevărat, înseamnă că trebuie să adăugăm un '1' la începutul șirului
	if (carry)
	{
		// Alocăm un nou șir cu o dimensiune mai mare
		char* newDigits = new char[strlen(this->digits) + 2]; // +2 pentru a adăuga '1' și '\0'
		newDigits[0] = '1'; // Plasăm '1' la începutul șirului

		// Copiem vechiul șir în noul șir, la poziția 1 (după '1')
		memcpy(newDigits + 1, this->digits, strlen(this->digits) + 1); // +1 pentru '\0'

		delete[] this->digits; // Eliberăm memoria veche
		this->digits = newDigits; // Actualizăm pointerul pentru a folosi noul șir
	}

	return aux; // Returnăm copia obiectului înainte de modificare
}

int Number::toDecimal(const char* val, int base)
{
	int rez = 0;
	for (int i = 0; i < strlen(val); i++)
	{
		char c = val[i];
		int d;

		if (c >= '0' && c <= '9')
			d = c - '0';
		else if (c >= 'A' && c <= 'F')
			d = 10 + (c - 'A');
		else
			return -1;

		if (d >= base)
			return -1;

		rez = rez * base + d;
	}
	return rez;
}