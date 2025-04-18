/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 22:27:18 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/18 19:09:34 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>

class Span
{
    private:
        unsigned int _size;
        std::vector<int> _array;
    public:
        Span(unsigned int n);
        Span(Span const & cpy);
        ~Span();
        
        Span & operator=(Span const & rhs);

        void addNumber(int number);
        void addNumberUltra(std::vector<int>::iterator begin, std::vector<int>::iterator end);

        int shortestSpan();
        int longestSpan();

        void printArray();

        class ArrayFullException : public std::exception
        {
            virtual const char *what() const throw()
            {
                return "Array is full";
            }
        };
        
        class NoRangeException : public std::exception
        {
            virtual const char *what() const throw()
            {
                return "No range to find";
            }
        };
};

#endif
