/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:19:42 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/06 13:37:44 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/*******************Orthodox_Canonical_Form********************/

Form::Form()
	: _name("Default"), _gradeToSign(0), _gradeToExecute(0)
{
	_isSigned = false;
}

Form::Form(const std::string name, const int gToSigne, const int gToExec)
	: _name(name), _gradeToSign(gToSigne), _gradeToExecute(gToExec)
{
	_isSigned = false;
	if (gToSigne < 1 || gToExec < 1)
		throw GradeTooHighException();
	if (gToSigne > 150 || gToExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &ob)
	: _name(ob._name), _gradeToSign(ob._gradeToSign),
		_gradeToExecute(ob._gradeToExecute)
{
	_isSigned = ob._isSigned;
}

Form &Form::operator=(const Form &ob)
{
	if (this == &ob)
		return (*this);
	this->_isSigned = ob._isSigned;
	return (*this);
}

Form::~Form(){}

/*****************geters_And_Seters****************************/

const std::string Form::getName() const
{
	return (_name);
}
int Form::getGradeToSign() const
{
	return(_gradeToSign);
}
int Form::getGradeToExecute() const
{
	return(_gradeToExecute);
}

/********************funct_of_grade****************************/

void Form::beSigned(const Bureaucrat& bur)
{
	if (this->_gradeToSign < 1)
		throw GradeTooHighException();
	if (bur.getGrade() <= this->_gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

void Form::signForm(const Bureaucrat& bur)
{
	this->beSigned(bur);
	if (_isSigned)
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

/*********************Operator**************************/

std::ostream& operator<<(std::ostream& COUT, const Form& ob1)
{
	COUT << ob1.getName() << ", Form's grade to be sign is "
		<< ob1.getGradeToSign() 
		<< ", and the Form's grade to be execute is "
		<< ob1.getGradeToExecute();
	return COUT;
}