/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:33:43 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/12 17:41:04 by kdaumont         ###   ########.fr       */
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

void ScalarConverter::convert(std::string const & str)
{
	std::string::size_type sz;
	double d;
	float f;
	int i;
	char c;

	try
	{
		d = std::stod(str, &sz);
		if (sz == str.size())
			std::cout << "double: " << d << std::endl;
		else
			std::cout << "double: impossible" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "double: impossible" << std::endl;
	}

	try
	{
		f = std::stof(str, &sz);
		if (sz == str.size())
			std::cout << "float: " << f << "f" << std::endl;
		else
			std::cout << "float: impossible" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "float: impossible" << std::endl;
	}

	try
	{
		i = std::stoi(str, &sz);
		if (sz == str.size())
			std::cout << "int: " << i << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "int: impossible" << std::endl;
	}

	try
	{
		c = std::stoi(str, &sz);
		if (sz == str.size())
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "char: impossible" << std::endl;
	}
}