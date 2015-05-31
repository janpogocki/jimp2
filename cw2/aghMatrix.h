
#include <iostream>
#include <math.h>
#include <cstdarg> // do funkcji o zmiennej liczbie argumentow --- setItems(int r, int c ...)

using namespace std;

template <class T>
class aghMatrix {
private:
    T ** matrix;
    int n;
    int m;
public:
	 aghMatrix() {};
	 aghMatrix(int _n, int _m);
	 ~aghMatrix();

	 void setItem(int n, int m, T item); // n - wiersz, m - kolumna
	 void setItems (T * wsk);
	 void setItems(int r, int c ...);
	 void setAll();
	 void getALL();

	 T & operator()(int a, int b);
	 aghMatrix<T> & operator+(const aghMatrix<T> & other);
	 aghMatrix<T> & operator*(const aghMatrix<T> & other);
	 aghMatrix<T> & operator= ( const aghMatrix<T> & other);
	 bool operator== (const aghMatrix<T> & other);
	 bool operator!= (const aghMatrix<T> & other);



};

//-------------------CONSTRUCTOR------------------------------
template <class T>
aghMatrix<T>::aghMatrix(int _n, int _m)
{
	  n = _n;
      m = _m;
      matrix = new  T * [n];

        for (int i = 0; i < n; i ++)
        {
            matrix[i] = new T[m];
        }
}

//-------------------DESTRUCTOR---------------------------------
template <class T>
aghMatrix<T>::~aghMatrix()
{
	cout << "destructor" <<endl;
	delete [] matrix;
}

//-------------------SETITEM------------------------------------
template <class T>
void aghMatrix<T>::setItem(int n, int m, T item)
{
	matrix[n][m] = item;
}

//-----------------SETITEMS-------------------------------------
template <class T>
void aghMatrix<T>::setItems(int r, int c ...)
{
		  matrix = new  T * [r];
		  n = r;
		  m = c;

        for (int i = 0; i < r; i ++)
        {
            matrix[i] = new T[c];
        }

		va_list ap;
		va_start(ap,c);

		for(int i = 0; i < r; i ++)
		{
			for (int j = 0; j < c; j ++)
			{
				matrix[i][j] = va_arg(ap,char);

			}
		}

		va_end(ap);
}

//-----------------------SETITEMS2---------------------------
template <class T>
void aghMatrix<T>::setItems (T * wsk)
{
		int licznik = 0;
		for(int i = 0; i < n; i ++)
		{
			for (int j = 0; j < m; j ++)
			{
				matrix[i][j] = wsk[licznik];
				licznik ++;
			}
		}

}

//-----------------SETALL---------------------------------------
template <class T>
void aghMatrix<T>::setAll()
{
  for (int i = 0; i < n; i ++)
        {
            for (int j = 0; j < m; j ++)
            {
                matrix[i][j] = j + i;
            }
        }
}

//------------------GETALL----------------------------------------
template <class T>
void aghMatrix<T>::getALL()
{
	 for (int i = 0; i < n; i ++)
        {
            for (int j = 0; j < m; j ++)
            {
                cout << matrix[i][j];
            }
            cout << endl;
        }

}

//------------------OPERATOR()--------------------------------------
template <class T>
T & aghMatrix<T>::operator()(int a, int b)
{
	if ( (a > n) || (a < 0) || (b > m) || (b < 0)) throw aghException(0, "Index out of range", __FILE__, __LINE__);
	else return matrix[a][b];
}

//------------------OPERATOR=----------------------------------------
template <class T>
aghMatrix<T> & aghMatrix<T>::operator= ( const aghMatrix<T> & other)
{
	
	if ( & other != this) 
	{
	
	if ( (other.n == n) && (other.m == m))
	{
            for (int i = 0; i < n; i ++)
            {
                    for (int j = 0; j < m; j ++)
                    {
                        matrix[i][j] = other.matrix[i][j];
                    }
            }
       
			
	}

	else
	{
		delete [] matrix;
		n = other.n;
		m = other.m;
		matrix  = new T * [n];
		for (int i = 0; i < n; i ++)
		{
			matrix[i] = new T[m];
		}


		  for (int i = 0; i < n; i ++)
            {
                    for (int j = 0; j < m; j ++)
                    {
                        matrix[i][j] = other.matrix[i][j];
                    }
            }

	}

	}
	return *this;

}

