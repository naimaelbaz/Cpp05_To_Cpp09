/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:53:18 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/28 11:25:40 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	*this = obj;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if (this == &obj)
		return (*this);
	this->_data.erase(this->_data.begin(), this->_data.end());
	this->_data.insert(obj._data.begin(), obj._data.end());
	this->dataFile.erase(this->_data.begin(), this->_data.end());
	this->dataFile.insert(obj._data.begin(), obj._data.end());
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::checkForSpecialChar(const std::string &str)
{
	if (std::count(str.begin(), str.end(), ' ') != 2
		|| str.find('\t') != std::string::npos || std::count(str.begin(),
			str.end(), '|') != 1)
		return (false);
	return (true);
}

std::vector<std::string> BitcoinExchange::splitString(const std::string &str,
		char del)
{
	std::vector<std::string> tmpVec;
	std::string token;
	std::istringstream StrStream(str);
	while (std::getline(StrStream, token, del))
		tmpVec.push_back(token);
	return (tmpVec);
}

void BitcoinExchange::checkForDate(std::string year, std::string month,
		std::string day)
{
	int	num_y;
	int	num_m;
	int	num_d;

	num_y = std::atoi(year.c_str());
	if (num_y < 2009)
		throw ErrorHandling(" the year " + year + " is out of my data");
	num_m = std::atoi(month.c_str());
	if (num_m < 1 || num_m > 12)
		throw ErrorHandling(month + " is invalid month");
	num_d = std::atoi(day.c_str());
	if (num_d < 1 || num_d > 31)
		throw ErrorHandling(day + " is invalid day in the month");
	if ((num_m == 4 || num_m == 6 || num_m == 9 || num_m == 11) && num_d == 31)
		throw ErrorHandling(day + " is invalid day in the month" + month);
	if ((num_y % 400 == 0 || num_y % 4 == 0) && num_m == 2 && num_d > 29)
		throw ErrorHandling(day + " is invalid day in the month" + month);
	else if (!(num_y % 4 == 0) && num_m == 2 && num_d > 28)
		throw ErrorHandling(day + " is invalid day in the month" + month);
}

void BitcoinExchange::checkErrorInKey(myMap::iterator it)
{
	char	*pos;
	double	num;

	std::vector<std::string> tmpVec;
	std::string tab[3];
	std::string tmpStr;
	if (std::count(it->first.begin(), it->first.end(), '-') != 2
		|| it->first.empty())
		throw ErrorHandling(" bad input in date => " + it->first);
	tmpStr = it->first;
	if (tmpStr[tmpStr.size() - 1] == ' ')
		tmpStr = tmpStr.substr(0, tmpStr.size() - 1);
	tmpVec = splitString(tmpStr, '-');
	for (int i = 0; i < 3; i++)
	{
		num = strtof(tmpVec[i].c_str(), &pos);
		if (tmpVec[i].empty() || tmpVec[i].find(' ') != std::string::npos
			|| strcmp(pos, ""))
		throw ErrorHandling(" bad input in date => " + it->first);
		tab[i] = tmpVec[i];
		(void)num;
	}
	if (tab[1].size() != 2 || tab[2].size() != 2)
		throw ErrorHandling(" bad input in date => " + it->first);
	this->checkForDate(tab[0], tab[1], tab[2]);
}

float BitcoinExchange::checkErrorInValue(myMap::iterator it)
{
	char	*pos;
	double	num;

	std::string tmpStr;
	tmpStr = it->second;
	if (tmpStr[0] == ' ')
		tmpStr = tmpStr.substr(1, tmpStr.size());
	num = strtod(tmpStr.c_str(), &pos);
	if (tmpStr.empty() || tmpStr.find(' ') != std::string::npos || strcmp(pos,
			""))
		throw ErrorHandling(" bad input in value => " + it->second);
	if (num < 0)
		throw ErrorHandling(it->second + " is not a positive number!");
	if (num > 1000)
		throw ErrorHandling(it->second + " is too large number");
	return (num);
}

void BitcoinExchange::saveDataInMap(const std::string &fileName)
{
	char	*pos;
	float	num;
	float	num2;

	std::string str;
	std::string key;
	std::string value;
	std::ifstream myfile(fileName);
	if (myfile.is_open())
	{
		while (std::getline(myfile, str))
		{
			if (!strcmp(str.c_str(), "date | value"))
				continue ;
			try
			{
				if (!this->checkForSpecialChar(str))
					throw ErrorHandling(" bad input => " + str);
				key = std::strtok(const_cast<char *>(str.c_str()), "|");
				value = std::strtok(NULL, "|");
				_data[key] = value;
				myMap::iterator it = _data.find(key);
				this->checkErrorInKey(it);
				num = this->checkErrorInValue(it);
				this->OpenDataFile();
				myMap::iterator it_f = dataFile.find(key);
				if (it_f == dataFile.end())
				{
					it_f = dataFile.lower_bound(key);
					if (it_f != dataFile.begin())
						it_f--;
					if (it_f == dataFile.end())
					throw ErrorHandling(" bad input => " + str);
					num2 = std::strtod(it_f->second.c_str(), &pos);
					std::cout << it->first << "=> " << num
								<< " = " << num * num2 << "\n";
				}
			}
			catch(const std::exception& e)
			{
				std::cerr << "Error:" << e.what() << '\n';
			}
		}
		
	}
	else
		throw "Unable to open file";
	myfile.close();
}

void BitcoinExchange::OpenDataFile()
{
	std::string str;
	std::ifstream datafile("data.csv");
	std::string key;
	std::string value;
	if (datafile.is_open())
	{
		while (std::getline(datafile, str))
		{
			if (!strcmp(str.c_str(), "date,exchange_rate"))
				continue ;
			key = std::strtok(const_cast<char *>(str.c_str()), ",");
			value = std::strtok(NULL, ",");
			this->dataFile[key] = value;
		}
	}
	else
		throw "Unable to read from Data file";
	datafile.close();
}

BitcoinExchange::ErrorHandling::ErrorHandling(std::string msg)
	: msgError(msg){}

const char *BitcoinExchange::ErrorHandling::what() const throw()
{
	return (msgError.c_str());
}

BitcoinExchange::ErrorHandling::~ErrorHandling() throw(){}
