/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:54:47 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/13 14:25:56 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();

	void add_contact(Contact contact);
	void print_contacts();
	void search_contact(int index);

	int get_index();

private:
	std::string _get_input(std::string msg);

	Contact _contacts[8];
	int _index;
	int _nb_contact;
};

#endif
