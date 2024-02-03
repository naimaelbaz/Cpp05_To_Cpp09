/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:35:37 by nel-baz           #+#    #+#             */
/*   Updated: 2024/02/03 19:11:22 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>


class BitcoinExchange
{
private:
	typedef std::map<std::string, std::string> myMap;
	typedef std::map<size_t, std::string> myMap_data;
	myMap _data;
	myMap_data dataFile;

	bool	checkForSpecialChar(const std::string& str);
	void	checkErrorInKey(myMap::iterator it);
	float	checkErrorInValue(myMap::iterator it);
	std::vector<std::string> splitString(const std::string& str, char del);
	void	checkForDate(std::string year, std::string month, std::string day);
	void	OpenDataFile();
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& obj);
	BitcoinExchange& operator=(const BitcoinExchange& obj);
	~BitcoinExchange();
	void saveDataInMap(const std::string& fileName);

	class ErrorHandling : public std::exception
	{
		private:
			std::string msgError;
		public:
			ErrorHandling(std::string msg);
			const char* what() const throw();
			~ErrorHandling() throw();
	};
};

#endif
