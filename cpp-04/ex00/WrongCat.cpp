/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:39:27 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/03 14:57:44 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &cpy) : WrongAnimal(cpy)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = cpy;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs)
{
	std::cout << "WrongCat Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Meoooww..." << std::endl;	
}
