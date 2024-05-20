/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:44:12 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/20 19:31:07 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
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

std::ostream&   operator<<(std::ostream& os, const Point& rhs)
{
    os << "(" << rhs.getX() << ", " << rhs.getY() << ")";
    return os;
}