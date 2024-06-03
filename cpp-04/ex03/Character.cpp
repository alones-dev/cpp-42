/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:57:34 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/03 10:56:57 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name)
{
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const & copy)
{
	*this = copy;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

Character &Character::operator=(Character const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			this->_inventory[i] = rhs._inventory[i]->clone();
		}
	}
	return *this;
}

std::string const &Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			std::cout << "Materia " << m->getType() << " equipped" << std::endl;
			return;
		}
	}
	std::cout << "Inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	if (!this->_inventory[idx])
	{
		std::cout << "Nothing found at this index..." << std::endl;
		return;
	}
	// delete this->_inventory[idx];
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	if (!this->_inventory[idx])
	{
		std::cout << "Nothing found at this index..." << std::endl;
		return;
	}
	this->_inventory[idx]->use(target);
}
