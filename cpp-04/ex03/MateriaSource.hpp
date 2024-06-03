/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:59:00 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/03 11:07:10 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	protected:
		AMateria *_source[4];
	public:
		MateriaSource();
		MateriaSource(MateriaSource const & copy);
		~MateriaSource();

		MateriaSource & operator=(MateriaSource const &rhs);
		
		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};

#endif
