/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:19:42 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/06 13:38:21 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/*******************Orthodox_Canonical_Form********************/

AForm::AForm()
	: _name("Default"), _gradeToSign(0), _gradeToExecute(0)
{
	_isSigned = false;
}

AForm::AForm(const std::string name, const int gToSigne, const int gToExec)
	: _name(name), _gradeToSign(gToSigne), _gradeToExecute(gToExec)
{
	_isSigned = false;
	if (gToSigne < 1 || gToExec < 1)
		throw GradeTooHighException();
	if (gToSigne > 150 || gToExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &ob)
	: _name(ob._name), _gradeToSign(ob._gradeToSign),
		_gradeToExecute(ob._gradeToExecute)
{
	_isSigned = ob._isSigned;
}

AForm &AForm::operator=(const AForm &ob)
{
	if (this == &ob)
		return (*this);
	this->_isSigned = ob._isSigned;
	return (*this);
}

AForm::~AForm(){}

/*****************geters_And_Seters****************************/

const std::string AForm::getName() const
{
	return (_name);
}
int AForm::getGradeToSign() const
{
	return(_gradeToSign);
}
int AForm::getGradeToExecute() const
{
	return(_gradeToExecute);
}
bool AForm::getIsSigned() const
{
	return (_isSigned);
}

void	AForm::setIsSigned(bool val)
{
	_isSigned = val;
}

/********************funct_of_grade****************************/

void AForm::beSigned(const Bureaucrat& bur)
{
	if (this->_gradeToSign < 1)
		throw GradeTooHighException();
	if (bur.getGrade() <= this->_gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

void AForm::signForm(const Bureaucrat& bur)
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

std::ostream& operator<<(std::ostream& COUT, const AForm& ob1)
{
	COUT << ob1.getName() << ", Form's grade to be sign is "
		<< ob1.getGradeToSign() 
		<< ", and the Form's grade to be execute is "
		<< ob1.getGradeToExecute();
	return COUT;
}