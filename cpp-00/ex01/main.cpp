/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:54:44 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/13 14:42:32 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void add_contact(PhoneBook &phonebook)
{
	Contact new_contact;

	phonebook.add_contact(new_contact);
}

void search_contact(PhoneBook &phonebook)
{
	if (phonebook.get_index() == 0)
	{
		std::cout << "\033[0;31m❌ No contacts available\033[0m";
		return;
	}
	else
	{
		std::string index;

		phonebook.print_contacts();

		std::cout << "\033[1;34mEnter the index of the contact you want to see (0-7): \033[0m";
		getline(std::cin, index);
		if (std::cin.fail())
			return;
		if (index.length() != 1 || !isdigit(index[0]) || index[0] < '0' || index[0] > '7')
		{
			std::cout << "\033[0;31m❌ Invalid index\033[0m";
			return;
		}
		phonebook.search_contact(index[0] - '0');
	}
}

int main()
{
	PhoneBook phonebook;

	std::cout << "\033[1;35mWelcome to the PhoneBook\033[0m" << std::endl;
	while (1)
	{
		std::string input;

		std::cout << "\033[1;34mPlease enter a command (ADD, SEARCH or EXIT): \033[0m";
		getline(std::cin, input);
		if (std::cin.fail())
			break;
		if (input == "EXIT")
			break;
		else if (input == "ADD")
			add_contact(phonebook);
		else if (input == "SEARCH")
			search_contact(phonebook);
		else
			std::cout << "\033[0;31m❌ Invalid command\033[0m";
		std::cout << std::endl;
	}
	return (0);
}
