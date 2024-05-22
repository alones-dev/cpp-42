/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 08:44:03 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/22 16:16:39 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap    clap("Clap");
    ScavTrap    scav("Scav");
    FragTrap    frag("Frag");

    std::cout << std::endl;

    clap.attack("Scav");
    clap.takeDamage(10);
    clap.beRepaired(5);

    std::cout << std::endl;

    scav.attack("Frag");
    scav.takeDamage(10);
    scav.beRepaired(5);
    scav.guardGate();

    std::cout << std::endl;

    frag.attack("Clap");
    frag.takeDamage(10);
    frag.beRepaired(5);
    frag.highFivesGuys();

    std::cout << std::endl;
    return (0);
}
