/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 08:44:03 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/31 15:31:06 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap    a("Arnaud");
    ClapTrap    b("Claire");

    std::cout << std::endl;

    a.attack("Claire");
    a.takeDamage(10);
    a.takeDamage(10);
    a.beRepaired(5);
    a.attack("Claire");

    std::cout << std::endl;

    b.beRepaired(3);
    b.attack("Arnaud");
    b.attack("Arnaud");
    b.attack("Arnaud");
    b.beRepaired(3);

    std::cout << std::endl;
}
