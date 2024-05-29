/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:39:16 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/29 09:18:25 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat const &cpy);
		~Cat();

		Cat &operator=(Cat const &rhs);

		virtual void makeSound() const;
		Brain* getBrain() const;
	private:
		Brain *_brain;
};

#endif
