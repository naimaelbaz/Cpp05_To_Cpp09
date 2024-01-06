/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:20:42 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/06 13:39:40 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& ob);
	RobotomyRequestForm	&operator=(const RobotomyRequestForm& ob);
	~RobotomyRequestForm();
	

	
	void beSigned(const Bureaucrat& bur);
	void signForm(const Bureaucrat& bur);
	void execute(Bureaucrat const & executor) const;
};

#endif
