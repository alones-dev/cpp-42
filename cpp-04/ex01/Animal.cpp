/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:34:56 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/29 09:17:51 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Default constructor called" << std::endl;
}

Animal::Animal(Animal const &cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Animal::~Animal()
{
	std::cout << "Destructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

std::string Animal::getType() const
{
	return (this->_type);
}

void Animal::makeSound() const
{
	std::cout << "Basic animal sound..." << std::endl;	
}
