/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:52:50 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/17 09:00:22 by kdaumont         ###   ########.fr       */
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
    this->setRawBits(cpy.getRawBits());
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
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}
