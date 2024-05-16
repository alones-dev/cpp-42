/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:52:50 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/16 10:28:10 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*choose_level[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
            (this->*choose_level[i])();
    }
}

void Harl::debug()
{
    std::cout << std::endl << "\033[0;32m[DEBUG]\033[0m" << std::endl;
    std::cout << "\033[1;32mI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !\033[0m" << std::endl;
    std::cout << std::endl;
}

void Harl::info()
{
    std::cout << std::endl << "\033[0;36m[INFO]\033[0m" << std::endl;
    std::cout << "\033[1;36mI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !\033[0m" << std::endl;
    std::cout << std::endl;
}

void Harl::warning()
{
    std::cout << std::endl << "\033[0;33m[WARNING]\033[0m" << std::endl;
    std::cout << "\033[0;33mI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\033[0m" << std::endl;
    std::cout << std::endl;
}

void Harl::error()
{
    std::cout << std::endl << "\033[0;31m[ERROR]\033[0m" << std::endl;
    std::cout << "\033[1;31mThis is unacceptable. I want to speak to the manager now\033[0m" << std::endl;
    std::cout << std::endl;
}
