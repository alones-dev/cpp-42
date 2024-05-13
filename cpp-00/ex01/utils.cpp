/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:06:18 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/13 14:09:23 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

bool is_number(std::string str)
{
	for (unsigned long i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

std::string trunc_word(std::string word)
{
	if (word.length() > 10)
	{
		word = word.substr(0, 9);
		word += ".";
	}
	return (word);
}
