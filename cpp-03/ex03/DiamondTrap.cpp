/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 08:44:05 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/31 15:25:30 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(DiamondTrap const &cpy) : ClapTrap(cpy), ScavTrap(cpy), FragTrap(cpy)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	*this = cpy;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
	std::cout << "DiamondTrap Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.get_name();
		this->_hit_points = rhs.get_hit_points();
		this->_energy_points = rhs.get_energy_points();
		this->_attack_damage = rhs.get_attack_damage();
	}
	return (*this);
}

std::string DiamondTrap::get_name(void) const
{
	return (this->_name);
}

void DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->_name << " and my ClapTrap is " << this->ClapTrap::_name << std::endl;
}
