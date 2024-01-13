/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:03:13 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/13 10:52:38 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac == 2)
			ScalarConverter::convert(av[1]);
		else
			throw "error in number of argements";
	}
	catch(const char* e)
	{
		std::cerr << e << '\n';
	}
}