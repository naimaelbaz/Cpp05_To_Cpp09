/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:31:17 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/04 17:55:52 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADETOOHighEXCEPTION_HPP
# define GRADETOOHighEXCEPTION_HPP

#include "Bureaucrat.hpp"

class Bureaucrat::GradeTooHighException : public std::exception
{
public:
	const	char *what() const throw();
};

#endif