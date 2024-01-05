/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:23:15 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/05 16:15:36 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

/*******************Orthodox_Canonical_Form********************/

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45) 
{
	this->setIsSigned(false);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ob) : AForm("Robotomy", 145, 137) 
{
	(void)ob;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &ob)
{
	if (this == &ob)
		return (*this);
	AForm::operator=(ob);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){}

/****************Func_of_grade*************************/

void RobotomyRequestForm::beSigned(const Bureaucrat& bur)
{
	if (this->getGradeToSign() < 1)
		throw GradeTooHighException();
	if (this->getGradeToExecute() > 150)
		throw GradeTooLowException();
	if (bur.getGrade() <= this->getGradeToExecute())
		this->setIsSigned(true);
}

void RobotomyRequestForm::signForm(const Bureaucrat& bur)
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