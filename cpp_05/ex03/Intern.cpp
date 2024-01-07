/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:29:13 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/06 20:43:34 by nel-baz          ###   ########.fr       */
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

void Intern::printMsg(std::string msg)
{
	std::cout << msg << '\n';
}

AForm *Intern::makeForm(std::string FormName, std::string target)
{
	AForm *ob = NULL;

	ob = (FormName == "Shrubbery creation" ? new ShrubberyCreationForm(target) : ob);
	ob = (FormName == "Robotomy request" ? new RobotomyRequestForm(target) : ob);
	ob = (FormName == "Presidential pardon" ? new PresidentialPardonForm(target) : ob);
	ob == NULL ? this->printMsg("Intern failed to create " + FormName)
				: this->printMsg("Intern creates " + FormName);
	return(ob);
}
