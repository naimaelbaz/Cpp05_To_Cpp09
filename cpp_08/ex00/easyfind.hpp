/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:09:30 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/22 09:32:11 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>

template <typename T, int N>
int easyfind(T container)
{
	typename T::iterator it = std::find(container.begin(), container.end(), N);
	if (it == container.end())
		throw "is out of range!";
	return(*it);
}
#endif