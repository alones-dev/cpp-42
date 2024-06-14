/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:37:12 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/14 11:02:04 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data*   data = new Data;

    data->s1 = "Hello";
    data->s2 = "World";
    data->n = 42;

    std::cout << "Address of raw data: " << data << std::endl;

    uintptr_t   raw = Serializer::serialize(data);
    Data*       deserialized = Serializer::deserialize(raw);

    std::cout << "Address of deserialized: " << deserialized << std::endl << std::endl;

    std::cout << "--- Checking content ---" << std::endl;
    std::cout << "s1: " << deserialized->s1 << std::endl;
    std::cout << "s2: " << deserialized->s2 << std::endl;
    std::cout << "n: " << deserialized->n << std::endl;
    std::cout << "--- Checking content ---" << std::endl << std::endl;


    delete data;
	
	return 0;
}
