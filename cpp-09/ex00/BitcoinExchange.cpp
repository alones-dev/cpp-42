/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:03:56 by kdaumont          #+#    #+#             */
/*   Updated: 2024/07/08 09:47:04 by kdaumont         ###   ########.fr       */
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
	if (this != &cpy)
		_csv = cpy._csv;
	return *this;
}

void deleteSpace(std::string & str)
{
	std::size_t pos = str.find_first_not_of(" \t");
	if (pos != std::string::npos)
		str.erase(0, pos);

	pos = str.find_last_not_of(" \t");
	if (pos != std::string::npos)
		str.erase(pos + 1);
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

std::map<int, int> monthsMap()
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

float checkValue(std::string & value, bool check)
{
	char *end;
	float tmpFloat = strtof(value.c_str(), &end);
	
	if (check)
	{
		if (tmpFloat > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			return -1;
		}
	}

	if (tmpFloat == 0 && end == value.c_str())
	{
		if (check)
			std::cerr << "Error: invalid value." << std::endl;
		return -1;
	}

	if (tmpFloat < 0)
	{
		if (check)
			std::cerr << "Error: not a positive number." << std::endl;
		return -1;
	}

	return tmpFloat;
}

std::string checkDate(std::string & date, bool check)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
	{
		if (check)
			std::cerr << "Error: invalid date format (YYYY-MM-DD)." << std::endl;
		return "Error";
	}
	
	int year = strtoint(date.substr(0, 4));
	int month = strtoint(date.substr(5, 2));
	int day = strtoint(date.substr(8, 2));

	if (year < BTC_CREATION || year > ACT_DATE)
	{
		if (check)
			std::cerr << "Error: invalid year." << std::endl;
		return "Error";
	}

	if (month < 1 || month > 12)
	{
		if (check)
			std::cerr << "Error: invalid month." << std::endl;
		return "Error";
	}
	
	std::map<int, int> months = monthsMap();
	if (day < 1 || day > months[month])
	{
		if (month == 2 && day == 29 && year % 4 == 0)
			return date;
		if (check)
			std::cerr << "Error: invalid day." << std::endl;
		return "Error";
	}

	return date;
}

void processInfos(std::string & date, std::string & value, std::map<std::string, float> & csv)
{
	float checkedValue = checkValue(value, true);
	std::string checkedDate = checkDate(date, true);

	if (checkedValue != -1 && checkedDate != "Error")
	{
		if (csv.find(date) != csv.end())
			std::cout << date << " => " << value << " = " << csv[date] * checkedValue << std::endl;
		else
		{
			std::map<std::string, float>::const_iterator it = csv.lower_bound(date);
			if (it == csv.begin())
				std::cout << "Error: no data for input => " << checkedDate << std::endl;
			else
			{
				it--;
				std::cout << date << " => " << value << " = " << it->second * checkedValue << std::endl;
				return;
			}
		}
	}
}

void parseCSV(std::map<std::string, float> & csv)
{
	std::ifstream inputFile(PATH_CSV);
	if (!inputFile.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		exit(1);
	}

	std::string line;

	std::getline(inputFile, line);
	if (line != "date,exchange_rate")
	{
		std::cerr << "Error: wrong database format." << std::endl;
		inputFile.close();
		exit(1);
	}

	while (inputFile.good())
	{
		std::size_t pos;
		std::string date;
		std::string value;
		
		std::getline(inputFile, line);
		pos = line.find(",");
		if (line.empty())
			continue;
		if (pos == std::string::npos)
		{
			std::cerr << "Error: wrong database input." << line << std::endl;
			exit(1);
		}
		else
		{
			date = line.substr(0, pos);
			deleteSpace(date);

			value = line.substr(pos + 1, line.length());
			deleteSpace(value);

			if (checkValue(value, false) != -1 && checkDate(date, false) != "Error")
				csv.insert(std::pair<std::string, float>(date, strtof(value.c_str(), NULL)));
			else
			{
				std::cerr << "Error: invalid database (some dates or values invalid)." << std::endl;
				exit(1);
			}
		}
	}
	
	if (csv.empty())
	{
		std::cerr << "Error: empty database." << std::endl;
		exit(1);
	}
}

void BitcoinExchange::execute(std::string const & file)
{
	parseCSV(_csv);

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
		std::cerr << "Error: wrong file format." << std::endl;
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

			processInfos(date, value, _csv);
		}
	}

	inputFile.close();
}
