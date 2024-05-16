/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:52:50 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/16 10:51:13 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "\033[0;31mError: wrong number of arguments\033[0m" << std::endl;
        return (1);
    }
    
    Harl harl;
    int level = harl.get_level(av[1]);    
    
    switch (level)
    {
        case -1:
            std::cout << "\033[0;31mError: wrong level\033[0m" << std::endl;
            break;
        case 1:
            harl.complain("DEBUG");
        case 2:
            harl.complain("INFO");
        case 3:
            harl.complain("WARNING");
        case 4:
            harl.complain("ERROR");
    }

    return (0);
}
