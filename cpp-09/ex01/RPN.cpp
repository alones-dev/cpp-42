/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 23:53:39 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/20 23:53:48 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(RPN const & cpy)
{
    *this = cpy;
}

RPN::~RPN()
{
}

RPN & RPN::operator=(RPN const & rhs)
{
    if (this != &rhs)
        this->_rpn = rhs._rpn;
    return *this;
}

bool isNumber(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

bool isValidValue(char c, bool checkSpace)
{
    if (isNumber(c))
        return true;
    if (isOperator(c))
        return true;
    if (checkSpace)
        if (c == ' ' || c == '\t')
            return true;
    return false;
}

bool isValidRPN(std::string const & rpn)
{
    int countNb = 0;
    int countOperator = 0;

    if (rpn.empty())
        return false;

    for (size_t i = 0; i < rpn.size(); i++)
    {
        if (isValidValue(rpn[i], false) && isValidValue(rpn[i + 1], false))
            return false;
    }

    for (size_t i = 0; i < rpn.size(); i++)
    {
        if (countOperator > 0 && countNb == 0)
            return false;
        if (!isValidValue(rpn[i], true))
            return false;
        if (isNumber(rpn[i]))
            countNb++;
        if (isOperator(rpn[i]))
            countOperator++;
    }

    if (countNb - countOperator != 1)
        return false;

    std::queue<char> rpnQueue;
    for (size_t i = 0; i < rpn.size(); i++)
    {
        if (isValidValue(rpn[i], false))
            rpnQueue.push(rpn[i]);
    }

    if (rpnQueue.empty() || rpnQueue.size() == 1)
        return false;
    if (isOperator(rpnQueue.front()) || isOperator(rpnQueue.front() + 1))
        return false;
    if (!isOperator(rpnQueue.back()))
        return false;

    return true;
}

void RPN::execute(std::string const & rpn)
{
    if (!isValidRPN(rpn))
    {
        std::cout << "Error: invalid expression" << std::endl;
        return;
    }

    std::cout << "RPN: " << rpn << std::endl;
}