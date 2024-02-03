/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:01:31 by nel-baz           #+#    #+#             */
/*   Updated: 2024/02/03 14:39:59 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <deque>
#include <ctime>

class PmergeMe
{
private:
	typedef std::vector<int> Vec;
	Vec myVec;
	Vec main;
	Vec pend;

	typedef std::deque<int> Deq;
	Deq myDeq;
	Deq main_d;
	Deq pend_d;


	void	PendAndMain(void);
	void	mergeSort(Vec& main, Vec& pend);
	void	sortOneRnge(Vec& first_m, Vec& second_m, Vec& first_p, Vec& second_p, Vec& main, Vec& pend);
	void	InsertPendInMain(void);
	std::vector<int> JacobsthalNumbers(size_t size);
	void	insertElementInMain(int element, int size);

	void	PendAndMain(int);
	void	mergeSort(Deq& main, Deq& pend);
	void	sortOneRnge(Deq& first_m, Deq& second_m, Deq& first_p, Deq& second_p, Deq& main, Deq& pend);
	void	InsertPendInMain(int);
	std::deque<int>	JacobsthalNumbers(size_t size, int);
	void	insertElementInMain(int element, int size, int);
public:
	PmergeMe();
	PmergeMe(const PmergeMe& obj);
	PmergeMe &operator=(const PmergeMe& obj);
	~PmergeMe();

	void SortRnage(char const **seqInt);
	void SortRnage(char const **seqInt, int);
	std::vector<int> getMyVec();
	std::vector<int> getSortVector();
	double duration_vec;
	double duration_deq;
};

#endif