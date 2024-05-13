/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:52:50 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/13 22:25:50 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::string input;

    std::cout << "\033[1;36mGive a name to your stack's zombie: \033[0m";
    getline(std::cin, input);
    if (std::cin.fail())
        return (1);
    
    Zombie stack(input);
    stack.announce();

    std::cout << "\033[1;36mGive a name to your heap's zombie: \033[0m";
    getline(std::cin, input);
    if (std::cin.fail())
        return (1);
        
    Zombie *heap = newZombie(input);
    heap->announce();
    delete heap;

    std::cout << "\033[1;36mGive a name to your random zombie: \033[0m";
    getline(std::cin, input);
    if (std::cin.fail())
        return (1);
        
    randomChump(input);
    
    return (0);
}