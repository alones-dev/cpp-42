/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:37:40 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/14 11:01:49 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

struct Data
{
	std::string s1;
	std::string s2;
	unsigned int n;
};

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const & cpy);
	public:
		~Serializer();

		Serializer & operator=(Serializer const & cpy);

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
