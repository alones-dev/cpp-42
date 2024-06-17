/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:02:58 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/17 14:38:19 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T *_array;
		unsigned int _size;
	public:
		Array() : _size(0)
		{
			this->_array = new T[0];
		}
		Array(unsigned int n) : _size(n)
		{
			this->_array = new T[n];
		}
		Array(Array const &cpy) : _size(cpy.size())
		{
			this->_array = new T[cpy.size()];
			for (unsigned int i = 0; i < cpy.size(); i++)
				this->_array[i] = cpy[i];
		}
		~Array()
		{
			delete [] this->_array;
		}
		Array &operator=(Array const &rhs)
		{
			if (this != &rhs)
			{
				delete [] this->_array;
				this->_size = rhs.size();
				this->_array = new T[rhs.size()];
				for (unsigned int i = 0; i < rhs.size(); i++)
					this->_array[i] = rhs[i];
			}
			return *this;
		}
		unsigned int size() const
		{
			return this->_size;
		}
};

#endif
