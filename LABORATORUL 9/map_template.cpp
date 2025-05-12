#include <stdio.h> //pentru printf

//Nu folosim STL (vector, map, etc)

//Definim o clasa generica Map cu doua tipuri: K (cheie) si V (valoare)
template <typename K, typename V>
class Map
{
private:
	//Structura interna pentru a pastra o pereche cheie-valoare
	struct Entry
	{
		K key;
		V value;
	};

	Entry data[100]; //vector static de maxim 100 de perechi
	int count = 0; //numarul actual de elemente in mapa

public:
	//Operatorul [] pentru acces si modificare a valorii asociate unei chei 
	V& operator[](K key)
	{
		//Daca cheia exista, returnam referinta la valoarea ei
		for (int i = 0; i < count; i++)
		{
			if (data[i].key == key)
				return data[i].value;
		}
		//Daca cheia nu exista, adaugam un nou Entry
		data[count].key = key;
		count++;
		return data[count - 1].value;
	}

	//Metoda Set: seteaza o valoare pentru o cheie (inlocuieste daca exista)
	void Set(K key, V value)
	{
		for (int i = 0; i < count; i++)
		{
			if (data[i].key == key)
			{
				data[i].value = value;
				return;
			}
		}
		data[count].key = key;
		data[count].value = value;
		count++;
	}

	//Metoda Get: returneaza true daca gaseste cheia si copiaza valoarea in variabila primita
	bool Get(const K& key, V& value)
	{
		for (int i = 0; i < count; i++)
		{
			if (data[i].key == key)
			{
				value = data[i].value;
				return true;
			}
		}
		return false;
	}

	//Returneaza numarul de elemente din mapa
	int Count() const
	{
		return count;
	}

	//Sterge toate elementele
	void Clear()
	{
		count = 0;
	}

	//Sterge un element cu o cheie specifica, daca exista
	bool Delete(const K& key)
	{
		for (int i = 0; i < count; i++)
		{
			if (data[i].key == key)
			{
				for (int j = i; j < count - 1; j++)
				{
					data[j] = data[j + 1]; //mutam elementele inapoi
				}
				count--;
				return true;
			}
		}
		return false;
	}

	//Verificam daca toate cheile din mapa primita se gasesc si in mapa curenta
	bool Includes(const Map<K, V>& other)
	{
		for (int i = 0; i < other.count; i++)
		{
			bool found = false;
			for (int j = 0; j < count; j++)
			{
				if (data[j].key == other.data[i].key)
				{
					found = true;
					break;
				}
			}
			if (!found)
				return false;
		}
		return true;
	}

	//Structura care va fi folosita in structured bindings
	struct IterItem
	{
		K key;
		V value;
		int index;
	};

	//Clasa Ierator necesara pentru range-based for + structured bindings
	class Iterator
	{
	private:
		Entry* vector; //pointer la vectorul de date
		int index; //indexul curent

	public:
		//Constructorul iteratorului 
		Iterator(Entry* vector, int index) : vector(vector), index(index) {}

		//Operatorul * returneaza structura cu key, value, index
		IterItem operator*() const
		{
			return { vector[index].key, vector[index].value, index };
		}

		//Preincrementare: trece la urmatorul element
		Iterator& operator++()
		{
			index++;
			return *this;
		}

		//Operator de comparatie: verifica daca am ajuns la final
		bool operator!=(const Iterator& other) const
		{
			return index != other.index;
		}
	};

	//Functia begin() pentru range-based for
	Iterator begin()
	{
		return Iterator(data, 0);
	}

	//Functia end() pentru range-based for
	Iterator end()
	{
		return Iterator(data, count);
	}
};

//Functia main care testeaza clasa Map
int main()
{
	Map<int, const char*> m;

	m[10] = "C++";
	m[20] = "test";
	m[30] = "Poo";

	//Afisam elementele folosind structured bindings si range-based for
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d Value=%s\n", index, key, value);
	}

	m[20] = "result"; //modificam valoarea pentru cheia 20

	//Afisam din nou
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}

	return 0;
}