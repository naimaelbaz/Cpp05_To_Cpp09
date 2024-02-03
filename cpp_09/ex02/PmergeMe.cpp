#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	*this = obj;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
	if (this == &obj)
		return(*this);
	std::copy(obj.myVec.begin(),
		obj.myVec.end(), this->myVec.begin());
	std::copy(obj.myDeq.begin(),
		obj.myDeq.end(), this->myDeq.begin());
	return(*this);
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::sortOneRnge(Vec& first_m, Vec& second_m, Vec& first_p, Vec& second_p, Vec& main, Vec& pend)
{
	std::vector<int>::iterator it_Fm = first_m.begin();
	std::vector<int>::iterator it_Sm = second_m.begin();
	std::vector<int>::iterator it_Fp = first_p.begin();
	std::vector<int>::iterator it_Sp = second_p.begin();
	int i = 0;
	while (it_Fm != first_m.end() && it_Sm != second_m.end())
	{
		if (*it_Fm < *it_Sm)
		{
			main[i] = *it_Fm;
			pend[i++] = *it_Fp;
			it_Fp++;
			it_Fm++;
		}
		else
		{
			main[i] = *it_Sm;
			pend[i++] = *it_Sp;
			it_Sp++;
			it_Sm++;
		}
	}
	while (it_Fm != first_m.end())
	{
		main[i] = *it_Fm;
		pend[i++] = *it_Fp;
		it_Fp++;
		it_Fm++;
	}
	while (it_Sm != second_m.end())
	{
		main[i] = *it_Sm;
		pend[i++] = *it_Sp;
		it_Sp++;
		it_Sm++;
	}
}

void PmergeMe::mergeSort(Vec& main, Vec& pend)
{
	if (main.size() <= 1)
		return ;
	std::vector<int> first_m(main.size() / 2);
	std::vector<int> second_m(main.size() - (main.size() / 2));
	std::vector<int> first_p(main.size() / 2);
	std::vector<int> second_p(main.size() - (main.size() / 2));
	for (size_t i = 0; i < first_m.size(); i++)
		first_m[i] = main[i];
	for (size_t i = first_m.size(); i < main.size(); i++)
		second_m[i - first_m.size()] = main[i];
	for (size_t i = 0; i < first_p.size(); i++)
		first_p[i] = pend[i];
	for (size_t i = first_p.size(); i < pend.size(); i++)
		second_p[i - first_p.size()] = pend[i];
	mergeSort(first_m, first_p);
	mergeSort(second_m, second_p);
	sortOneRnge(first_m, second_m, first_p, second_p, main, pend);
}

void PmergeMe::PendAndMain(void)
{
	for (std::vector<int>::iterator it = myVec.begin(); it != myVec.end(); it++)
	{
		if (it + 1 != myVec.end() && *it > *(it + 1))
		{
			main.push_back(*it);
			pend.push_back(*(it + 1));
			it++;
		}
		else if (it + 1 != myVec.end() && *it < *(it + 1))
		{
			main.push_back(*(it + 1));
			pend.push_back(*it);
			it++;
		}
		else
			pend.push_back(*it);
	}
	mergeSort(main, pend);
}

std::vector<int> PmergeMe::JacobsthalNumbers(size_t size)
{
	std::vector<int> jacobsthal;

	for (size_t i = 0 ; i <= size; i++)
	{
		int j = (std::pow(2, i + 2) - std::pow(-1, i + 2)) / 3;
		jacobsthal.push_back(j);
	}
	return (jacobsthal);
}

void PmergeMe::insertElementInMain(int element, int size)
{
	int i = 0;
	for (std::vector<int>::iterator it = main.begin(); it != main.end() && i <= size; it++)
	{
		if (element < *it)
		{
			main.insert(it, element);
			return;
		}
		i++;
	}
	main.push_back(element);
}

