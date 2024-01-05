/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:26:02 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/05 15:35:18 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& ob);
	PresidentialPardonForm	&operator=(const PresidentialPardonForm& ob);
	~PresidentialPardonForm();
	

	
	void beSigned(const Bureaucrat& bur);
	void signForm(const Bureaucrat& bur);
};

#endif
