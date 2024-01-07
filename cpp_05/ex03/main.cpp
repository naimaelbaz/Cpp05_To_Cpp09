/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:17:22 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/07 11:13:18 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern I1;
	AForm *ob;
	Intern I2;
	AForm *ob1;
	Intern I3;
	AForm *ob2;
	try
	{
		// ShrubberyCreationForm
		try
		{
			ob = I1.makeForm("Shrubbery creation", "file");
			if (!ob)
				throw "";
			Bureaucrat bur1("b1", 136);
			bur1.signForm(*ob);
			bur1.executeForm(*ob);
		}
		catch(const char *e)
		{
			std::cerr << e << '\n';
		}

		// RobotomyRequestForm
		try
		{
			ob1 = I2.makeForm("Robotomy request", "Robot");
			if (!ob1)
				throw "";
			Bureaucrat bur2("b2", 40);
			bur2.signForm(*ob1);
			bur2.executeForm(*ob1);
		}
		catch(const char *e)
		{
			std::cerr << e << '\n';
		}

		// PresidentialPardonForm
		try
		{
			ob2 = I3.makeForm("Presidential pardon", "prisoner");
			if (!ob2)
				throw "";
			Bureaucrat bur3("b3", 4);
			bur3.signForm(*ob2);
			bur3.executeForm(*ob2);
		}
		catch(const char *e)
		{
			std::cerr << e << '\n';
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete ob;
	delete ob1;
	delete ob2;
	return (0);
}