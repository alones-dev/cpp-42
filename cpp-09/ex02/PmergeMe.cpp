/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:25:47 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/27 14:37:12 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &cpy)
{
    *this = cpy;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
    (void)rhs;
    return (*this);
}

std::string ltostr(long int nb)
{
    std::stringstream ss;
    
    ss << nb;
    return ss.str();
}

bool checkArguments(char **av)
{
    long int tmp;
    char *end;

    for (int i = 1; av[i]; i++)
    {
        tmp = strtol(av[i], &end, 10);
        if (*end != '\0')
            return (false);
        if (ltostr(tmp) != av[i])
            return (false);
        if (tmp < 0)
            return (false);
        if (tmp > 2147483647)
            return (false);
    }

    return (true);
}

time_t PmergeMe::processVector(char **av, std::vector<int> & vec)
{
    if (!checkArguments(av))
    {
        std::cout << "Error: bad arguments type" << std::endl;
        exit(1);
    }

    struct timeval start, end;
    gettimeofday(&start, NULL);

    for (int i = 1; av[i]; i++)
        vec.push_back(atoi(av[i]));
        
    std::sort(vec.begin(), vec.end());
    
    gettimeofday(&end, NULL);

    return ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec));
}

time_t PmergeMe::processDeque(char **av, std::deque<int> & dq)
{
    if (!checkArguments(av))
    {
        std::cout << "Error: bad arguments type" << std::endl;
        exit(1);
    }

    struct timeval start, end;
    gettimeofday(&start, NULL);

    for (int i = 1; av[i]; i++)
        dq.push_back(atoi(av[i]));
    
    std::sort(dq.begin(), dq.end());

    gettimeofday(&end, NULL);

    return ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec));
}