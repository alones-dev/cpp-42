/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:19:57 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/22 10:26:52 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &cpy) : ClapTrap(cpy)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = cpy;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.get_name();
		this->_hit_points = rhs.get_hit_points();
		this->_energy_points = rhs.get_energy_points();
		this->_attack_damage = rhs.get_attack_damage();
	}
	return (*this);
}

void ScavTrap::attack(std::string const &target)
{
	if (this->_hit_points <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " is dead and can't attack" << std::endl;
		return ;
	}
	if (this->_energy_points <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " is out of energy and can't attack" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	this->_energy_points--;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->get_name() << " is now in Gate guardian mode" << std::endl;
}
