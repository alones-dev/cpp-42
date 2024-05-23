/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:39:27 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/23 11:18:00 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog Default constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(Dog const &cpy) : Animal(cpy)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = cpy;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
	delete _brain;
}

Dog &Dog::operator=(Dog const &rhs)
{
	std::cout << "Dog Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Wof woof..." << std::endl;	
}
