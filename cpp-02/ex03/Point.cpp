/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:44:12 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/19 22:28:18 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y)
{
}

Point::Point(Point const &cpy) : _x(cpy._x), _y(cpy._y)
{
}

Point::~Point()
{
}

Point &Point::operator=(Point const &rhs)
{
	if (this != &rhs)
	{
		(Fixed)this->_x = rhs.getX();
		(Fixed)this->_y = rhs.getY();
	}
	return (*this);
}

Fixed Point::getX() const
{
	return (this->_x);
}

Fixed Point::getY() const
{
	return (this->_y);
}

float Point::getXFloat() const
{
	return (this->_x.toFloat());
}

float Point::getYFloat() const
{
	return (this->_y.toFloat());
}