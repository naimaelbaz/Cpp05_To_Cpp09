/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:27:23 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/15 10:46:58 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	/*************Valid Cast***********/
	Base *obj = generate();
	Base &obj1 = dynamic_cast<Base&>(*obj);
	identify(obj);
	identify(obj1);

	delete obj;
	/***********Invalid Cast************/
	Base c;
	Base c1;
	identify(&c);
	identify(c1);
}