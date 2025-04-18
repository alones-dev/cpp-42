/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:05:11 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/04 14:16:23 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
    AAnimal* dog = new Dog();
    AAnimal* cat = new Cat();
    // AAnimal* ani = new AAnimal("Animal"); // Can not be done

    std::cout << std::endl << "=== Make sound for dog and cat ===" << std::endl;
    dog->makeSound();
    cat->makeSound();
    std::cout << std::endl;

    delete dog;
    delete cat;

    return (0);
}
