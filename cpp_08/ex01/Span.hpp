/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:56:54 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/23 10:32:18 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
private:
	std::vector<int> MySpan;
	unsigned int _N;
public:
	Span();
	Span(unsigned int N);
	Span(const Span& obj);
	Span &operator=(const Span& obj);
	~Span();

	void addNumber(int number);
	int shortestSpan();
	int longestSpan();
	void addRangeOfNumbers(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end);
};



#endif