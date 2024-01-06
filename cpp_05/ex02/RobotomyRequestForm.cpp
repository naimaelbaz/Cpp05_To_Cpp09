/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:23:15 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/06 13:44:40 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

/*******************Orthodox_Canonical_Form********************/

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45) 
{
	this->target = "Default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45) 
{
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ob) : AForm("Robotomy", 145, 137) 
{
	this->target = ob.target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &ob)
{
	if (this == &ob)
		return (*this);
	this->target = ob.target;
	AForm::operator=(ob);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){}

/****************Func_of_grade*************************/

void RobotomyRequestForm::beSigned(const Bureaucrat& bur)
{
	if (this->getGradeToSign() < 1)
		throw GradeTooHighException();
	if (bur.getGrade() <= this->getGradeToExecute())
		this->setIsSigned(true);
	else
		throw GradeTooLowException();
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

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() && executor.getGrade() <= this->getGradeToExecute())
	{
		int	randValue;

		randValue =  rand() % 2;
		std::cout << this->target << " Makes some drilling noises...\n";
		if (randValue)
			std::cout << this->target << " successful!\n";
		else
			std::cout << this->target << " failed.\n";
	}
	else
		throw GradeTooLowException();
}