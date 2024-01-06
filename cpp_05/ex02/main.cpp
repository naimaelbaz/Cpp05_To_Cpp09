/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:17:22 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/06 13:42:08 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	try
	{
		Bureaucrat bur1("b1", 140);
		RobotomyRequestForm f1("Robot1");
		f1.signForm(bur1);
		Bureaucrat bur2("b2", 4);
		PresidentialPardonForm f2("prisoner");
		f2.signForm(bur2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(char *e)
	{
		std::cerr << e << '\n';
	}
	try
	{
		Bureaucrat bur2("b2", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		 ShrubberyCreationForm f3("file");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}