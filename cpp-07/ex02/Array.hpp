/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:02:58 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/18 14:51:12 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <cstdlib>

template <typename T>
class Array
{
	private:
		T *_array;
		unsigned int _size;
	public:
		Array() : _size(0)
		{
			std::cout << "Array default constructor called" << std::endl;
			this->_array = new T[0];
		}

		Array(unsigned int n) : _size(n)
		{
			std::cout << "Array unsigned int constructor called" << std::endl;
			this->_array = new T[n];
		}

		Array(Array &cpy) : _size(cpy.size())
		{
			std::cout << "Array copy constructor called" << std::endl;
			*this = cpy;
		}

		~Array()
		{
			std::cout << "Array destructor called" << std::endl;
			delete [] this->_array;
		}

		Array &operator=(Array &rhs)
		{
			std::cout << "Array copy assignement operator called" << std::endl;
			if (this != &rhs)
			{
				this->_size = rhs._size;
				this->_array = new T[rhs._size];
				for (unsigned int i = 0; i < rhs._size; i++)
					this->_array[i] = rhs._array[i];
			}
			return *this;
		}
		
		unsigned int size() const
		{
			return this->_size;
		}

		T &operator[](unsigned int i)
		{
			if (i >= this->_size)
				throw Array::IndexRangeException();
			return this->_array[i];
		}

		class IndexRangeException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Index out of range";
				}
		};
};

template <typename T>
std::ostream & operator<<(std::ostream & o, Array<T> & rhs)
{
    for (unsigned int i = 0; i < rhs.size(); i++)
        o << rhs[i] << " ";
    return o;
}

#endif
