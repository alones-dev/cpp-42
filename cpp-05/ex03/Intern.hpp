/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:45:17 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/07 15:55:36 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		Intern(Intern const &cpy);
		~Intern();

		Intern &operator=(Intern const &rhs);

		AForm* makeForm(std::string const form, std::string const target);
};

#endif
