/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:52:28 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/03 10:27:15 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Ice : public AMateria
{
	protected:
	
	public:
		Ice();
		Ice(Ice const & copy);
		~Ice();

		Ice & operator=(Ice const &rhs);
		
		virtual Ice* clone() const;
		virtual void use(ICharacter& target);
};

#endif
