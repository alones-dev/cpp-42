/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:30:14 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/20 09:30:40 by kdaumont         ###   ########.fr       */
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
        typedef typename Container::const_iterator const_iterator;
        typedef typename Container::reverse_iterator reverse_iterator;
        typedef typename Container::const_reverse_iterator const_reverse_iterator;
        
        iterator begin()
        {
            return this->c.begin();
        }

        iterator end()
        {
            return this->c.end();
        }

        const_iterator begin() const
        {
            return this->c.begin();
        }

        const_iterator end() const
        {
            return this->c.end();
        }

        reverse_iterator rbegin()
        {
            return this->c.rbegin();
        }

        reverse_iterator rend()
        {
            return this->c.rend();
        }

        const_reverse_iterator rbegin() const
        {
            return this->c.rbegin();
        }

        const_reverse_iterator rend() const
        {
            return this->c.rend();
        }
};

#endif
