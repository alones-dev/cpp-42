/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:02:15 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/10 09:10:39 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &cpy) : AForm(cpy)
{
	*this = cpy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
		this->_target = rhs.getTarget();
	return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::cout << executor.getName() << " executed " << this->getName() << std::endl;

	srand(time(0));

	if (rand() % 2 == 0)
		std::cout << "Drilling noises... " << this->getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Drilling noises... " << this->getTarget() << " has failed to be robotomized." << std::endl; 
}
