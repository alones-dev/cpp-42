/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:52:50 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/16 10:25:52 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl harl;
    std::string input;
    
    while (1)
    {
        std::cout << "\033[0;35mEnter a level of complaint (DEBUG, INFO, WARNING, ERROR) or 'exit' to quit: \033[0m";
        std::getline(std::cin, input);
        if (std::cin.fail())
            break;
        if (input == "exit" || input == "EXIT")
            break;
        harl.complain(input);
    }

    return (0);
}
