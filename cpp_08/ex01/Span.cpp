/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:04:56 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/24 11:51:29 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0)
{
}

Span::Span(unsigned int N) : _N(N)
{
}

Span::Span(const Span &obj)
{
	*this = obj;
}

Span &Span::operator=(const Span &obj)
{
	if (this == &obj)
		return (*this);
	this->MySpan.assign(obj.MySpan.size(), 0);
	std::copy(obj.MySpan.begin(),
		obj.MySpan.end(), this->MySpan.begin());
	return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if (MySpan.size() == _N)
		throw "No empty space!!";
	MySpan.push_back(number);
}

int Span::shortestSpan()
{
	if (MySpan.size() < 2)
		throw "No span can be found!!";
	int shortest = INT_MAX;
	std::vector<int>::iterator nextIt;
	std::vector<int> tmpSpan = MySpan;
	sort(tmpSpan.begin(), tmpSpan.end());
	for (std::vector<int>::iterator it = tmpSpan.begin(); it != tmpSpan.end(); it++)
	{
		nextIt = it + 1;
		if (nextIt != tmpSpan.end())
		{
			if (abs(*it - *nextIt) < shortest)
				shortest = abs(*it - *nextIt);
		}
	}
	return shortest;
}


int Span::longestSpan()
{
	if (MySpan.size() < 2)
		throw "No span can be found!!";
	int _min = *std::minmax_element(MySpan.begin(), MySpan.end()).first;
	int _max = *std::minmax_element(MySpan.begin(), MySpan.end()).second;
	return (_max - _min);
}

void Span::addRangeOfNumbers(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end)
{
	MySpan.insert(MySpan.begin(), begin, end);
}
