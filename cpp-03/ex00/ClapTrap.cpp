/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 08:44:15 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/22 09:18:21 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(3), _attack_damage(5)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.get_name();
		this->_hit_points = rhs.get_hit_points();
		this->_energy_points = rhs.get_energy_points();
		this->_attack_damage = rhs.get_attack_damage();
	}
	return (*this);
}

std::string ClapTrap::get_name(void) const
{
	return (this->_name);
}

unsigned int ClapTrap::get_hit_points(void) const
{
	return (this->_hit_points);
}

unsigned int ClapTrap::get_energy_points(void) const
{
	return (this->_energy_points);
}

unsigned int ClapTrap::get_attack_damage(void) const
{
	return (this->_attack_damage);
}

void ClapTrap::attack(std::string const &target)
{
	if (this->_hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and can't attack" << std::endl;
		return ;
	}
	if (this->_energy_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is out of energy and can't attack" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	this->_energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
	this->_hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and can't repair" << std::endl;
		return ;
	}
	if (this->_energy_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is out of energy and can't repair" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " points!" << std::endl;
	this->_hit_points += amount;
	this->_energy_points--;
}
