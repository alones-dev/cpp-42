/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:05:11 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/03 14:59:47 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;
	
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	
	std::cout << std::endl;

	const WrongAnimal* meta_w = new WrongAnimal();
	const WrongAnimal* j_w = new WrongCat();
	meta_w->makeSound();
	j_w->makeSound();
	
	delete meta;
	delete j;
	delete i;
	
	return 0;
}
