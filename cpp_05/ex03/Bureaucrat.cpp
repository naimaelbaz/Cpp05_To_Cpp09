/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:32:09 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/06 17:09:45 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/*******************Orthodox_Canonical_Form********************/

Bureaucrat::Bureaucrat() : _name("Default")
{
	_grade = 150;
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
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrage()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name
				<< " signed " << form.getName() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << this->_name
			<< " couldn't sign " << form.getName()
			<< " because ";
		std::cerr << e.what() << '\n';
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() <<'\n';
	}
	catch(const std::exception& e)
	{
		std::cout << this->_name << " filed to executed " << form.getName() << " because ";
		std::cerr << e.what() << '\n';
	}
}
/*********************Operator**************************/

std::ostream& operator<<(std::ostream& COUT, const Bureaucrat& ob1)
{
	COUT << ob1.getName() << ", bureaucrat grade " << ob1.getGrade();
	return COUT;
}

/*********************Exceptions****************************/

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade of Bureaucrat is too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade of Bureaucrat is too Low";
}
