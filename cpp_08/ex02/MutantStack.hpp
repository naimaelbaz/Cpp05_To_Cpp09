/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:41:49 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/24 13:45:54 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack(){}
	MutantStack(const MutantStack& obj) : std::stack<T, Container>(obj){
	}
	MutantStack& operator=(const MutantStack& obj){
		if(this == &obj)
			return(*this);
		std::stack<T, Container>::operator=(obj);
		return(*this);
	}
	~MutantStack(){}

	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	iterator begin()
	{
		return this->c.begin();
	}
	iterator end()
	{
		return this->c.end();
	}

	const_iterator begin() const
	{
		return this->c.begin();
	}
	const_iterator end() const
	{
		return this->c.end();
	}
};

#endif