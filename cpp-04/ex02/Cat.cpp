/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:39:27 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/29 09:26:11 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat Default constructor called" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(Cat const &cpy) : Animal(cpy)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = cpy;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	delete _brain;
}

Cat &Cat::operator=(Cat const &rhs)
{
	std::cout << "Cat Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs.getType();
		this->_brain = new Brain();
		for (int i = 0; i < 100; i++)
			this->_brain->setIdea(i, rhs.getBrain()->getIdea(i));
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meoooww..." << std::endl;	
}

Brain* Cat::getBrain() const
{
	return (this->_brain);
}
