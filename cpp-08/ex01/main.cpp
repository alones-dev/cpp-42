/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 22:27:07 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/18 19:23:12 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    {
        std::cout << "Subject test" << std::endl;

        Span sp = Span(5);
    
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "Test with 50k elements" << std::endl;

        Span sp = Span(50000);

        for (int i = 0; i < 50000; i++)
            sp.addNumber(i + 42);
    
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp.longestSpan() << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "Test ultra methods" << std::endl;

        std::vector<int> vec;
        vec.push_back(6);
        vec.push_back(3);
        vec.push_back(17);
        vec.push_back(42);
        vec.push_back(9);

        Span sp = Span(5);
        sp.addNumberUltra(vec.begin(), vec.end());
        std::cout << "Span:" << std::endl;
        sp.printArray();
        std::cout << std::endl;
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp.longestSpan() << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "Test exceptions" << std::endl;

        Span sp = Span(5);

        sp.addNumber(1);
        
        try
        {
            std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        
        try
        {
            std::cout << "Longest: " << sp.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4);
        sp.addNumber(5);

        std::cout << "Span:" << std::endl;
        sp.printArray();
        std::cout << std::endl;
        
        try
        {
            sp.addNumber(6);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    return 0;
}