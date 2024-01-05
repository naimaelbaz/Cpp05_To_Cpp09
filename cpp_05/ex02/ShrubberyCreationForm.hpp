/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:38:05 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/05 16:00:17 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& ob);
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm& ob);
	~ShrubberyCreationForm();
	

	
	void beSigned(const Bureaucrat& bur);
	void signForm(const Bureaucrat& bur);
	void AsciiTree(std::string target);
};

#endif
