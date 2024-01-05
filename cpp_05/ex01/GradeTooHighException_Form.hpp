/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException_Form.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:31:17 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/05 11:56:07 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADETOOHighEXCEPTION_FORM_HPP
# define GRADETOOHighEXCEPTION_FORM_HPP

#include "Form.hpp"

class Form::GradeTooHighException : public std::exception
{
public:
	const	char *what() const throw();
};

#endif