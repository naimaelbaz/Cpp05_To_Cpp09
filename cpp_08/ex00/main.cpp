/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:27:44 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/22 09:32:52 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	try
	{
		std::vector<int> myVec;
		for (int i = 0; i < 5; i++)
			myVec.push_back(i + 1);
		std::cout <<"The elemnte "<< easyfind<std::vector<int>, 6>(myVec) << " is in the vector"<< "\n";
	}
	catch(const char* e)
	{
		std::cerr << e << '\n';
	}

	try
	{
		std::vector<int> myVec;
		for (int i = 0; i < 5; i++)
			myVec.push_back(i + 1);
		std::cout <<"The elemnte "<< easyfind<std::vector<int>, 1>(myVec) << " is in the vector"<< "\n";
	}
	catch(const char* e)
	{
		std::cerr << e << '\n';
	}
}