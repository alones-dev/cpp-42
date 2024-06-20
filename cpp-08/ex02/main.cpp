/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:29:57 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/20 09:31:31 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
    {
        std::cout << "Subject test:" << std::endl << std::endl;
        MutantStack<int> mstack;
    
        mstack.push(5);
        mstack.push(17);
        std::cout << "First value: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "MutantStack size: " << mstack.size() << std::endl << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        std::cout << "MutantStack values:" << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        std::stack<int> s(mstack);
        
        std::cout << std::endl << "Stack values:" << std::endl;
        while (!s.empty())
        {
            std::cout << s.top() << std::endl;
            s.pop();
        }
        std::cout << "Final size: " << s.size() << std::endl;
    }
    std::cout << std::endl << "-----------------" << std::endl << std::endl;
    {
        std::cout << "List test:" << std::endl << std::endl;
        std::list<int> stack;

        stack.push_back(5);
        stack.push_back(17);
        std::cout << "First value: " << stack.back() << std::endl;
        stack.pop_back();
        std::cout << "List size: " << stack.size() << std::endl << std::endl;
        stack.push_back(3);
        stack.push_back(5);
        stack.push_back(737);
        stack.push_back(0);
        std::list<int>::iterator it = stack.begin();
        std::list<int>::iterator ite = stack.end();
        ++it;
        --it;
        std::cout << "List values:" << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        std::list<int> s(stack);

        std::cout << std::endl << "New list values:" << std::endl;
        while (!s.empty())
        {
            std::cout << s.back() << std::endl;
            s.pop_back();
        }
        std::cout << "Final size: " << s.size() << std::endl;
    }
    
    return 0;
}
