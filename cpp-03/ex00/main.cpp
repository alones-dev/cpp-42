/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 08:44:03 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/31 15:11:07 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap    a("Jhon Smith");
    ClapTrap    b("Rawid Jeremy");

    std::cout << std::endl;

    a.attack("Rawid Jeremy");
    a.takeDamage(10);
    a.takeDamage(10);
    a.beRepaired(5);
    a.attack("Rawid Jeremy");

    std::cout << std::endl;

    b.beRepaired(3);
    b.attack("Jhon Smith");
    b.attack("Jhon Smith");
    b.attack("Jhon Smith");
    b.beRepaired(3);

    std::cout << std::endl;
}
