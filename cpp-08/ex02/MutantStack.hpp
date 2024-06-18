/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:30:14 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/18 20:59:06 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template < typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        MutantStack() : std::stack<T, Container>() {};
        MutantStack(MutantStack const & cpy) : std::stack<T, Container>(cpy) 
        {
            *this = cpy;
        }
        ~MutantStack() {}

        MutantStack & operator=(MutantStack const & rhs)
        {
            if (this != &rhs)
                std::stack<T, Container>::operator=(rhs);
            return *this;
        }

        typedef typename Container::iterator iterator;
        
        iterator begin()
        {
            return this->c.begin();
        }
        
        iterator rbegin()
        {
            return this->c.rbegin();
        }

        iterator end()
        {
            return this->c.end();
        }

        iterator rend()
        {
            return this->c.rend();
        }
};

#endif