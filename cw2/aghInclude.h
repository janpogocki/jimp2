#ifndef PLIKH
#define PLIKH

#include <iostream>

using namespace std;

//////////////////////////////
// gdzie ta obsluga wyjatkow ma byc zaincludowana, skoro nie wolno
// includowac plikow cpp?... // aghExeption.h nie jest plikiem cpp.

template <class T>
class aghMatrix {
private:
	T ** matrix;
	int n;
	int m;

public:
	aghMatrix(int _n, int _m)
	{
		n = _n;
		m = _m;
		matrix = new  T * [n];

		for (int i = 0; i < n; i ++)
		{
			matrix[i] = new T[m];
		}


	}

	void setItem(int n, int m, T item) // n - wiersz, m - kolumna
	{
		matrix[n][m] = item;

	}


	~aghMatrix()
	{
		cout << "destruktor" <<endl;
	}

	// ------------------------------------------------------------------> to zacz¹lem pisac na szybko wiec nie przetestowalem, rano to zrobie.

	T operator()(int a, int b)
	{
		return matrix[a][b];
	}

	T ** operator+ (const aghMatrix<T> & other)
	{
		T ** temp = new * T[n];
		for (int i = 0; i < n; i ++)
		{
			temp[i] = new T[m];
		}

		for (int i = 0; i < n; i ++)
		{
			for (int j = 0; j < m; j ++)
			{
				temp[i][j] = (matrix[i][j] + other.matrix[i][j]);
			}

		}

		return temp;
	}

		T & operator= ( const aghMatrix<T> & other)
		{
			for (int i = 0; i < n; i ++)
			{
					for (int j = 0; j < m; j ++)
					{

					}
			}
		}


};

//------------------------------------------------------------------
//KLASA aghComplex

class aghComplex
{
  private:
    double real, imaginary, r, i;
  public:
    aghComplex();
    aghComplex(double _r, double _i);
    aghComplex add(aghComplex number);
    aghComplex sub(aghComplex number);
    aghComplex mul(aghComplex number);
    aghComplex div(aghComplex number);
    aghComplex power(int wykladnik);
    double re();
    double im();
    void print();
};

aghComplex::aghComplex()
{
    real = imaginary = 0;
}

aghComplex::aghComplex(double _r, double _i)
{
    real = r = _r;
    imaginary = i = _i;
}

aghComplex aghComplex::add(aghComplex number)
{
    r = real+number.real;
    i = imaginary+number.imaginary;
    return aghComplex(r,i);
}

aghComplex aghComplex::sub(aghComplex number)
{
    r = real - number.real;
    i = imaginary - number.imaginary;
    return aghComplex(r,i);
}

aghComplex aghComplex::mul(aghComplex number)
{
    r = real*number.real - imaginary*number.imaginary;
    i = real*number.imaginary + imaginary*number.real;
    return aghComplex(r,i);
}

aghComplex aghComplex::div(aghComplex number)
{
    r = (real*number.real + imaginary*number.imaginary)/(number.real*number.real+number.imaginary*number.imaginary);
    i = (imaginary*number.real - real*number.imaginary)/(number.real*number.real+number.imaginary*number.imaginary);
    return aghComplex(r,i);
}

aghComplex aghComplex::power(int wykladnik)
{
    aghComplex number;
    number = aghComplex(real, imaginary);

    if (wykladnik == 0)
    {
        r = 1;
        i = 0;
    }
    else if (wykladnik > 1)
    {
        aghComplex temp;
        temp = number;

        for (int j=0; j<wykladnik-1; j++)
        {
            temp.mul(number);
            temp = aghComplex(temp.r, temp.i);
        }

        r = temp.r;
        i = temp.i;
    }
    else if (wykladnik < 0)
    {
        //transformacja na postac trygonometryczna
        double modul, fi;
        modul = sqrt(real*real+imaginary*imaginary);

        if (real > 0)
            fi = atan(imaginary/real);
        else if (real < 0)
            fi = atan(imaginary/real)+M_PI;

        r = pow(modul, wykladnik)*cos(wykladnik*fi);
        i = pow(modul, wykladnik)*sin(wykladnik*fi);
    }
    return aghComplex(r,i);
}

double aghComplex::re()
{
    return r;
}

double aghComplex::im()
{
    return i;
}

void aghComplex::print()
{
    if (re() == 0 && im() != 0)
        cout << im() << "i";
    else if (re() != 0 && im() == 0)
        cout << re();
    else if (re() == 0 && im() == 0)
        cout << "0";
    else
    {
        cout << re();
        cout << std::showpos << im() << "i" << std::noshowpos;
    }
}


#endif
