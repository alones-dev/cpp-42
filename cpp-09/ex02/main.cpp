/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:26:17 by kdaumont          #+#    #+#             */
/*   Updated: 2024/07/07 19:07:07 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void printArgs(char **av)
{
    for (int i = 1; av[i]; i++)
        std::cout << av[i] << " ";
    std::cout << std::endl;
}

void printInfos(char **av, std::vector<int> & vec, size_t size, time_t time1, time_t time2)
{
    std::cout << "Before:\t";
    printArgs(av);

    std::cout << "After:\t";
    printContainer(vec);
    
    std::cout << "Time to process a range of\t" << size << " elements with std::vector\t:\t" << time1 << " us" << std::endl;
    std::cout << "Time to process a range of\t" << size << " elements with std::deque\t:\t" << time2 << " us" << std::endl;
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "Error: wrong number of arguments" << std::endl;
        std::cout << "Usage: ./PmergeMe [...]" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    time_t sortVector = PmergeMe::processVector(av, vec);

    printInfos(av, vec, vec.size(), sortVector, 0);

    return 0;
}
