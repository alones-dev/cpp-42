/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:52:50 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/17 13:32:20 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(Fixed const &cpy)
{
    *this = cpy;
}

Fixed::Fixed(int const value)
{
    this->_value = value << Fixed::_bits;
}

Fixed::Fixed(float const value)
{
    this->_value = roundf(value * (1 << _bits));
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
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

/* Comparison */
bool Fixed::operator>(Fixed const &rhs) const
{
    return (this->_value > rhs.getRawBits());
}

bool Fixed::operator<(Fixed const &rhs) const
{
    return (this->_value < rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const &rhs) const
{
    return (this->_value >= rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const &rhs) const
{
    return (this->_value <= rhs.getRawBits());
}

bool Fixed::operator==(Fixed const &rhs) const
{
    return (this->_value == rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const &rhs) const
{
    return (this->_value != rhs.getRawBits());
}

/* Arithmetic */
Fixed Fixed::operator+(Fixed const &rhs) const
{
    return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(Fixed const &rhs) const
{
    return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(Fixed const &rhs) const
{
    return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(Fixed const &rhs) const
{
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

/* Incrementation */
Fixed &Fixed::operator++()
{
    this->_value++;
    return (*this);
}

Fixed &Fixed::operator--()
{
    this->_value--;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++*this;
    return (temp);
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --*this;
    return (temp);
}

/* Min, max */
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b ? a : b);
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
    return (a < b ? a : b);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
    return (a > b ? a : b);
}
