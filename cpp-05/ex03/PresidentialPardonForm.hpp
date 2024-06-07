/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:01:53 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/07 12:36:39 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(PresidentialPardonForm const &cpy);
		~PresidentialPardonForm();

		PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

		std::string getTarget() const;
		void execute(Bureaucrat const &executor) const;
};

#endif
