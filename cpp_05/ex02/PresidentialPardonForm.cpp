/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:27:20 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/06 13:47:50 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

/*******************Orthodox_Canonical_Form********************/

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5) 
{
	this->target = "Default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential", 25, 5) 
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ob) : AForm("Presidential", 25, 5) 
{
	this->target = ob.target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ob)
{
	if (this == &ob)
		return (*this);
	this->target = ob.target;
	AForm::operator=(ob);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){}

/****************Func_of_grade*************************/

void PresidentialPardonForm::beSigned(const Bureaucrat& bur)
{
	if (this->getGradeToSign() < 1)
		throw GradeTooHighException();
	if (bur.getGrade() <= this->getGradeToExecute())
		this->setIsSigned(true);
	else
		throw GradeTooLowException();
}

void PresidentialPardonForm::signForm(const Bureaucrat& bur)
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


void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() && executor.getGrade() <= this->getGradeToExecute())
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox\n";
	else
		throw GradeTooLowException();
}