/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:24:42 by kdaumont          #+#    #+#             */
/*   Updated: 2024/07/07 00:13:01 by kdaumont         ###   ########.fr       */
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
void mergeSort(T & vec)
{
    
}

#endif