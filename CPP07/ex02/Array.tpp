#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"
# include <stdexcept>
# include <iostream>

template <typename T>
Array<T>::Array(void) : _array(NULL), _array_len(0)
{
	std::cout << "Default constructor has been called\n";
	std::cout << "Empty array created" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _array_len(n)
{
	std::cout << "Size array constructor has been called\n";
	std::cout << "Empty array of size '" << n << "' created" << std::endl;
}

template <typename T>
Array<T>::Array(const Array &obj) : _array(NULL), _array_len(obj.len())
{
	std::cout << "Copy constructor has been called\n";
	if (this->_array_len != 0)
	{
		this->_array = new T[_array_len]();
		for (size_t i = 0; i < this->_array_len; i++)
			this->_array[i] = obj[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &obj)
{
	std::cout << "Copy assignment operator has been called\n";
	if (this != &obj)
	{
		T *temp = NULL;
		if (obj.len() != 0)
		{
			temp = new T[obj.len()]();
			for (size_t i = 0; i < obj.len(); i++)
				temp[i] = obj[i];
		}
		delete[] this->_array;
		this->_array = temp;
		this->_array_len = obj.len();
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int idx)
{
	// std::cout << "Array access operator has been called\n";
	if (idx >= this->_array_len)
		throw (std::out_of_range("Index out of bounds!"));
	return (this->_array[idx]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int idx) const
{
	// std::cout << "Array access operator has been called\n";
	if (idx >= this->_array_len)
		throw (std::out_of_range("Index out of bounds!"));
	return (this->_array[idx]);
}

template <typename T>
Array<T>::~Array(void)
{
	std::cout << "Default destructor has been called\n";
	delete[] _array;
}

template <typename T>
unsigned int Array<T>::len(void) const
{
	return (this->_array_len);
}

#endif