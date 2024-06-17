/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:45:10 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/17 22:26:02 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> vector(array, array + 10);
    std::list<int> list(array, array + 10);

    std::cout << "Vector:" << std::endl;
    std::cout << "Try to find 5:" << std::endl;
    try
    {
        easyfind(vector, 5);
        std::cout << "Value found" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << "Try to find 42:" << std::endl;
    try
    {
        easyfind(vector, 42);
        std::cout << "Value found" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl << "List:" << std::endl;
    std::cout << "Try to find 5:" << std::endl;
    try
    {
        easyfind(list, 5);
        std::cout << "Value found" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << "Try to find 42:" << std::endl;
    try
    {
        easyfind(list, 42);
        std::cout << "Value found" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}