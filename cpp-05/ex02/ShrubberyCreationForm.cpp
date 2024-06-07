/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:02:46 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/07 12:40:17 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &cpy) : AForm(cpy)
{
	*this = cpy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
		this->_target = rhs.getTarget();
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
		
	std::ofstream out((executor.getName() + "_shrubbery").c_str());
	if (!out.is_open())
		throw AForm::CantOpenFileException();

	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	
	out << "    oxoxoo    ooxoo" << std::endl;
	out << "  ooxoxo oo  oxoxooo" << std::endl;
	out << " oooo xxoxoo ooo ooox" << std::endl;
	out << " oxo o oxoxo  xoxxoxo" << std::endl;
	out << "  oxo xooxoooo o ooo" << std::endl;
	out << "    ooo\\oo\\  /o/o" << std::endl;
	out << "        \\  \\/ /" << std::endl;
	out << "         |   /" << std::endl;
	out << "         |  |" << std::endl;
	out << "         | D|" << std::endl;
	out << "         |  |" << std::endl;
	out << "         |  |" << std::endl;
	out << "  ______/____\\____" << std::endl;
}
