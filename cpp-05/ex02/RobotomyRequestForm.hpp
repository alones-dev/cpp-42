/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:02:23 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/07 12:37:08 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(RobotomyRequestForm const &cpy);
		~RobotomyRequestForm();

		RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

		std::string getTarget() const;
		void execute(Bureaucrat const &executor) const;
};

#endif
