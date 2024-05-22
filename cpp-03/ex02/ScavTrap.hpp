/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:19:40 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/22 10:15:35 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public :
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &cpy);
		~ScavTrap();

		ScavTrap &operator=(ScavTrap const &rhs);

		void attack(std::string const &target);
		void guardGate(void);
};

#endif
