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




#endif
