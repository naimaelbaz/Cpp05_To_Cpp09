/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:17:22 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/06 18:18:16 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

// void pop()
// {
// 	system("leaks Bureaucrat");
// }

int main()
{
	// atexit(pop);
	Intern I1;
	AForm *ob = I1.makeForm("ShrubberyCreationForm", "file");
	Intern I2;
	AForm *ob1 = I2.makeForm("RobotomyRequestForm", "Robot");
	Intern I3;
	AForm *ob2 = I3.makeForm("PresidentialPardonForm", "Robot");
	try
	{
		// ShrubberyCreationForm
		Bureaucrat bur1("b1", 136);
		bur1.signForm(*ob);
		bur1.executeForm(*ob);

		// RobotomyRequestForm
		Bureaucrat bur2("b2", 40);
		bur2.signForm(*ob1);
		bur2.executeForm(*ob1);

		// PresidentialPardonForm
		Bureaucrat bur3("b3", 4);
		bur3.signForm(*ob2);
		bur3.executeForm(*ob2);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(char *e)
	{
		std::cerr << e << '\n';
	}

	delete ob;
	delete ob1;
	delete ob2;
	return (0);
}