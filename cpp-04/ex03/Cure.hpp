/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:52:28 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/03 10:28:04 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Cure : public AMateria
{
	protected:
	
	public:
		Cure();
		Cure(Cure const & copy);
		~Cure();

		Cure & operator=(Cure const &rhs);
		
		virtual Cure* clone() const;
		virtual void use(ICharacter& target);
};

#endif
