/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:46:15 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/06 13:41:12 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

/*******************Orthodox_Canonical_Form********************/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137) 
{
	this->target = "Default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137) 
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ob) : AForm("Shrubbery", 145, 137) 
{
	this->target = ob.target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ob)
{
	if (this == &ob)
		return (*this);
	this->target = ob.target;
	AForm::operator=(ob);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

/****************Func_of_grade*************************/

void ShrubberyCreationForm::beSigned(const Bureaucrat& bur)
{
	if (this->getGradeToSign() < 1)
		throw GradeTooHighException();
	if (bur.getGrade() <= this->getGradeToExecute())
		this->setIsSigned(true);
	else
		throw GradeTooLowException();
		
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

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (this->getIsSigned() && executor.getGrade() <= this->getGradeToExecute())
	{
		std::string file = this->target + "_shrubbery";
		std::ofstream myFile;
		myFile.open(file);
		if (!myFile.good())
			throw "Failed to open file " + file;
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
	else
		throw GradeTooLowException();
}