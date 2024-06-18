/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:03:51 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/18 14:32:29 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void addInt(int &i)
{
	i++;
}

void addStr(std::string &str)
{
	str += "_ok";
}

template <typename T>
void printArray(T const &array, int length)
{
	for (int i = 0; i < length; i++)
		std::cout << i << ": " << array[i] << std::endl;
}

int main()
{
	int array1[5] = {1, 2, 3, 4, 5};
	std::string array2[5] = {"one", "two", "three", "four", "five"};
	
	std::cout << "Array 1 before iter:" << std::endl;
	printArray(array1, 5);
	std::cout << std::endl << "Array 1 after iter:" << std::endl;
	iter(array1, 5, addInt);
	printArray(array1, 5);

	std::cout << std::endl;

	std::cout << "Array 2 before iter:" << std::endl;
	printArray(array2, 5);
	std::cout << std::endl << "Array 2 after iter:" << std::endl;
	iter(array2, 5, addStr);
	printArray(array2, 5);
	
	return 0;
}	

