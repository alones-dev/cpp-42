/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:52:50 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/17 13:08:35 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &cpy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = cpy;
}

Fixed::Fixed(int const value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = value << Fixed::_bits;
}

Fixed::Fixed(float const value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(value * (1 << _bits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &rhs)
        this->_value = rhs.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

float Fixed::toFloat(void) const
{
    return (float(this->_value) / (1 << _bits));
}

int Fixed::toInt(void) const
{
    return (this->_value >> Fixed::_bits);
}

std::ostream& operator<<(std::ostream& o, const Fixed& fixed)
{
    o << fixed.toFloat();
    return (o);
}
