#ifndef PLIKH
#define PLIKH

#include <iostream>

using namespace std;

//----------------------
//funkcja szablonowa
template <class T>
double suma (T tab, int n)
{
    // tutaj raczej musi byc double bo char ma 0-255, a w drugim przypadku funkcja ma zwracac 484, wiec raczej typ T nie wypali
    double suma = 0;

    for (int i = 0; i < n; i ++)
    {
        cout << tab[i] << " "; // drukuje kolejno zawartosc tablicy
        suma += static_cast<double>(tab[i]); // dodaje do zmiennej typu double zawartosc tablicy ktora pierw rzutuje
    }

    cout << endl;

    //Drukowanie w okreslonym w tresci formacie
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

    cout << suma << "\n\n";

    return suma;
}

//-------------------------------------------------------------------
//funkcja specjalizowana
double suma(char ** tab, int n)
{
    double suma=0;

    for (int i=0; i<n; i++)
    {
        //wypisanie kolejnych wyrazow
        if (i != n-1)
            cout << tab[i] << "+";
        else
            cout << tab[i] << "=";
        //przeliczenie dlugosci tablicy znakow
        for (int j=0; tab[i][j] != '\0'; j++)
            suma++;
    }

    //wyswietlenie sklejonego ciagu
    for (int i=0; i<n; i++)
    {
        cout << tab[i];
    }

    //wyswietlenie sumy w nawiasie
    cout << "(" << suma << ")" << "\n\n";

    return suma;
}

//-------------------------------------------------------------------
//KLASA aghFib

class aghFib
{
private:
    int * tab;
public:
    int wartoscFib(int n);

    //przeladowanie operatora []
    int operator[](int el){return wartoscFib(el);}
};

int aghFib::wartoscFib(int n)
{
    //dynamiczna tablica - tworzymy
    tab = new int[n+1];
    tab[0]=0;
    tab[1]=1;

    if (n>=2)
    {
        for (int i=2; i<=n; i++)
        {
            //fib to suma dwoch poprzednich elementow
            tab[i] = tab[i-1]+tab[i-2];
        }
    }

    return tab[n];
    delete tab;
}

#endif
