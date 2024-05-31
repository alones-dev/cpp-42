/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 08:44:03 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/31 15:11:40 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap   diamond("Jean");

    std::cout << std::endl;
    diamond.attack("someone");
    diamond.takeDamage(10);
    diamond.beRepaired(5);

    std::cout << std::endl;
    diamond.guardGate();

    std::cout << std::endl;
    diamond.highFivesGuys();

    std::cout << std::endl;
    diamond.whoAmI();

    std::cout << std::endl;
    return (0);
}
