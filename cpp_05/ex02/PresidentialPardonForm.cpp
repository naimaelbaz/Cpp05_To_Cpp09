/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:27:20 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/05 16:16:02 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

/*******************Orthodox_Canonical_Form********************/

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 145, 137) 
{
	this->setIsSigned(false);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ob) : AForm("Presidential", 145, 137) 
{
	(void)ob;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ob)
{
	if (this == &ob)
		return (*this);
	AForm::operator=(ob);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){}

/****************Func_of_grade*************************/

void PresidentialPardonForm::beSigned(const Bureaucrat& bur)
{
	if (this->getGradeToSign() < 1)
		throw GradeTooHighException();
	if (this->getGradeToExecute() > 150)
		throw GradeTooLowException();
	if (bur.getGrade() <= this->getGradeToExecute())
		this->setIsSigned(true);
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
