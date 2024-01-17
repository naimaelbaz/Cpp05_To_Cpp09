/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:38:09 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/17 16:14:55 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void print(char x)
{
	std::cout << x;
}

int main()
{
	try
	{
		/******** Simple function *********/
		int tab[] = {'n', 'a', 'i', 'm', 'a'};
		iter( tab, 5, print);
		std::cout << "\n";

		/******** Template function *********/
		iter( tab, 5, print2<char>);
		std::cout << "\n";
		
	}
	catch(const char* e)
	{
		std::cerr << e << '\n';
	}
	
	return 0;
}