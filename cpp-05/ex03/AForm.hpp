/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:01:21 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/07 11:26:20 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		bool _signed;
		int const _grade_to_sign;
		int const _grade_to_execute;
	public:
		AForm(std::string const name, int grade_to_sign, int grade_to_execute);
		AForm(AForm const &cpy);
		virtual ~AForm();

		AForm &operator=(AForm const &rhs);

		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(Bureaucrat const &signer);
		virtual void execute(Bureaucrat const &executor) const = 0;
		
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};	

	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class CantOpenFileException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, AForm const &src);

#endif
