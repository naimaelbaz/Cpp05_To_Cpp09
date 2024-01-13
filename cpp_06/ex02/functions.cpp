/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:28:13 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/13 19:06:26 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <random>
#include <iostream>

int randomNumbers()
{
	std::srand(time(0));
	return ((std::rand() % 3));
}

Base * generate(void)
{
	if (randomNumbers() == 0)
		return (new A);
	else if (randomNumbers() == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "the actual type of the object p(pointer) is : A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "the actual type of the object p(pointer) is : B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "the actual type of the object p(pointer) is : C\n";
	else
		std::cout << "bad_cast: No one was the actual type of p(pointer)\n";
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "the actual type of the object p(reference) is : A\n";
	}
	catch(const std::exception& e)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "the actual type of the object p(reference) is : B\n";
		}
		catch(const std::exception& e)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "the actual type of the object p(reference) is : C\n";
				
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << ": No one was the actual type of p(reference)"<< '\n';
			}
		}
	}
}