//------------------------OPERATOR+--------------------------
template <class T>
aghMatrix<T> & aghMatrix<T>::operator+(const aghMatrix<T> & other)
{
	
	    aghMatrix<T> * temp = new aghMatrix<T>(n,m);
		
        for (int i = 0; i < n; i ++)
        {
            for (int j = 0; j < m; j ++)
            {
                temp->matrix[i][j] = (matrix[i][j] + other.matrix[i][j]);

            }

        }

        return *temp;

}

//-------------------OPERATOR*---------------------------------
template <class T>
aghMatrix<T> & aghMatrix<T>::operator*(const aghMatrix<T> & other)
{
	aghMatrix<T> * temp = new aghMatrix<T>(n,other.m);
	T count = 0;

	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < other.m; j ++)
		{
			count = 0;
			for (int k = 0; k < other.n; k ++) count += matrix[i][k] * other.matrix[k][j];
			temp->matrix[i][j] = count;
		}
	}

	return *temp;
}

//---------------------------OPERATOR==------------------------
template <class T>
bool aghMatrix<T>::operator== (const aghMatrix<T> & other)
{
	if ( (n != other.n) || (m != other.m) ) return false;
	else
	{
		  for (int i = 0; i < n; i ++)
            {
                for (int j = 0; j < m; j ++)
                {
                    if (matrix[i][j] != other.matrix[i][j]) return false;
                }

            }
            return true;

	}

}

//--------------------------OPERTAOR!=------------------------
template <class T>
bool aghMatrix<T>::operator!= (const aghMatrix<T> & other)
{
	if ( &other == this ) return false;
	if ( (n != other.n) || (m != other.m) ) return true;
	else
	{
		  for (int i = 0; i < n; i ++)
            {
                for (int j = 0; j < m; j ++)
                {
                    if (matrix[i][j] != other.matrix[i][j]) return true;
                }

            }
            return false;

	}
}

//------------------------SPECJALIZOWANE-------------------
aghMatrix<char> & aghMatrix<char>::operator+(const aghMatrix<char> & other)
{
	    aghMatrix<char> * temp = new aghMatrix<char>(n,m);
		
		for (int i = 0; i < n; i ++)
		{
			for (int j = 0; j < m; j ++)
			{
				temp->matrix[i][j] = ((matrix[i][j] - 97) + (other.matrix[i][j] - 97) % 25) + 97;
			}
		}

		return *temp;
}

//---------------------OPERATOR*----------------------------
aghMatrix<char> & aghMatrix<char>::operator*(const aghMatrix<char> & other)
{
	aghMatrix<T> * temp = new aghMatrix<T>(n,other.m);
	char count = 0;

	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < other.m; j ++)
		{
			count = 0;
			for (int k = 0; k < other.n; k ++) 
			{
			count += (matrix[i][k] - 97) * (other.matrix[k][j] - 97);
			}

			temp->matrix[i][j] = (count % 25) + 97;
		}
	}

	return *temp;

}

///--------------------------OPERATOR+CHAR*---------------------------------
/*aghMatrix<char*> & aghMatrix<char*>::operator+(const aghMatrix<char*> & other)
{
	    aghMatrix<char*> * temp = new aghMatrix<char*>(n,m);
		
		for (int i = 0; i < n; i ++)
		{
			for (int j = 0; j < m; j ++)
			{


				
				for (int ii = 0; ii < strlen(matrix[i][j]); ii++)
				{
					for (int jj = 0; jj < strlen(other.matrix[i][j]); jj ++)
					{

	
					}

				}





				
			}
		}

		return *temp;
}*/
