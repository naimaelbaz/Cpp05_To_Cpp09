/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:13:59 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/06 17:56:35 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern& ob);
	Intern &operator=(const Intern& ob);
	~Intern();

	AForm *makeForm(std::string FormName, std::string target);
	void printMsg(std::string msg);
};

#endif