/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:13:59 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/07 12:05:33 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
private:
	AForm *CreateShrubbery(std::string target);
	AForm *CreateRobotomy(std::string target);
	AForm *CreatePresidential(std::string target);
public:
	Intern();
	Intern(const Intern& ob);
	Intern &operator=(const Intern& ob);
	~Intern();

	AForm *makeForm(std::string FormName, std::string target);
};

#endif