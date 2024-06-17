/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 22:27:18 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/17 22:31:59 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>

class Span
{
    private:
        unsigned int _size;
        unsigned int _current;
        int *_array;
    public:
        Span();
        Span(unsigned int size);
        Span(Span const & to_copy);
        ~Span();
        
        Span & operator=(Span const & to_copy);

        void addNumber(int number);

        int shortestSpan();
        int longestSpan();
};

#endif