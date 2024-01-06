/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:25:52 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/06 15:03:40 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>

class Form;

class Bureaucrat
{
private:
	const	std::string _name;
	int		_grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& ob);
	Bureaucrat &operator=(const Bureaucrat& ob);
	~Bureaucrat();

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

	const	std::string getName() const;
	int		getGrade() const;
	void	incrementGrage();
	void	decrementGrage();
	void	signForm(Form& form);
};

std::ostream& operator<<(std::ostream& COUT, const Bureaucrat& ob1);

#endif