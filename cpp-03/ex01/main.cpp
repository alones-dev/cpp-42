/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 08:44:03 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/31 15:31:19 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap    a("Arnaud");
    ClapTrap    b("Claire");
    ScavTrap    c("Matteo");

    b = c;

    std::cout << std::endl;

    a.takeDamage(10);
    a.beRepaired(5);
    a.attack("Claire");

    std::cout << std::endl;

    b.attack("Arnaud");
    b.beRepaired(3);

    std::cout << std::endl;

    c.beRepaired(5);
    for (int i = 0; i < 3; i++)
        c.attack("the whole world");
    c.beRepaired(5);
    c.guardGate();
    c.beRepaired(10);

    std::cout << std::endl;
    return (0);
}
