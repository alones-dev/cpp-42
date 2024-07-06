/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:25:47 by kdaumont          #+#    #+#             */
/*   Updated: 2024/07/07 00:12:01 by kdaumont         ###   ########.fr       */
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

void sortVector(std::vector<int> & vec)
{
    bool isPair = vec.size() % 2;
    std::vector< std::pair<int, int> > pairVec;
    std::pair<int, int> tmp;

    pairVec.resize(vec.size() / 2);
    for (std::size_t i = 0; i < vec.size(); i++)
    {
        if (isPair && i + 1 == vec.size())
        {
            tmp.first = vec[i];
            tmp.second = 0;
        }
        else if (i % 2 == 0)
            pairVec[i / 2].first = vec[i];
        else
            pairVec[i / 2].second = vec[i];
    }

    vec.clear();
    for (std::vector< std::pair<int, int> >::iterator it = pairVec.begin(); it != pairVec.end(); it++)
    {
        if (it->first > it->second)
            std::swap(it->first, it->second);
    }

    
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

    sortVector(vec);
    
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

    // sort deque
    (void)dq;
    gettimeofday(&end, NULL);

    return ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec));
}