/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:04:02 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/07 12:44:27 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat  superadmin("Super-Admin", 1);
    Bureaucrat  admin("Admin", 20);
    Bureaucrat  moderator("Moderator", 80);
    Bureaucrat  user("User", 150);

    std::cout << std::endl << "===== List of bureaucrats =====" << std::endl;
    std::cout << superadmin << std::endl;
    std::cout << admin << std::endl;
    std::cout << moderator << std::endl;
    std::cout << user << std::endl;
    std::cout << "===== List of bureaucrats =====" << std::endl << std::endl;

    PresidentialPardonForm    pardon("McAfee");
    RobotomyRequestForm       robotomy("Neo");
    ShrubberyCreationForm     shrubbery("garden");

    std::cout << std::endl << "===== Trying to sign pardon =====" << std::endl;
    user.signForm(pardon);
    moderator.signForm(pardon);
    admin.signForm(pardon);
    superadmin.signForm(pardon);
    std::cout <<  "===== Trying to sign pardon =====" << std::endl << std::endl;

    std::cout << "===== Trying to sign robotomy =====" << std::endl;
    user.signForm(robotomy);
    moderator.signForm(robotomy);
    admin.signForm(robotomy);
    superadmin.signForm(robotomy);
    std::cout <<  "===== Trying to sign robotomy =====" << std::endl << std::endl;

    std::cout << "===== Trying to sign shrubbery =====" << std::endl;
    user.signForm(shrubbery);
    moderator.signForm(shrubbery);
    admin.signForm(shrubbery);
    superadmin.signForm(shrubbery);
    std::cout <<  "===== Trying to sign shrubbery =====" << std::endl << std::endl;

    ///////////////////

    std::cout << std::endl << "===== Trying to execute pardon =====" << std::endl;
    user.executeForm(pardon);
    moderator.executeForm(pardon);
    admin.executeForm(pardon);
    superadmin.executeForm(pardon);
    std::cout <<  "===== Trying to execute pardon =====" << std::endl << std::endl;

    std::cout << "===== Trying to execute robotomy =====" << std::endl;
    user.executeForm(robotomy);
    moderator.executeForm(robotomy);
    admin.executeForm(robotomy);
    superadmin.executeForm(robotomy);
    std::cout <<  "===== Trying to execute robotomy =====" << std::endl << std::endl;

    std::cout << "===== Trying to execute shrubbery =====" << std::endl;
    user.executeForm(shrubbery);
    moderator.executeForm(shrubbery);
    admin.executeForm(shrubbery);
    superadmin.executeForm(shrubbery);
    std::cout <<  "===== Trying to execute shrubbery =====" << std::endl << std::endl;

	return 0;
}
