/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:33:43 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/14 11:40:22 by kdaumont         ###   ########.fr       */
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

int isPseudo(std::string const & str)
{
	if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return (1);
	}
	
	if (str == "+inf" || str == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return (1);
	}

	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return (1);
	}

	return (0);
}

void toChar(std::string const & str)
{
	int value = std::atoi(str.c_str());
	
	if (str.length() == 1 && !std::isdigit(str[0]))
	{
		std::cout << "char: '" << str << "'" << std::endl;
		return;
	}
	if (value >= 32 && value <= 126)
	{
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		return;
	}
	if ((value >= 0 && value <= 31) || value == 127)
	{
		std::cout << "char: Non displayable" << std::endl;
		return;
	}
	std::cout << "char: impossible" << std::endl;
}

void toInt(std::string const & str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
	else if (((str[0] == '-' || str[1] == '+') && isdigit(str[1])) || isdigit(str[0]))
		std::cout << "int: " << static_cast<int>(std::atoi(str.c_str())) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

void toFloat(std::string const & str)
{
	char *end;
	float tmp = strtof(str.c_str(), &end);
	
	if (str.length() == 1 && !isdigit(str[0]))
		std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
	else if ((str[0] == '-' || str[0] == '+') && isdigit(str[1]))
	{
		if (str.find('.') != std::string::npos && *end != 'f')
			std::cout << "float: " << str << "f" << std::endl;
		else if (str.find('.') != std::string::npos && *end == 'f')
			std::cout << "float: " << str << std::endl;
		else
			std::cout << "float: " << str << ".0f" << std::endl;
	}
	else if (isdigit(str[0]))
	{
		if (str.find('.') != std::string::npos && *end != 'f')
			std::cout << "float: " << str << "f" << std::endl;
		else if (str.find('.') != std::string::npos && *end == 'f')
			std::cout << "float: " << str << std::endl;
		else
			std::cout << "float: " << str << ".0f" << std::endl;
	}
	else
		std::cout << "float: impossible" << std::endl;
	(void)tmp;
}

void toDouble(std::string const & str)
{
	char *end;
	float tmp = strtof(str.c_str(), &end);
	
	if (str.length() == 1 && !isdigit(str[0]))
		std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
	else if ((str[0] == '-' || str[0] == '+') && isdigit(str[1]))
	{
		if (str.find('.') != std::string::npos && *end != 'f')
			std::cout << "double: " << str << std::endl;
		else if (str.find('.') != std::string::npos && *end == 'f')
			std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
		else
			std::cout << "double: " << str << ".0" << std::endl;
	}
	else if (isdigit(str[0]))
	{
		if (str.find('.') != std::string::npos && *end != 'f')
			std::cout << "double: " << str << std::endl;
		else if (str.find('.') != std::string::npos && *end == 'f')
			std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
		else
			std::cout << "double: " << str << ".0" << std::endl;
	}
	else
		std::cout << "double: impossible" << std::endl;
	(void)tmp;
}

void ScalarConverter::convert(std::string const & str)
{
	if (isPseudo(str))
		return;

	toChar(str);
	toInt(str);
	toFloat(str);
	toDouble(str);
}
