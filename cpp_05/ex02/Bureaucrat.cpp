/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:32:09 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/06 14:01:13 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/*******************Orthodox_Canonical_Form********************/

Bureaucrat::Bureaucrat() : _name("Default")
{
	_grade = 0;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& ob)
	: _name(ob._name), _grade(ob._grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ob)
{
	if (this == &ob)
		return *this;
	this->_grade = ob._grade;
	return *this;
}

Bureaucrat::~Bureaucrat(){}

/*****************geters_And_Seters****************************/

const std::string Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

/********************funct_of_grade****************************/

void Bureaucrat::incrementGrage()
{
	int i;
	i = _grade - 1;
	if (i < 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrage()
{
	int i;
	i = _grade + 1;
	if (i > 150)
		throw GradeTooLowException();
	_grade++;
}

void	Bureaucrat::executeForm(AForm const & form)
{
	if (form.getIsSigned() && this->_grade <= form.getGradeToExecute())
		std::cout << this->_name << " executed " << form.getName();
	else
		std::cout << this->_name << " filed to executed " << form.getName();
}
/*********************Operator**************************/

std::ostream& operator<<(std::ostream& COUT, const Bureaucrat& ob1)
{
	COUT << ob1.getName() << ", bureaucrat grade " << ob1.getGrade();
	return COUT;
}
