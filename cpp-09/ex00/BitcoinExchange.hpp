/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:04:06 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/20 22:14:45 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <sstream>

#define PATH_CSV "./data.csv"
#define BTC_CREATION 2009
#define ACT_DATE 2024

class BitcoinExchange
{
	private:
		std::map<std::string, float> _csv;
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const & cpy);
		~BitcoinExchange();

		BitcoinExchange & operator=(BitcoinExchange const & cpy);

		void execute(std::string const & file);
};

#endif
