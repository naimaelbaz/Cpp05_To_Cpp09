/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:25:52 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/04 18:33:46 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>

class Bureaucrat
{
private:
	const	std::string _name;
	int		_grade;
public:
	Bureaucrat(std::string name, int grade);
	class	GradeTooHighException;
	class	GradeTooLowException;
	const	std::string getName() const;
	int		getGrade() const;
	void	incrementGrage();
	void	decrementGrage();
};

std::ostream& operator<<(std::ostream& COUT, const Bureaucrat& ob1);

#endif