/**
* \file aghContainer.h
* \author Piotr Ha³aœ
* \date 26.05.2015
* \version 1.0
* \brief The definition and declaration of template class aghContainer
*/
//------------------------------------------------------------------

#ifndef AGH_CONTAINER
#define AGH_CONTAINER
//-------------------------------------------------------------------
#include "aghException.h"
//-------------------------------------------------------------------

/**
* \class template aghContainer<T>
* \author Piotr Ha³aœ
* \date 26.05.2015
* \brief The definition of aghContainer class which is base class for containers
*/
template <class T>
class aghContainer
{
public:
	/// \brief The default constructor.
    aghContainer() {};

	/// \brief The virtual destructor.
	virtual ~aghContainer() {};

		
  /// \brief Adds item to derived class by using virtual method insert
  ///  \param item - what we want to add
    void append(T const& item);

	/// \brief virtual method which an item into derived container 
  ///  \param n - position on which item should be added
  ///  \param item - it is item which we want to add
  /// \return true if succeed or false if it fail.
    virtual bool insert(int n, T const& item) = 0;
 
  /// \brief virtual method which show us how many items derived container contains
  /// \return number of items
    virtual int size () const = 0;

   /// \brief Virtual method which return item on n position
  ///  \param n - position on which item shoulb be return
  /// \return item on n position
    virtual T& at(int) const = 0;
   
  /// \brief Remove items from n position
  ///  \param n - position on which item should be removed
  /// \return true if succeed or false if n position is wrong 
	virtual bool remove(int) = 0;
 
  /// \brief Remove all items from container
	void clear();
   
  /// \brief Returns item on n position
	T& operator[](int n) const;
   
  /// \brief Give us position on which item is.
  ///  \param _value it is item which we looking for
 ///  \param _from -  on which position we should start search
  /// \return position on which item is or -1 if can't find
	int indexOf(T const& _value, int _from = 0) const;
   
   /// \brief Give us position on which item is.
  ///  \param _value it is item which we looking for
 ///  \param _from -  on which position we should start search
  /// \return position on which item is or -1 if can't find
	bool contains(T const& _value, int _from = 0) const;
   

  /// \return returns true if container is empty or false if it isn't
	bool isEmpty();


	//---------------------operatory-----------------------------
	
/// \brief an overloaded operator << that writes content of container
///
/// \param out - a given stream 
/// \param right - a reference to the aghContainer object
/// \return returns a reference to the given stream
	template <class L>
	friend ostream& operator<<(ostream& out, aghContainer<L> const& right);
	
	
/// \brief an overloaded operator << that adds element to container
///
/// \param element - item which we want to add 
/// \return returns container with item
	aghContainer<T>& operator<<(T const& element);

/// \brief an overloaded operator += that adds element to container
///
/// \param element - item which we want to add
/// \return returns container with item
    aghContainer<T>& operator+=(T const& element);

/// \brief an overloaded operator += that adds up one containers to the other
///
/// \param right - right side object of operator +=
/// \return returns  sum of containers
	aghContainer<T>& operator+=(aghContainer<T> const& right);

// \brief check whether the right side conatiners is equal to the left side
///
/// \param right - right side object of operator ==
/// \return returns  true if are equal and false if are not
    bool operator==(aghContainer<T> const& right);

// \brief check whether the right side conatiners isn't equal to the left side
///
/// \param right - right side object of operator !=
/// \return returns  true if are not equal and false if are
    bool operator!=(aghContainer<T> const& right);

// \brief copied one container to the other
///
/// \param right - right side object of operator =
/// \return return lefside = container with values the right side
	 aghContainer<T>& operator=(aghContainer<T> const& right);



};

//------------------------APPEND--------------------------------------

template <class T>
void aghContainer<T>::append(T const& item)
{
    insert (size(),item);
}

//-----------------------------CLEAR----------------------------------

template <class T>
void aghContainer<T>::clear()
{
    for (int i = 0; i < size(); )
    {
        remove(0);
    }
}

//------------------------------------------OPERATOR<<----------------

template <class T>
aghContainer<T>& aghContainer<T>::operator<<(T const& element)
{
    append(element);
    return *this;
}

template <class T>
aghContainer<T>& aghContainer<T>::operator+=(T const& element)
{
    append(element);
    return *this;
}

//-------------------------------------INDEXOF--------------------------
template <class T>
int aghContainer<T>::indexOf(T const& _value, int _from) const
{
    for(int i = _from; i < size(); i ++)
    {
        if (_value == at(i)) return i;
    }

    return -1;
}

//-------------------------------------OPERATOR[]-------------------------
template <class T>
T& aghContainer<T>::operator[](int n) const
{
    if ( (n <0) || (n > size()))  throw aghException(0, "Index out of range", __FILE__, __LINE__);
    return at(n);
}


//---------------------------------CONTAINS------------------------------

template <class T>
bool aghContainer<T>::contains(T const& _value, int _from) const
{
    if(indexOf(_value,_from) != -1) return true;
    else return false;
}

//---------------------------------isEmpty-------------------------------
template <class T>
bool aghContainer<T>::isEmpty()
{
    if (size() > 0) return false;
    else return true;
}


//------------------operator==---------------------------------------


template <class T>
bool aghContainer<T>::operator==(aghContainer<T> const& right)
{
    if ( size() == right.size())
    {
        for (int i = 0; i < size(); i ++)
        {
            if (at(i) != right.at(i)) return false;
        }

        return true;
    }

    return false;
}



//-----------------------OPERATOR!=--------------------------------

template <class T>
bool aghContainer<T>::operator!=(aghContainer<T> const& right)
{
    if ( *this == right) return false;
    else return true;

}

//----------------------OPERATOR=------------------------------------
template <class T>
aghContainer<T>& aghContainer<T>::operator=(aghContainer<T> const& right)
{


     if (&right == this) return *this;
    else
    {
		clear();
        for (int i = 0; i < right.size(); i ++)
        {
		
			insert(i,right.at(i));
        }
	
    }
    
    return *this;
}

//------------------------OPERATOR+=---------------------------------------
template <class T>
aghContainer<T>& aghContainer<T>::operator+=(aghContainer<T> const& right)
{
	int stab = right.size();
	for(int i = 0; i < stab; i ++)
	{
		insert(i,at(i) + right.at(i));
	}
	return *this;
}

//-----------------------OPERATOR<<------------------------------------------
template <class L>
ostream& operator<<(ostream& out, aghContainer<L> const& right)
{
	for (int i = 0; i < right.size(); i ++)
	{
		out << right.at(i) << " ";
	}
	return out;
}

#endif
