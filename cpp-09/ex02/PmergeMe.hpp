/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:24:42 by kdaumont          #+#    #+#             */
/*   Updated: 2024/07/07 14:22:51 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <ctime>
#include <vector>
#include <deque>
#include <algorithm>
#include <sstream>
#include <string>
#include <sys/time.h>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &cpy);
        ~PmergeMe();

        PmergeMe &operator=(const PmergeMe &rhs);

        static time_t processVector(char **av, std::vector<int> &vec);
        static time_t processDeque(char **av, std::deque<int> &dq);
};

template <typename T>
void mergeSort2(T & vec, T & left, T & right)
{
    vec.clear();

    int i = 0;
    int j = 0;

    while (i < left.size() && j < right.size())
    {
        if (left[i].second < right[j].second)
        {
            vec.push_back(left[i]);
            i++;
        }
        else
        {
            vec.push_back(right[j]);
            j++;
        }
    }

    while (i < left.size())
    {
        vec.push_back(left[i]);
        i++;
    }

    while (j < right.size())
    {
        vec.push_back(right[j]);
        j++;
    }
}

template <typename T>
void mergeSort(T & vec)
{
    if (vec.size() > 1)
    {
        T left(vec.begin(), vec.begin() + vec.size() / 2);
        T right(vec.begin() + vec.size() / 2, vec.end());

        mergeSort(left);
        mergeSort(right);

        mergeSort2(vec, left, right);
    }
}

template <typename T>
int binarySearch(T & container, int elt)
{
    int left = 0;
    int right = container.size();
    int mid;

    while (left < right)
    {
        mid = left + (right - left) / 2;

        if (container[mid] == elt)
            return (mid);
        else if (container[mid] < elt)
            left = mid + 1;
        else
            right = mid;
    }

    return (left);
}

template <typename T>
T groupSizes(int elt)
{
    T sizes;
    int i = 0;
    int cur = 2;
    int sum = 0;

    while (sum + cur <= elt)
    {
        sizes.push_back(cur);
        sum += cur;
        cur *= 2;
        i++;
    }
}

template <typename T>
void printContainer(T & container)
{
    for (std::size_t i = 0; i < container.size(); i++)
        std::cout << container[i] << " ";
    std::cout << std::endl;
}

template <typename T>
bool isSorted(T & container)
{
    for (std::size_t i = 0; i < container.size() - 1; i++)
    {
        if (container[i] > container[i + 1])
            return (false);
    }

    return (true);
}

#endif