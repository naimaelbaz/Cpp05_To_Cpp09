/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:02:08 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/17 16:14:09 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename TA, typename TF>
void iter(TA *add, unsigned int length, TF func)
{
	if (!add || !func)
		throw "Error";
	for (unsigned int i = 0; i < length; i++)
		func(add[i]);
}

template <typename T>
void print2(T arg)
{
	std::cout << arg;
}
#endif