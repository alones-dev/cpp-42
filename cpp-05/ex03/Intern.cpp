/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:45:07 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/09 18:21:26 by kdaumont         ###   ########.fr       */
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
	std::string list[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	AForm* final = NULL;

	for (int i = 0; i < 3; i++)
	{
		if (form == list[i])
		{
			final = forms[i];
			std::cout << "Intern creates " << form << std::endl;
		}
		else
			delete forms[i];
	}

	if (!final)
		std::cout << "Intern cannot create " << form << " because it does not exist" << std::endl;

	return final;
}
