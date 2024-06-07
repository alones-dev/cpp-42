/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:05:07 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/07 09:21:49 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const name, int grade_to_sign, int grade_to_execute) : _name(name), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw Form::GradeTooHighException();
	else if (grade_to_sign > 150 || grade_to_execute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &cpy) : _name(cpy.getName()), _signed(cpy.getSigned()), _grade_to_sign(cpy.getGradeToSign()), _grade_to_execute(cpy.getGradeToExecute())
{
	*this = cpy;
}

Form::~Form()
{
}

Form &Form::operator=(Form const &rhs)
{
	if (this != &rhs)
		this->_signed = rhs.getSigned();
	return *this;
}

std::string Form::getName() const
{
	return this->_name;
}

bool Form::getSigned() const
{
	return this->_signed;
}

int Form::getGradeToSign() const
{
	return this->_grade_to_sign;
}

int Form::getGradeToExecute() const
{
	return this->_grade_to_execute;
}

void Form::beSigned(Bureaucrat const &signer)
{
	if (signer.getGrade() <= this->_grade_to_sign)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, Form const &src)
{
	out << "Form: " << src.getName() << " is ";
	if (src.getSigned())
		out << "signed";
	else
		out << "not signed" << std::endl;
	out << "Grade to sign the form: " << src.getGradeToSign() << std::endl;
	return out;
}
