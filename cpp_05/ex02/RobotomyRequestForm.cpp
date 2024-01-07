/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:23:15 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/07 11:30:39 by nel-baz          ###   ########.fr       */
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

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ob) : AForm(ob)
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

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() && executor.getGrade() <= this->getGradeToExecute())
	{
		int	randValue;
		std::srand(std::time(0));
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