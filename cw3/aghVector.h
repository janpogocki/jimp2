/**
* \file aghVector.h
* \author Piotr Ha³aœ
* \date 26.05.2015
* \version 1.0
* \brief The definition and declaration of template class aghVector
*/
//------------------------------------------------------------------
#ifndef AGH_VECTOR
#define AGH_VECTOR

//-------------------------------------------------------------------
#include "aghContainer.h"
#include "aghException.h"
using namespace std;
//------------------------------------------------------------------

/**
* \class template aghVector<T>
* \author Piotr Ha³aœ
* \date 26.05.2015
* \brief The definition and declaration of template class aghVector<T> which inherit from aghContainer<T>
*/
template <class T>
class aghVector : public aghContainer<T>
{
private:
    T * tab;	///< Stores a type T items
    int sizetable;	///< Stores a size of table
    int howmanyitems; ///< Stores a number of items in tab

public:

	/// \brief The constructor which creating array (tab) with size = 1; sets sizetable on 1, and howmanyitems on 0.
    aghVector();

	/// \brief The second constructor which casts other on type aghVector<T> and copies all content of it.
    aghVector( const aghContainer<T>& other);

	/// \brief Destructor which sets howmanyitems on 1, and delete reserved memory by *tab.
	~aghVector();
	
	
  /// \brief adds an item into Vector more precisely into tab
  ///  \param n - position on which item should be added
  ///  \param item - it is item which we want to add into vector
  /// \return true if succeed or false if it fail.
    bool insert(int n, T const& item);
    
  /// \brief Creat free place in Vector (tab) on n position
  ///  \param n - position on which  should be free place in tab
	void rozsun (int n);
   
	/// \brief Show on the screen content of aghVector
    void show();

   /// \brief It show us how many items aghVector contains
  /// \return number of items
    int size() const;

   /// \brief Return item on n position
  ///  \param n - position on which item shoulb be return
  /// \return item on n position
    T& at(int n) const;

   /// \brief Remove items from n position
  ///  \param n - position on which item should be removed
  /// \return true if succeed or false if n position is wrong 
    bool remove(int n);

  /// \brief Opposite of rozsun
  ///  \param n - position on which vector should be fill
    void zsun(int n);

/// \brief an overloaded operator = that copies content of right side object to left side object
///
/// \param other - right side object which should be copied
/// \return returns a lefside object;
	aghVector<T> & operator=(aghVector<T> const & other); 
};


//----------------------Konstruktor--------------------------------


template <class T>
aghVector<T>::aghVector()
{
    tab = new T[1];
    sizetable = 1;
    howmanyitems = 0;

}
//----------------------Destruktor----------------------------------------
template<class T>
aghVector<T>::~aghVector()
{
	howmanyitems = 0;
	delete [] tab;
}
//-------------------Konstruktor przeci¹¿ony------------------------------
template <class T>
aghVector<T>::aghVector(  const aghContainer<T>& other)
{
const aghVector<T>& b = dynamic_cast<const aghVector<T>&>(other);
sizetable = b.sizetable;
howmanyitems = b.howmanyitems;

tab = new T[sizetable];
for (int i = 0; i < sizetable; i ++)
{
    tab[i] = b.tab[i];
}

}


//--------------------funkcja size------------------------------------
template <class T>
int aghVector<T>::size() const
{
    return howmanyitems;
}


//-----------------------funkcja AT---------------------------------
template <class T>
T& aghVector<T>::at(int n) const
{
    if ( (n <0) || (n > sizetable))  throw aghException(0, "Index out of range", __FILE__, __LINE__);
    return tab[n];
}

//-----------------------Funkcja rozsun-------------------------------

template <class T>
void aghVector<T>::rozsun(int n)
{
    if (sizetable >= 2)
    {
    for (int i = sizetable - 1; i >  n; i-- )
    {
    
        tab[i] = tab[i - 1];
    }
    }
}

//------------------------Zsun------------------------------------------

template <class T>
void aghVector<T>::zsun(int n)
{
    if (sizetable >= 2)
    {
        for (int i = n; i < sizetable -1; i++)
        {
            tab[i] = tab[i+1];
        }
    }
    
}

//--------------------remove-----------------------------------------
template <class T>
bool aghVector<T>::remove(int n)
{
    if ((n >= 0) && (n <= (howmanyitems -1))) 
    {
        zsun(n);
        howmanyitems--;
        return true;

    }
    
    
    return false;
    
}

//-----------------------Wyswietlanie elementow-------------------------

template <class T>
void aghVector<T>::show()
{
    for (int i = 0; i < sizetable; i ++)
    {
        cout << tab[i] << " ";
    }
}


//-------------------Insert------------------------------------------

template <class T>
bool aghVector<T>::insert(int n, T const& item)
{
    if (n < 0 ) return false;
    if (sizetable == howmanyitems)
    {
        T * temp = new T[sizetable];
        for (int i = 0; i < sizetable; i++)
        {
            temp[i] = tab[i];
        }

        delete [] tab;
        tab = new T[sizetable + 1];
        
        for (int i = 0; i < sizetable; i ++)
        {
            tab[i] = temp[i];
        }
        sizetable ++;

    }
    

    rozsun (n);
    tab[n] = item;
    howmanyitems ++;

    

    return true;    
}

//--------------------------OPERATOR=-------------------------------
template <class T>
aghVector<T> & aghVector<T>::operator=(aghVector<T> const & other)
{
	int stab = other.size();
	if ( &other != this) 
	{
		for (int i = 0; i < stab; i ++)
		{
			insert(i,other.at(i));
		}
	}
	return *this;
}
#endif
