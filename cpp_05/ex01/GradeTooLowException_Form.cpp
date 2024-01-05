/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException_Form.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:57:42 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/05 11:56:41 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GradeTooLowException_Form.hpp"

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade of form is too Low";
}