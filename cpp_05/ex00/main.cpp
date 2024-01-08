/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:17:22 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/08 11:06:59 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat Bur1("Bureaucrat1", 15);
		Bur1.decrementGrage();
		std::cout << Bur1 << '\n';
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	try
	{
		Bureaucrat Bur2("Bureaucrat2", 0);
		Bur2.decrementGrage();
		std::cout << Bur2 << '\n';
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
}