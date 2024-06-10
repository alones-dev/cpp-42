/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:04:02 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/10 09:00:48 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat  b1("Jean", 20);
    Bureaucrat  b2("Edward", 5);

    Form        form1("Form1", 30, 1);
    Form        form2("Form2", 10, 1);

    std::cout << std::endl;
	std::cout << form1;
	std::cout << form2;
    std::cout << std::endl;

    try
    {
        Form        invalid1("Form3", 149, 0);
        Form        invalid2("Form3", 151, 1);
    }
    catch (std::exception& e)
    {
        std::cout << "Unable to create form because " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        b2.signForm(form1);
        b2.signForm(form2);
    }
    catch (std::exception& e)
    {
        std::cout << "Unable to sign form because " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        b1.signForm(form1);
        b1.signForm(form2);
    }
    catch (std::exception& e)
    {
        std::cout << "Unable to sign form because " << e.what() << std::endl;
    }

	std::cout << std::endl;
	std::cout << form1;
	std::cout << form2;
    std::cout << std::endl;

	return 0;
}
