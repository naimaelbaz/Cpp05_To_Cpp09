/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:17:22 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/06 15:56:19 by nel-baz          ###   ########.fr       */
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
		bur1.signForm(f1);
		bur1.executeForm(f1);
		Bureaucrat bur2("b2", 4);
		PresidentialPardonForm f2("prisoner");
		bur2.signForm(f2);
		bur2.executeForm(f2);
		Bureaucrat bur3("b3", 4);
		ShrubberyCreationForm f3("file");
		f3.execute(bur3);
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
		Bureaucrat bur2("b3", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}