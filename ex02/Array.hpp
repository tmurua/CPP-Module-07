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
#include <cstddef>	// NULL

// class template for an array of elements of type T
// T is chosen when creating the Array object. ex: Array<int> numbers;
template <typename T>
class Array{
	private:
		T				*_array;	// pointer to first element of array of T
		unsigned int	_size;		// number of elements inside the array

	public:
		Array() : _array(NULL), _size(0){}

		// new T[n]() allocates n T elements and initializes each with T()
		// ex.: int() initializes int to 0, so Array<int>(3) creates [0][0][0]
		Array(unsigned int n) : _array(new T[n]()), _size(n){}

		// deep copy: allocate new memory, then copy each element from other
		Array(const Array &other) : _array(NULL), _size(other._size){
			unsigned int	i = 0;

			if (_size > 0)
				_array = new T[_size]();
			while (i < _size){
				_array[i] = other._array[i];
				i++;
			}
		}

		// replaces this array with a deep copy of other: allocate/copy/delete
		Array	&operator=(const Array &other){
			unsigned int	i = 0;
			T				*newArray = NULL;

			if (this == &other)
				return (*this);
			if (other._size > 0)
				newArray = new T[other._size]();
			while (i < other._size){
				newArray[i] = other._array[i];
				i++;
			}
			delete[] _array;
			_array = newArray;
			_size = other._size;

			return (*this);
		}

		~Array(void){
			delete[] _array;
		}

		// subscript operator for non-const arrays: read/write access
		// ex.: Array<int> a(3); a[0] = 42; std::cout << a[0]; 
		T	&operator[](unsigned int index){
			if (index >= _size) // index must be between 0 and size -1
				throw std::exception();
			return (_array[index]);
		}

		// subscript operator for const arrays: read only access
		// ex.: const Array<int> a(3); std::cout << a[0]; // OK 
		// a[0] = 42; // ERROR
		const T	&operator[](unsigned int index) const{
			if (index >= _size)
				throw std::exception();
			return (_array[index]);
		}

		unsigned int	size(void) const{
			return (_size);
		}
};

#endif
