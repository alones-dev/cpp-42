/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:04:02 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/10 08:56:33 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat  b1("Jean", 5);
    Bureaucrat  b2("Edward", 147);


    std::cout << std::endl << "===== First try -> Incrementing the grade =====" << std::endl;
    try
    {
        while (true)
        {
            std::cout << b1 << std::endl;
            b1.incrementGrade();
        }
    }
    catch (std::exception& e)
    {
        std::cout << "Unable to increment grade: " << e.what() << std::endl;
    }


    std::cout << std::endl << "===== Second try -> Decrementing the grade =====" << std::endl;
    try
    {
        while (true)
        {
            std::cout << b2 << std::endl;
            b2.decrementGrade();
        }
    }
    catch (std::exception& e)
    {
        std::cout << "Unable to increment grade: " << e.what() << std::endl;
    }
    std::cout << std::endl;

	return 0;
}
