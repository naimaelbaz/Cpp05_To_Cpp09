/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:45:26 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/05 11:52:42 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
	const	std::string _name;
	bool	_isSigned;
	const	int _gradeToSign;
	const	int _gradeToExecute;
public:
	Form();
	Form(const std::string name, const int gToSign, const int gToExec);
	Form(const Form& ob);
	Form	&operator=(const Form& ob);
	~Form();
	
	class	GradeTooLowException;
	class	GradeTooHighException;
	const	std::string getName() const;
	int		getGradeToSign() const;
	int		getGradeToExecute() const;
	void	beSigned(const Bureaucrat& bur);
	void	signForm(const Bureaucrat& bur);
};

std::ostream& operator<<(std::ostream& COUT, const Form& ob);

#endif