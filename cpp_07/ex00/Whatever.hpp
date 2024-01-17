/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:46:20 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/17 14:35:07 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void	swap(T &first, T &second)
{
	T tmp;
	tmp = first;
	first = second;
	second = tmp;
}

template <typename T>
T	min(T first, T second)
{
	return (first < second ? first : second);
}


template <typename T>
T	max(T first, T second)
{
	return (first > second ? first : second);
}

#endif