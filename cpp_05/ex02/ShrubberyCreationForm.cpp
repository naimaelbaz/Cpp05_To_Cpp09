/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:46:15 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/05 16:19:49 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

/*******************Orthodox_Canonical_Form********************/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137) 
{
	this->setIsSigned(false);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ob) : AForm("Shrubbery", 145, 137) 
{
	(void)ob;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ob)
{
	if (this == &ob)
		return (*this);
	AForm::operator=(ob);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

/****************Func_of_grade*************************/

void ShrubberyCreationForm::beSigned(const Bureaucrat& bur)
{
	if (this->getGradeToSign() < 1)
		throw GradeTooHighException();
	if (this->getGradeToExecute() > 150)
		throw GradeTooLowException();
	if (bur.getGrade() <= this->getGradeToExecute())
		this->setIsSigned(true);
}

void ShrubberyCreationForm::signForm(const Bureaucrat& bur)
{
	this->beSigned(bur);
	if (this->getIsSigned())
		std::cout << bur.getName()
				<< " signed " << this->getName() << '\n';
	else
		std::cout << bur.getName()
				<< " couldn't sign " << this->getName()
				<< " because grade of form to sign is "
				<< this->getGradeToSign()
				<< " and grade of Bureaucrat is "
				<< bur.getGrade() << '\n';
}

void ShrubberyCreationForm::AsciiTree(std::string target)
{
	target += "_shrubbery";
	std::ofstream myFile;
	myFile.open(target);
	myFile << "       _-_\n"
            << "    /~~   ~~\\\n"
            << " /~~         ~~\\\n"
            << "{               }\n"
            << " \\  _-     -_  /\n"
            << "   ~  \\\\ //  ~\n"
            << "_- -   | | _- _\n"
            << "  _ -  | |   -_\n"
            << "      // \\\\" << '\n';
	myFile.close();
}
