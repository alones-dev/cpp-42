/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:17:01 by kdaumont          #+#    #+#             */
/*   Updated: 2024/06/14 14:12:58 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	Base* base = NULL;
	static bool error = false;
	if (!error)
	{
		srand(time(NULL));
		error = true;
	}
	int rdm = rand() % 3;

	switch (rdm)
	{
		case 0:
			base = new A;
			break;
		case 1:
			base = new B;
			break;
		case 2:
			base = new C;
			break;
	}
	
	return base;
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
		(void)a;
	}
	catch(std::exception &e) {}
	try 
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;	
		(void)b;
	}
	catch(std::exception &e) {}
	try 
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;	
		(void)c;
	}
	catch(std::exception &e) {}
}

int main()
{
	srand(time(0));

	Base* b1 = generate();
	Base* b2 = generate();
	Base* b3 = generate();
	Base* b4 = generate();
	Base* b5 = generate();

	

	std::cout << "Identify b1" << std::endl;
	identify(b1);
	identify(*b1);

	std::cout << "Identify b2" << std::endl;
	identify(b2);
	identify(*b2);

	std::cout << "Identify b3" << std::endl;
	identify(b3);
	identify(*b3);

	std::cout << "Identify b4" << std::endl;
	identify(b4);
	identify(*b4);
	
	std::cout << "Identify b5" << std::endl;
	identify(b5);
	identify(*b5);
	
	
	delete b1;

	return 0;
}
