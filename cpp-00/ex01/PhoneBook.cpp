/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:54:28 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/17 09:26:41 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"

PhoneBook::PhoneBook()
{
	_index = 0;
	_nb_contact = 0;
}

PhoneBook::~PhoneBook()
{
}

int PhoneBook::get_index()
{
	return (this->_index);
}

std::string PhoneBook::_get_input(std::string msg)
{
	std::string input;
	bool isValid = false;

	do
	{
		std::cout << "\033[1;36m" << msg << "\033[0m";
		std::getline(std::cin, input);
		if (std::cin.fail())
			break;
		if (input.empty())
			std::cout << "\033[0;31m❌ Input can't be empty\033[0m" << std::endl;
		else if (!is_valid_word(input))
			std::cout << "\033[0;31m❌ Invalid input\033[0m" << std::endl;
		else
			isValid = true;
		if (msg == "Phone number: ")
		{
			if (input.length() != 10)
			{
				std::cout << "\033[0;31m❌ Phone number must be 10 digits\033[0m" << std::endl;
				isValid = false;
			}
			else if (!is_number(input))
			{
				std::cout << "\033[0;31m❌ Phone number must be a number\033[0m" << std::endl;
				isValid = false;
			}
		}
	} while (!isValid);
	return (input);
}

void PhoneBook::add_contact(Contact contact)
{
	contact.set_first_name(this->_get_input("First name: "));
	contact.set_last_name(this->_get_input("Last name: "));
	contact.set_nickname(this->_get_input("Nickname: "));
	contact.set_phone_number(this->_get_input("Phone number: "));
	contact.set_darkest_secret(this->_get_input("Darkest secret: "));

	if (this->_index < 8)
	{
		this->_contacts[this->_index] = contact;
		this->_index++;
		if (this->_nb_contact < 8)
			this->_nb_contact++;
	}
	else
	{
		this->_index = 0;
		this->_contacts[this->_index] = contact;
		this->_index++;
	}
	std::cout << "\033[0;32m✅ New contact added\033[0m";
}

void PhoneBook::print_contacts()
{
	std::cout << "\033[1;36m_____________________________________________" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|                 PHONEBOOK                 |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	for (int i = 0; i < this->_nb_contact; i++)
	{
		std::cout << "|";
		std::cout << "\033[0m" << std::setw(10) << i << "\033[1;36m|";
		std::cout << "\033[0m" << std::setw(10) << trunc_word(this->_contacts[i].get_first_name()) << "\033[1;36m|";
		std::cout << "\033[0m" << std::setw(10) << trunc_word(this->_contacts[i].get_last_name()) << "\033[1;36m|";
		std::cout << "\033[0m" << std::setw(10) << trunc_word(this->_contacts[i].get_nickname()) << "\033[1;36m|" << std::endl;
		std::cout << "|__________|__________|__________|__________|\033[0m" << std::endl;
	}
}

void PhoneBook::search_contact(int index)
{
	if (index > this->_nb_contact - 1 || index < 0)
	{
		std::cout << "\033[0;31m❌ Invalid index\033[0m";
		return;
	}
	std::cout << std::endl;
	std::cout << "\033[1;36mFirst name: \033[0m" << _contacts[index].get_first_name() << std::endl;
	std::cout << "\033[1;36mLast name: \033[0m" << _contacts[index].get_last_name() << std::endl;
	std::cout << "\033[1;36mNickname: \033[0m" << _contacts[index].get_nickname() << std::endl;
	std::cout << "\033[1;36mPhone number: \033[0m" << _contacts[index].get_phone_number() << std::endl;
	std::cout << "\033[1;36mDarkest secret: \033[0m" << _contacts[index].get_darkest_secret() << std::endl;
}
