/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:14:03 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/23 13:21:49 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

// class template that stores an array of elements of type T
// T is the placeholder for the type stored inside the array
// Array<int>, Array<std::string>, Array<float>, etc all come from this same template
template <typename T>
class Array{
	private:
		// pointer to the memory allocated with new[]
		T				*_array;
		// number of elements inside the array
		unsigned int	_size;

	public:
		// creates an empty array, no allocated memory
		Array() : _array(NULL), _size(0){}

		// new T[n]() allocates n elements and initializes them by default
		// for int this means 0, for std::string this means empty strings
		Array(unsigned int n) : _array(new T[n]()), _size(n){}

		// creates a new array with the same size as other
		// then copies each element one by one
		Array(const Array &other) : _array(NULL), _size(other._size){
			unsigned int	i = 0;

			// allocate only if there is something to allocate
			if (_size > 0)
				_array = new T[_size]();

			// copy every element from other into this new array
			// this makes a deep copy, not just a copy of the pointer
			while (i < _size){
				_array[i] = other._array[i];
				i++;
			}
		}

		// replaces the current array with a deep copy of other
		Array	&operator=(const Array &other){
			unsigned int	i = 0;
			T				*newArray = NULL;

			if (this == &other)
				return (*this);

			// allocate new memory before deleting the old one
			// this is safer because the old array is still valid if allocation fails
			if (other._size > 0)
				newArray = new T[other._size]();

			// copy elements from other into the new memory
			while (i < other._size){
				newArray[i] = other._array[i];
				i++;
			}

			// remove the old memory after the copy is ready
			delete[] _array;

			// make this object point to the new memory
			_array = newArray;
			_size = other._size;

			return (*this);
		}

		~Array(void){
			delete[] _array;
		}

		// subscript operator for non-const arrays
		// returns a reference, so the element can be modified
		T	&operator[](unsigned int index){
			// index must be between 0 and size - 1
			if (index >= _size)
				throw std::exception();
			return (_array[index]);
		}

		// subscript operator for const arrays
		// returns a const reference, so the element can be read but not modified
		const T	&operator[](unsigned int index) const{
			// same bounds check as the non-const version
			if (index >= _size)
				throw std::exception();
			return (_array[index]);
		}

		// returns the number of elements in the array
		// const at the end means this function does not modify the object
		unsigned int	size(void) const{
			return (_size);
		}
};

#endif
