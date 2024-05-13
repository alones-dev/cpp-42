/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:52:50 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/13 22:47:20 by kdaumont         ###   ########.fr       */
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
        
    Zombie *horde = zombieHorde(5, input);
    for (int i = 0; i < 5; i++)
        horde[i].announce();
    delete [] horde;
    return (0);
}