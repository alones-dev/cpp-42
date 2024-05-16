/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:52:50 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/16 11:33:47 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) , _weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void    HumanB::attack()
{
    if (this->_weapon == NULL)
        std::cout << "\033[1;34m" << this->_name << "\033[1;36m has no weapon to attack with\033[0m" << std::endl;
    else
        std::cout << "\033[1;34m" << this->_name << "\033[1;36m attacks with their \033[1;34m" << (*this->_weapon).getType() << "\033[0m" << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}
