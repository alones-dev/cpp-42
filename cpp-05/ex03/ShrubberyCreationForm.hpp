/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:02:53 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/07 11:11:33 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm(std::string const target);
		ShrubberyCreationForm(ShrubberyCreationForm const &cpy);
		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

		std::string getTarget() const;
		void execute(Bureaucrat const &executor) const;
};

#endif
