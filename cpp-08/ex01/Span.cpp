/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 22:27:34 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/18 12:18:33 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _size(n)
{
}

Span::Span(Span const & cpy)
{
	*this = cpy;
}

Span::~Span()
{
}

Span & Span::operator=(Span const & rhs)
{
	if (this != &rhs)
	{
		_size = rhs._size;
		_array = rhs._array;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (_array.size() >= _size)
		throw Span::ArrayFullException();
	_array.push_back(number);
}

int Span::shortestSpan()
{
	if (_array.size() <= 1)
		throw Span::NoRangeException();

	std::vector<int> tmp(_array);
	std::sort(tmp.begin(), tmp.end());
	std::adjacent_difference(tmp.begin(), tmp.end(), tmp.begin());
}
