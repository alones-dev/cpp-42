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
    (void)rhs;
    return *this;
}

bool isNumber(char c)
{
    return c >= '0' && c <= '9';
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool isValidValue(char c, bool checkSpace)
{
    return isNumber(c) || isOperator(c) || (checkSpace && (c == ' ' || c == '\t'));
}

bool isValidRPN(std::string const &rpn)
{
    int countNb = 0;
    int countOperator = 0;

    if (rpn.empty())
        return false;

    for (size_t i = 0; i < rpn.size() - 1; i++)
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

int evaluateRPN(std::string const &rpn)
{
    std::stack<int> s;
    for (size_t i = 0; i < rpn.size(); i++)
    {
        if (isNumber(rpn[i]))
            s.push(rpn[i] - '0');
        else if (isOperator(rpn[i]))
        {
            int op2 = s.top(); 
            s.pop();
            int op1 = s.top(); 
            s.pop();
            int result = 0;
            switch (rpn[i])
            {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }
            s.push(result);
        }
    }
    return s.top();
}

void RPN::execute(std::string const &rpn)
{
    if (!isValidRPN(rpn))
    {
        std::cout << "Error: invalid expression" << std::endl;
        return;
    }

    int result = evaluateRPN(rpn);

    std::cout << result << std::endl;
}