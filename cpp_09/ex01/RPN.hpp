/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:11:45 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/28 10:51:40 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <algorithm>

class RPN
{
private:
	std::stack<int> mystack;

	int	checkOperator(int first, int second, char oper);
public:
	RPN();
	RPN(const RPN& obj);
	RPN& operator=(const RPN& obj);
	~RPN();

	void CalculateRpnOperation(std::string str);
};


#endif