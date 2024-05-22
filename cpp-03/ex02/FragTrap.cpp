/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:30:09 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/22 14:59:49 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(FragTrap const &cpy) : ClapTrap(cpy)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = cpy;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	std::cout << "FragTrap Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.get_name();
		this->_hit_points = rhs.get_hit_points();
		this->_energy_points = rhs.get_energy_points();
		this->_attack_damage = rhs.get_attack_damage();
	}
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " high fives guys" << std::endl;
}
