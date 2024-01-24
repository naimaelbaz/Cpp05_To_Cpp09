/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:38:10 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/24 11:04:20 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	try
	{
		Span sp(5);
		std::vector<int> myVec;
		for (int i = 0; i < 5; i++)
			myVec.push_back(i + 1);
		sp.addRangeOfNumbers(myVec.begin(), myVec.end());
	
		std::cout << " The shortest Span is: " << sp.shortestSpan() << std::endl;
		std::cout << " The longest Span is: "<< sp.longestSpan() << std::endl;
	}
	catch(const char* e)
	{
		std::cerr << e << '\n';
	}
	
}