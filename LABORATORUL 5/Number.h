#pragma once

class Number
{
	//add data members

	char* digits; //tablou de caractere pentru stocarea cifrelor
	int base;
public:
	//Constructor
	Number(const char* value, int base); //where base is between 2 and 16
	Number(int value); //constructor dintr-un numar intreg

	//add operators and copy/move constructor

	Number(const Number& other); //constructor de copiere
	Number(Number&& other); //constructor de mutare

	Number& operator=(int number);
	Number& operator=(const char* sir);
	Number& operator=(Number&& object);

	~Number(); //Destructor

	void SwitchBase(int newBase);
	void Print();
	int GetDigitsCount(); //returns th number of digits for the current number
	int GetBase(); //returns the current base

	//Functii prietene pentru adunare si scadere
	friend Number operator+(const Number& left, const Number& right);
	friend Number operator-(const Number& left, const Number& right);

	char operator[](int index); //operator de indexare pentru a accesa cifrele

	//Operatori de relatie
	bool operator>(const Number& object);
	bool operator<(const Number& object);
	bool operator>=(const Number& object);
	bool operator<=(const Number& object);
	bool operator==(const Number& object);

	//Operatori de incrementare/decrementare
	Number& operator++(); //Incrementare prefixata 
	Number operator++(int); //Incrementare postfixata 
	Number& operator--(); //Decrementare prefixata
	Number operator--(int); //Decrementare postfixata

	static int toDecimal(const char* value, int base);
};

