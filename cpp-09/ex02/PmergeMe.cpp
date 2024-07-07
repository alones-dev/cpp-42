/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:25:47 by kdaumont          #+#    #+#             */
/*   Updated: 2024/07/07 21:48:14 by kdaumont         ###   ########.fr       */
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

    // Pairs creation
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
    
    // Sort pairs
    for (std::vector< std::pair<int, int> >::iterator it = pairVec.begin(); it != pairVec.end(); it++)
    {
        if (it->first > it->second)
            std::swap(it->first, it->second);
    }

    // Merge sort (fusion sort)
    mergeSort(pairVec);

    // Fill vec with merge sorted values
    for (std::vector< std::pair<int, int> >::iterator it = pairVec.begin(); it != pairVec.end(); it++)
    {
        if (it == pairVec.begin())
            vec.push_back(it->first);
        vec.push_back(it->second);
    }
    pairVec.erase(pairVec.begin());
    if (isPair)
        pairVec.push_back(tmp);

    // Insertion sort
    std::vector<std::size_t> groupSize = groupSizes< std::vector<std::size_t> >(pairVec.size());

    std::size_t k = 0;
    for (std::size_t i = 0; i < groupSize.size(); i++)
    {
        for (std::size_t j = groupSize[i]; j > 0; j--)
        {
            int x = pairVec[k + j - 1].first;
            int pos = binarySearch(vec, x);
            vec.insert(vec.begin() + pos, x);
        }
        k += groupSize[i];
    }
}

void sortDeque(std::deque<int> & dq)
{
    bool isPair = dq.size() % 2;
    std::deque< std::pair<int, int> > pairDq;
    std::pair<int, int> tmp;

    // Pairs creation
    pairDq.resize(dq.size() / 2);
    for (std::size_t i = 0; i < dq.size(); i++)
    {
        if (isPair && i + 1 == dq.size())
        {
            tmp.first = dq[i];
            tmp.second = 0;
        }
        else if (i % 2 == 0)
            pairDq[i / 2].first = dq[i];
        else
            pairDq[i / 2].second = dq[i];
    }

    dq.clear();
    
    // Sort pairs
    for (std::deque< std::pair<int, int> >::iterator it = pairDq.begin(); it != pairDq.end(); it++)
    {
        if (it->first > it->second)
            std::swap(it->first, it->second);
    }

    // Merge sort (fusion sort)
    mergeSort(pairDq);

    // Fill deque with merge sorted values
    for (std::deque< std::pair<int, int> >::iterator it = pairDq.begin(); it != pairDq.end(); it++)
    {
        if (it == pairDq.begin())
            dq.push_back(it->first);
        dq.push_back(it->second);
    }
    pairDq.erase(pairDq.begin());
    if (isPair)
        pairDq.push_back(tmp);

    // Insertion sort
    std::deque<std::size_t> groupSize = groupSizes< std::deque<std::size_t> >(pairDq.size());

    std::size_t k = 0;
    for (std::size_t i = 0; i < groupSize.size(); i++)
    {
        for (std::size_t j = groupSize[i]; j > 0; j--)
        {
            int x = pairDq[k + j - 1].first;
            int pos = binarySearch(dq, x);
            dq.insert(dq.begin() + pos, x);
        }
        k += groupSize[i];
    }
}

time_t PmergeMe::processVector(char **av, std::vector<int> & vec)
{
    struct timeval start, end;
    gettimeofday(&start, NULL);
    
    if (!checkArguments(av))
    {
        std::cout << "Error: bad arguments type" << std::endl;
        exit(1);
    }

    for (int i = 1; av[i]; i++)
        vec.push_back(atoi(av[i]));

    if (!isSorted(vec))
        sortVector(vec);
    
    gettimeofday(&end, NULL);

    return ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec));
}

time_t PmergeMe::processDeque(char **av, std::deque<int> & dq)
{
    struct timeval start, end;
    gettimeofday(&start, NULL);
    
    if (!checkArguments(av))
    {
        std::cout << "Error: bad arguments type" << std::endl;
        exit(1);
    }

    for (int i = 1; av[i]; i++)
        dq.push_back(atoi(av[i]));

    if (!isSorted(dq))
        sortDeque(dq);

    gettimeofday(&end, NULL);

    return ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec));
}