void PmergeMe::InsertPendInMain(void)
{
	std::vector<int> tmp = main;
	std::vector<int> jacobsthal;
	jacobsthal = this->JacobsthalNumbers(pend.size());
	main.insert(main.begin(), *pend.begin());
	size_t prevJac = 1;
	size_t i;
	for (i = 1 ; i < pend.size(); i++)
	{
		size_t jac = i + 1;
		size_t prevJac_Tmp = jac;
		std::vector<int>::iterator it = std::find(jacobsthal.begin(), jacobsthal.end(), jac);
		if (it != jacobsthal.end())
		{
			prevJac_Tmp = jac;
			while (jac > prevJac)
			{
				insertElementInMain(*(pend.begin() + (jac - 1)), prevJac + prevJac_Tmp - 1);
				jac--;
			}
			prevJac = prevJac_Tmp;
		}
		std::vector<int>::iterator it_s = std::find(jacobsthal.begin(), jacobsthal.end(), prevJac);
		if ((it_s + 1) != jacobsthal.end() && static_cast<size_t>(*(it_s + 1)) > pend.size())
		{
			jac = pend.size();
			prevJac_Tmp = jac;
			while (jac > prevJac)
			{
				insertElementInMain(*(pend.begin() + (jac- 1)), prevJac + prevJac_Tmp - 1);
				jac--;
			}
			break ;
		}
	}
}

