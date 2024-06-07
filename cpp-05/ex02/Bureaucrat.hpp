/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:04:13 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/07 12:31:45 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade;
	public:
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &cpy);
		~Bureaucrat();

		Bureaucrat &operator=(Bureaucrat const &rhs);

		void incrementGrade();
		void decrementGrade();

		std::string const getName() const;
		int getGrade() const;

		void signForm(AForm &form);
		void executeForm(AForm const &form);

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
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &src);

#endif
