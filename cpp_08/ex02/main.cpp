/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:48:41 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/24 13:51:01 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <vector>

int main()
{
	std::cout << "*******************First Exemple****************************\n";
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "the top of stack is: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "the size of stack is: " << mstack.size() << std::endl;
	std::cout << "Elements: "<<  std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it;;
	for (it = mstack.begin(); it != mstack.end(); it++)	
		std::cout << *it << "\n";

	std::cout << "****************Const Class******************\n";
	const MutantStack<int> constMutan = mstack;
	MutantStack<int>::const_iterator it_c;;
	for (it_c = constMutan.begin(); it_c != constMutan.end(); it_c++)	
		std::cout << *it_c << "\n";

	std::cout << "*******************Second Exemple****************************\n";
	MutantStack<std::string, std::vector<std::string> > StackOfStudent;
	StackOfStudent.push("naima");
	StackOfStudent.push("yasmine");
	StackOfStudent.push("samir");
	StackOfStudent.push("ali");
	StackOfStudent.push("ikram");
	StackOfStudent.push("khalid");
	std::cout << "the last student was added is: " << StackOfStudent.top() << "\n";
	std::cout << StackOfStudent.top() << " leaves the school \n";
	StackOfStudent.pop();
	StackOfStudent.push("khadija");
	std::cout << "add a new student: " << StackOfStudent.top() << "\n";
	std::cout << "the members of the class are:\n";
	MutantStack<std::string, std::vector<std::string> >::iterator it_s;
	for (it_s = StackOfStudent.begin(); it_s != StackOfStudent.end(); it_s++)
		std::cout << *it << "\n";
	return 0;
}