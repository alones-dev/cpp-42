/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:01:41 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/07 12:32:52 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &cpy) : AForm(cpy)
{
	*this = cpy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (this != &rhs)
		this->_target = rhs.getTarget();
	return *this;
}

std::string PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
		
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;

	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
