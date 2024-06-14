/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:17:01 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/14 11:43:46 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	srand(time(0));
	int rdm = rand() % 3;

	switch (rdm)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Error" << std::endl;
}

void identify(Base& p)
{
	try 
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;	
	}
	catch(std::bad_cast &e) {}
	try 
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;	
	}
	catch(std::bad_cast &e) {}
	try 
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;	
	}
	catch(std::bad_cast &e) {}
}

int main()
{
	return 0;
}
