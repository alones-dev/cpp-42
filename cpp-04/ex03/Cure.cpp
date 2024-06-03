/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:54:55 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/03 10:31:24 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(Cure const & copy) : AMateria(copy)
{
}

Cure::~Cure()
{
}

Cure & Cure::operator=(Cure const &rhs)
{
	if (this != &rhs)
		AMateria::operator=(rhs);
	return *this;
}

Cure* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
