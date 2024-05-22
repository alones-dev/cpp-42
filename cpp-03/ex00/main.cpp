/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 08:44:03 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/22 09:18:07 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Bob");
	ClapTrap b("John");

	a.attack("John");
	b.takeDamage(5);
	b.beRepaired(5);
	b.beRepaired(5);
	b.beRepaired(5);
	b.attack("Bob");
	a.takeDamage(5);
	b.attack("Bob");
	a.takeDamage(5);
	b.attack("Bob");
	a.takeDamage(5);
	a.attack("John");
	a.beRepaired(5);
}
