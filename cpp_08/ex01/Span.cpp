/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:04:56 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/22 15:21:24 by nel-baz          ###   ########.fr       */
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
	if (MySpan.size() < _N)
		MySpan.push_back(number);
	else
		throw "No empty space!!";
}

int Span::shortestSpan() const
{
	
	return 0;
}

int Span::longestSpan() const
{
	return 0;
}
