/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:10:47 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/03 15:05:38 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(Brain const &cpy)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = cpy;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain &Brain::operator=(Brain const &rhs)
{
	std::cout << "Brain Assignation operator called" << std::endl;
	if (this != &rhs)
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	return (*this);
}

void Brain::setIdea(int index, std::string idea)
{
	if (index >= 0 && index < 100)
		this->_ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return (this->_ideas[index]);
	return ("Doesn't exist");
}
