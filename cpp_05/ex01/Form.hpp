/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:45:26 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/05 09:12:52 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Form
{
private:
	const	std::string _name;
	bool	_isSigned;
	const	int _gradeToSign;
	const	int _gradeToExecute;
public:
	Form(std::string name, int gToSign, int gToExec);
	
	class	GradeTooLowException;
	class	GradeTooHighException;
	const	std::string getName() const;
	int		getGradeToSign() const;
	int		getGradeToExecute() const;
};


#endif