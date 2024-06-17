/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:44:53 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/17 22:25:31 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>

class NoOccurenceException : public std::exception
{
    virtual const char *what() const throw()
    {
        return "Value not found";
    }
};

template <typename T>
int easyfind(T &container, int value)
{
    if (std::find(container.begin(), container.end(), value) != container.end())
        return value;
    throw NoOccurenceException();
}

#endif