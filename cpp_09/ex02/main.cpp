/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:08:20 by nel-baz           #+#    #+#             */
/*   Updated: 2024/02/03 14:41:21 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char const **av)
{
	try
	{
		if (ac < 2)
			throw "No number was given!";
		PmergeMe obj;
		obj.SortRnage(av);
		obj.SortRnage(av, 0);
		std::vector<int> vec = obj.getMyVec();
		std::cout << "Before:\t";
		for (std::vector<int>::iterator i = vec.begin() ; i != vec.end(); i++)
			std::cout << *i << " ";
		std::vector<int> vec_sort = obj.getSortVector();
		std::cout << "\nAfter:\t";
		for (std::vector<int>::iterator i = vec_sort.begin() ; i != vec_sort.end(); i++)
			std::cout << *i << " ";
		std::cout <<"\n";
		std::cout << "Time to process a range of " << vec.size()
					<< " elements with std::vector : " << obj.duration_vec << " us\n";
		std::cout << "Time to process a range of " << vec.size()
					<< " elements with std::deque  : " << obj.duration_deq << " us\n";
	}
	catch(const char* e)
	{
		std::cout << e << '\n';
	}
	return 0;
}