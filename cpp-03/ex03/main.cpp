/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 08:44:03 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/23 09:12:02 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap   diamond("Jean");

    // ClapTrap member functions
    std::cout << std::endl;
    diamond.attack("someone");
    diamond.takeDamage(10);
    diamond.beRepaired(5);

    // ScavTrap member function
    std::cout << std::endl;
    diamond.guardGate();

    // FragTrap member function
    std::cout << std::endl;
    diamond.highFivesGuys();

    // DiamondTrap member function
    std::cout << std::endl;
    diamond.whoAmI();

    std::cout << std::endl;
    return (0);
}
