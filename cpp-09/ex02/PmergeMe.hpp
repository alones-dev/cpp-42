/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:24:42 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/22 22:25:35 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &cpy);
        ~PmergeMe();

        PmergeMe &operator=(const PmergeMe &rhs);
};

#endif