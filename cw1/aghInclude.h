#include <iostream>
using namespace std;

template <class T>
double suma ( T tab [], int n)
{
	// tutaj raczej musi byc double bo char ma 0-255, a w drugim przypadku funkcja ma zwracaæ 484, wiêc raczej typ T nie wypali
	double suma = 0;

	for (int i = 0; i < n; i ++)
	{
		cout << tab[i] << " ";	// drukuje kolejno zawartosc tablicy
		suma += static_cast<double>(tab[i]);			// dodaje do zmiennej typu double zawartosc tablicy któr¹ pierw rzutuje
	}

	cout << endl;

	//----------------------------------- Drukowanie w okreslonym w tresci formacie
	for (int i = 0; i < n; i ++)
	{
	if ( i != n - 1)
		{
			cout << tab[i] << " + ";
		}

	else												
	{
		cout << tab[i] << " = ";
	}	
	
	}
	
	cout << suma <<endl;
	
	return suma; // wynik : 17 w pierwszym przypadku w drugim 484
}