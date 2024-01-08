/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:45:26 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/07 12:11:08 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
private:
	const	std::string _name;
	bool	_isSigned;
	const	int _gradeToSign;
	const	int _gradeToExecute;
public:
	AForm();
	AForm(const std::string name, const int gToSign, const int gToExec);
	AForm(const AForm& ob);
	AForm	&operator=(const AForm& ob);
	virtual	~AForm();
	
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	const			std::string getName() const;
	int				getGradeToSign() const;
	int				getGradeToExecute() const;
	bool			getIsSigned() const;
	void			setIsSigned(bool val);
	void			beSigned(const Bureaucrat& bur);
	virtual void	execute(Bureaucrat const & executor) const = 0;
	
};

std::ostream& operator<<(std::ostream& COUT, const AForm& ob);

#endif