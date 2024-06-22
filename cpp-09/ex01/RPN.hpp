/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 23:53:55 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/20 23:54:06 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <queue>

class RPN
{
    private:
        std::queue<char> _rpn;
    public:
        RPN();
        RPN(RPN const & cpy);
        ~RPN();

        RPN & operator=(RPN const & rhs);

        void execute(std::string const & rpn);
};

#endif