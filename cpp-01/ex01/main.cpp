/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:52:50 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/16 12:47:18 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::string input;

    std::cout << "\033[1;36mEnter the name of the horde: \033[0m";
    getline(std::cin, input);
    if (std::cin.fail())
        return (1);
        
    Zombie *horde = zombieHorde(15, input);
    if (!horde)
    {
        std::cerr << "\033[1;31mError: The horde could not be created.\033[0m" << std::endl;
        return (1);
    }
    for (int i = 0; i < 5; i++)
        horde[i].announce();
    delete [] horde;
    return (0);
}
