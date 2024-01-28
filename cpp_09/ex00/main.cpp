/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:43:38 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/27 15:34:02 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char const *av[])
{
	try
	{
		if (ac == 2)
		{
			BitcoinExchange bitc;
			bitc.saveDataInMap(av[1]);
		}
		else
			throw "Invalid number of argements";
	}
	catch(const char* e)
	{
		std::cerr << "Error: " << e << '\n';
	}
	return 0;
}
