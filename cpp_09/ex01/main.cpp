/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:40:40 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/28 11:37:55 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char const *av[])
{
	try
	{
		if (ac == 2)
		{
			RPN obj;
			obj.CalculateRpnOperation(av[1]);
		}
		else
			throw "ERROR";
	}
	catch(const char* e)
	{
		std::cout << e << '\n';
	}
	return 0;
}

