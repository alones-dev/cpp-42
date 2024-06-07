/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:01:10 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/07 11:26:27 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string const name, int grade_to_sign, int grade_to_execute) : _name(name), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw AForm::GradeTooHighException();
	else if (grade_to_sign > 150 || grade_to_execute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &cpy) : _name(cpy.getName()), _signed(cpy.getSigned()), _grade_to_sign(cpy.getGradeToSign()), _grade_to_execute(cpy.getGradeToExecute())
{
	*this = cpy;
}

AForm::~AForm()
{
}

AForm &AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
	{
		(const_cast<std::string &>(this->_name) = rhs.getName());
		this->_signed = rhs.getSigned();
		(const_cast<int &>(this->_grade_to_sign) = rhs.getGradeToSign());
		(const_cast<int &>(this->_grade_to_execute) = rhs.getGradeToExecute());
	}
	return *this;
}

std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::getSigned() const
{
	return this->_signed;
}

int AForm::getGradeToSign() const
{
	return this->_grade_to_sign;
}

int AForm::getGradeToExecute() const
{
	return this->_grade_to_execute;
}

void AForm::beSigned(Bureaucrat const &signer)
{
	if (signer.getGrade() <= this->_grade_to_sign)
	{
		this->_signed = true;
		std::cout << signer.getName() << " signed " << this->_name << std::endl;
	}
	else
		throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

const char *AForm::CantOpenFileException::what() const throw()
{
	return "Can't open file";
}

std::ostream &operator<<(std::ostream &out, AForm const &src)
{
	out << "Form: " << src.getName() << " is ";
	if (src.getSigned())
		out << "signed" << std::endl;
	else
		out << "not signed" << std::endl;
	out << "Grade to sign the form: " << src.getGradeToSign() << std::endl;
	return out;
}
