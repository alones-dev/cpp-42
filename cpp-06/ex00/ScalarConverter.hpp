/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:33:43 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/11 08:51:14 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter();
	public:
		ScalarConverter(ScalarConverter const & cpy);
		~ScalarConverter();

		ScalarConverter & operator=(ScalarConverter const & cpy);

		void convert(std::string const & str);
};

#endif
