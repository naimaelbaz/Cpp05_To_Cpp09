/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException_Form.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:50:26 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/05 11:56:58 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADETOOLOWEXCEPTION_FORM_HPP
# define GRADETOOLOWEXCEPTION_FORM_HPP

#include "Form.hpp"

class Form::GradeTooLowException : public std::exception
{
public:
	const	char *what() const throw();
};

#endif