/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:00:49 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/03 14:49:39 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_source[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & copy)
{
	*this = copy;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_source[i])
			delete this->_source[i];
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_source[i])
			delete this->_source[i];
		this->_source[i] = rhs._source[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
	{
		std::cout << "Invalid materia" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!this->_source[i])
		{
			this->_source[i] = m;
			std::cout << "Materia learned" << std::endl;
			return ;
		}
	}
	std::cout << "Materia source is full" << std::endl;
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_source[i] && this->_source[i]->getType() == type)
		{
			std::cout << "Materia " << type << " created" << std::endl;
			return this->_source[i]->clone();
		}
	}
	std::cout << "Materia type not found" << std::endl;
	return NULL;
}
