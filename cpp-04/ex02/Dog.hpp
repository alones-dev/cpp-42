/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:39:16 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/03 15:07:37 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	public:
		Dog();
		Dog(Dog const &cpy);
		virtual ~Dog();

		Dog &operator=(Dog const &rhs);

		virtual void makeSound() const;
		Brain* getBrain() const;
	private:
		Brain *_brain;
};

#endif
