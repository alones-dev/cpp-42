/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:32:23 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/15 14:01:54 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "\033[0;31mError: wrong number of arguments\033[0m" << std::endl;
        return (1);
    }
    
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
    {
        std::cout << "\033[0;31mError: could not open source file\033[0m" << std::endl;
        return (1);
    }

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile.is_open())
    {
        std::cout << "\033[0;31mError: could not create output file\033[0m" << std::endl;
        inputFile.close();
        return (1);
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        outputFile << line << std::endl;
    }

    inputFile.close();
    outputFile.close();
}
