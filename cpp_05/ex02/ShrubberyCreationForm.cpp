/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:46:15 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/07 11:27:57 by nel-baz          ###   ########.fr       */
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

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ob) : AForm(ob) 
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