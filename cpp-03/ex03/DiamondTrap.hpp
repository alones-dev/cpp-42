/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 08:44:18 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/31 15:25:12 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &cpy);
		~DiamondTrap();

		DiamondTrap &operator=(DiamondTrap const &rhs);
		std::string get_name(void) const;
		
		void attack(std::string const &target);
		void whoAmI(void);
	private:
		std::string _name;
};

#endif
