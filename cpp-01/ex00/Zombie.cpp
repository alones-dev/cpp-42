/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:52:50 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/13 22:28:39 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->_name = name;
    std::cout << "\033[1;32m" << this->_name << " is up\033[0m" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "\033[1;31m" << this->_name << " is down\033[0m" << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << "\033[0;32m🧟 " << this->_name << ": \033[1;33mBraiiiiiiinnnzzzZ...\033[0m" << std::endl;
}