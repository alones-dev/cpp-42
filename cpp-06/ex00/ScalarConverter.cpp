/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:33:43 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/11 08:59:27 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const & cpy)
{
	(void)cpy;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & cpy)
{
	(void)cpy;
	return *this;
}
