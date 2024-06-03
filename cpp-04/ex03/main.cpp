/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:27:58 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/03 13:56:52 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int	defaultTest(void)
{
	std::cout << "Default test" << std::endl;
	std::cout << "------------" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;
	delete bob;
	delete me;
	delete src;
	return (0);
}

int	customTest(void)
{
	std::cout << "Custom test" << std::endl;
	std::cout << "------------" << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());

	AMateria* tmp;
	tmp = src->createMateria("ice");

	ICharacter* zbi = new Character("zbi");
	zbi->equip(tmp);
	zbi->use(0, *zbi);
	zbi->use(249844846, *zbi); 
	zbi->use(-454654, *zbi);
	zbi->use(2, *zbi);
	zbi->unequip(0);
	zbi->use(0, *zbi);
	zbi->unequip(57527057);
	delete src;
	delete zbi;
	delete tmp;
	return (0);
}

int main(void)
{
	defaultTest();
	customTest();
	return (0);
}
