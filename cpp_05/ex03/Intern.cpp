/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:29:13 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/07 12:05:42 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){}

Intern::Intern(const Intern& ob)
{
	*this = ob;
}

Intern &Intern::operator=(const Intern& ob)
{
	(void)ob;
	return (*this);
}

Intern::~Intern() {}

AForm *Intern::CreateShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::CreateRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::CreatePresidential(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string FormName, std::string target)
{
	AForm *(Intern::*ptr[3])(std::string _target) = 
	{
		&Intern::CreateShrubbery,
		&Intern::CreateRobotomy,
		&Intern::CreatePresidential
	};
	std::string str[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (str[i] == FormName)
		{
			std::cout << "the form was created\n";
			return (this->*ptr[i])(target);
		}
	}
	std::cout << "failed to create the form\n";
	return NULL;
}
