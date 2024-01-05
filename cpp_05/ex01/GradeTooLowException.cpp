/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:57:42 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/05 11:57:44 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GradeTooLowException.hpp"

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade of Bureaucrat is too Low";
}