void PmergeMe::SortRnage(char const **seqInt)
{
	int i = 1;
	try
	{
		clock_t start_time_v = clock();
		while (seqInt[i])
		{
			std::string tmpStr = seqInt[i];
			if (tmpStr.find_first_not_of("0123456789") != std::string::npos || tmpStr.empty())
				throw std::invalid_argument("Error: Invalid number in the given sequence!");
			int num = atoi(seqInt[i]);
			if (num < 0)
				throw std::invalid_argument("Error: Number greater than max int!");
			if (std::find(myVec.begin(), myVec.end(), num) != myVec.end())
				throw std::invalid_argument("Error: Duplicate number in sequence!");
			this->myVec.push_back(atoi(seqInt[i]));
			i++;
		}
		this->PendAndMain();
		this->InsertPendInMain();
		clock_t end_time_v = clock();
		this->duration_vec = (static_cast<double>(end_time_v - start_time_v) / CLOCKS_PER_SEC) * 1e6;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}


std::vector<int> PmergeMe::getMyVec()
{
	return(myVec);
}

std::vector<int> PmergeMe::getSortVector()
{
	return(main);
}

/************************** ---Deque--- *********************************/


void PmergeMe::sortOneRnge(Deq& first_m, Deq& second_m, Deq& first_p, Deq& second_p, Deq& main, Deq& pend)
{
	Deq::iterator it_Fm = first_m.begin();
	Deq::iterator it_Sm = second_m.begin();
	Deq::iterator it_Fp = first_p.begin();
	Deq::iterator it_Sp = second_p.begin();
	int i = 0;
	while (it_Fm != first_m.end() && it_Sm != second_m.end())
	{
		if (*it_Fm < *it_Sm)
		{
			main[i] = *it_Fm;
			pend[i++] = *it_Fp;
			it_Fp++;
			it_Fm++;
		}
		else
		{
			main[i] = *it_Sm;
			pend[i++] = *it_Sp;
			it_Sp++;
			it_Sm++;
		}
	}
	while (it_Fm != first_m.end())
	{
		main[i] = *it_Fm;
		pend[i++] = *it_Fp;
		it_Fp++;
		it_Fm++;
	}
	while (it_Sm != second_m.end())
	{
		main[i] = *it_Sm;
		pend[i++] = *it_Sp;
		it_Sp++;
		it_Sm++;
	}
}

void PmergeMe::mergeSort(Deq& main_d, Deq& pend_d)
{
	if (main_d.size() <= 1)
		return ;
	Deq first_m(main_d.size() / 2);
	Deq second_m(main_d.size() - (main_d.size() / 2));
	Deq first_p(main_d.size() / 2);
	Deq second_p(main_d.size() - (main_d.size() / 2));
	for (size_t i = 0; i < first_m.size(); i++)
		first_m[i] = main_d[i];
	for (size_t i = first_m.size(); i < main_d.size(); i++)
		second_m[i - first_m.size()] = main_d[i];
	for (size_t i = 0; i < first_p.size(); i++)
		first_p[i] = pend_d[i];
	for (size_t i = first_p.size(); i < pend_d.size(); i++)
		second_p[i - first_p.size()] = pend_d[i];
	mergeSort(first_m, first_p);
	mergeSort(second_m, second_p);
	sortOneRnge(first_m, second_m, first_p, second_p, main_d, pend_d);
}

void PmergeMe::PendAndMain(int)
{
	for (Deq::iterator it = myDeq.begin(); it != myDeq.end(); it++)
	{
		if (it + 1 != myDeq.end() && *it > *(it + 1))
		{
			main_d.push_back(*it);
			pend_d.push_back(*(it + 1));
			it++;
		}
		else if (it + 1 != myDeq.end() && *it < *(it + 1))
		{
			main_d.push_back(*(it + 1));
			pend_d.push_back(*it);
			it++;
		}
		else
			pend_d.push_back(*it);
	}
	mergeSort(main_d, pend_d);
}

std::deque<int> PmergeMe::JacobsthalNumbers(size_t size, int)
{
	Deq jacobsthal;

	for (size_t i = 0 ; i <= size; i++)
	{
		int j = (std::pow(2, i + 2) - std::pow(-1, i + 2)) / 3;
		jacobsthal.push_back(j);
	}
	return (jacobsthal);
}

void PmergeMe::insertElementInMain(int element, int size, int)
{
	int i = 0;
	for (Deq::iterator it = main_d.begin(); it != main_d.end() && i <= size; it++)
	{
		if (element < *it)
		{
			main_d.insert(it, element);
			return;
		}
		i++;
	}
	main_d.push_back(element);
}

void PmergeMe::InsertPendInMain(int)
{
	Deq tmp = main_d;
	Deq jacobsthal;
	jacobsthal = this->JacobsthalNumbers(pend_d.size(), 0);
	main_d.insert(main_d.begin(), *pend_d.begin());
	size_t prevJac = 1;
	size_t i;
	for (i = 1 ; i < pend_d.size(); i++)
	{
		size_t jac = i + 1;
		size_t prevJac_Tmp = jac;
		Deq::iterator it = std::find(jacobsthal.begin(), jacobsthal.end(), jac);
		if (it != jacobsthal.end())
		{
			prevJac_Tmp = jac;
			while (jac > prevJac)
			{
				insertElementInMain(*(pend_d.begin() + (jac - 1)), prevJac + prevJac_Tmp - 1, 0);
				jac--;
			}
			prevJac = prevJac_Tmp;
		}
		Deq::iterator it_s = std::find(jacobsthal.begin(), jacobsthal.end(), prevJac);
		if ((it_s + 1) != jacobsthal.end() && static_cast<size_t>(*(it_s + 1)) > pend_d.size())
		{
			jac = pend_d.size();
			prevJac_Tmp = jac;
			while (jac > prevJac)
			{
				insertElementInMain(*(pend_d.begin() + (jac- 1)), prevJac + prevJac_Tmp - 1, 0);
				jac--;
			}
			break ;
		}
	}
}

void PmergeMe::SortRnage(char const **seqInt, int)
{
	int i = 1;
	try
	{
		clock_t start_time_d = clock();
		while (seqInt[i])
		{
			std::string tmpStr = seqInt[i];
			if (tmpStr.find_first_not_of("0123456789") != std::string::npos || tmpStr.empty())
				throw std::invalid_argument("Error: Invalid number in the given sequence!");
			int num = atoi(seqInt[i]);
			if (num < 0)
				throw std::invalid_argument("Error: Number greater than max int!");
			if (std::find(myDeq.begin(), myDeq.end(), num) != myDeq.end())
				throw std::invalid_argument("Error: Duplicate number in sequence!");
			this->myDeq.push_back(atoi(seqInt[i]));
			i++;
		}
		this->PendAndMain(0);
		this->InsertPendInMain(0);
		clock_t end_time_d = clock();
		duration_deq = (static_cast<double>(end_time_d - start_time_d) / CLOCKS_PER_SEC) * 1e6;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}
