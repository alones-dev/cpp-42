/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:03:56 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/20 17:11:49 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & cpy)
{
	*this = cpy;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & cpy)
{
	(void)cpy;
	return *this;
}

/* TODO :
	- manage spaces ("      2024-06-06     |  5")
	- 2147483647 -> invalid value (>  too large a number)
*/

void deleteSpace(std::string & str)
{
	if (str[0] == ' ')
		str.erase(0, 1);
	if (str[str.length() - 1] == ' ')
		str.erase(str.length() - 1, 1);
}

int strtoint(std::string const & str)
{
	std::istringstream iss(str);
	int tmpInt;
	iss >> tmpInt;

	if (iss.fail() || !iss.eof())
		return -1;

	return tmpInt;
}

std::map<int, int>monthsMap()
{
	std::map<int, int> months;
	
	months[1] = 31;
	months[2] = 28;
	months[3] = 31;
	months[4] = 30;
	months[5] = 31;
	months[6] = 30;
	months[7] = 31;
	months[8] = 31;
	months[9] = 30;
	months[10] = 31;
	months[11] = 30;
	months[12] = 31;

	return months;
}

float checkValue(std::string & value)
{
	char *end;
	float tmpFloat = strtof(value.c_str(), &end);
	std::ostringstream oss;
    oss << tmpFloat;
    std::string tmpStr = oss.str();
	
	if (tmpStr != value)
	{
		std::cerr << "Error: invalid value." << std::endl;
		return -1;
	}

	if (tmpFloat < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return -1;
	}

	if (tmpFloat > static_cast<float>(2147483647))
	{
		std::cerr << "Error: too large a number." << std::endl;
		return -1;
	}

	return tmpFloat;
}

std::string checkDate(std::string & date)
{
	if (date.length() != 10)
	{
		std::cerr << "Error: invalid date." << std::endl;
		return "Error";
	}
	
	int year = strtoint(date.substr(0, 4));
	int month = strtoint(date.substr(5, 2));
	int day = strtoint(date.substr(8, 2));

	if (year < BTC_CREATION || year > ACT_DATE)
	{
		std::cerr << "Error: invalid year." << std::endl;
		return "Error";
	}

	if (month < 1 || month > 12)
	{
		std::cerr << "Error: invalid month." << std::endl;
		return "Error";
	}

	std::map<int, int> months = monthsMap();
	if (day < 1 || day > months[month])
	{
		std::cerr << "Error: invalid day." << std::endl;
		return "Error";
	}

	return date;
}

void processInfos(std::string & date, std::string & value)
{
	float chekedValue = checkValue(value);
	std::string chekedDate = checkDate(date);

	if (chekedValue != -1 && chekedDate != "Error")
		std::cout << date << " => " << value << std::endl;
}

void BitcoinExchange::execute(std::string const & file)
{
	std::ifstream inputFile(file.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	
	std::getline(inputFile, line);
	if (line != "date | value")
	{
		std::cerr << "Error: wrong format." << std::endl;
		inputFile.close();
		return;
	}

	while (inputFile.good())
	{
		std::size_t pos;
		std::string date;
		std::string value;
		
		std::getline(inputFile, line);
		pos = line.find("|");
		if (line.empty())
			continue;
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
		}
		else
		{
			date = line.substr(0, pos);
			deleteSpace(date);

			value = line.substr(pos + 1, line.length());
			deleteSpace(value);

			processInfos(date, value);
		}
	}

	inputFile.close();
}
