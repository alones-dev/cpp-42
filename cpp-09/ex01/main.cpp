/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 23:54:12 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/20 23:56:28 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: wrong number of arguments\n";
        std::cout << "Usage: ./RPN <expression>" << std::endl;
        return 1;
    }

    RPN rpn;

    rpn.execute(av[1]);

    return 0;
}