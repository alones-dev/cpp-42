/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:45:07 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/07 15:58:13 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &cpy)
{
	*this = cpy;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return *this;
}

AForm* Intern::makeForm(std::string const form, std::string const target)
{
}
