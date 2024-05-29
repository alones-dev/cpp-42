/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:05:11 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/29 09:28:48 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
	Animal *animals[10];
	// test +100 idees
	std::cout << "Start the creation of 10 animals" << std::endl;

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "Animals created, let's listen to them:" << std::endl;

	for (int i = 0; i < 10; i++)
	{
		animals[i]->makeSound();
		std::cout << "His type: " << animals[i]->getType() << std::endl;
	}

	std::cout << "Start delete the 10 animals" << std::endl;
	for (int i = 0; i < 10; i++)
		delete animals[i];
	std::cout << "All animals are deleted" << std::endl;

	Dog dog1;
	Cat cat1;

	Brain* dogBrain = dog1.getBrain();
	Brain* catBrain = cat1.getBrain();

	dogBrain->setIdea(0, "I am a dog");
	catBrain->setIdea(0, "I am a cat");

	std::cout << "Dog idea: " << dogBrain->getIdea(0) << std::endl;
	std::cout << "Cat idea: " << catBrain->getIdea(0) << std::endl;

	return 0;
}
