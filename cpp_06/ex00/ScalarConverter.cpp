/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:08:33 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/15 10:38:59 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits>
#include <cstring>
#include <sstream>

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& ob)
{
	*this = ob;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& ob)
{
	(void)ob;
	return (*this);
}

ScalarConverter::~ScalarConverter(){}

static std::string to_lower(std::string str)
{
	std::string res;
	for (size_t i = 0; i < str.length(); i++)
		str[i] = tolower(str[i]);
	return(str);
}

void ScalarConverter::convertToInt(double Double, const std::string& toConvert)
{
	try
	{
		if (to_lower(toConvert) == "nan" || to_lower(toConvert) == "nanf")
			throw "int: Imposible";
		if (Double > INT_MAX || Double < INT_MIN)
			throw "int: Imposible";
		int Integer = static_cast<int>(Double);
		std::cout << "int: " <<Integer<<'\n';
	}
	catch(const char* e)
	{
		std::cerr << e << '\n';
	}
}

void ScalarConverter::convertToChar(double Double)
{
	try
	{
		char Character;
		int TmpInteger = static_cast<int>(Double);
		if (isprint(TmpInteger))
			Character = static_cast<char>(TmpInteger);
		else if ((TmpInteger >= 0 && TmpInteger < 32)
			|| (TmpInteger >= 127 && TmpInteger <= 255))
			throw "char: Non displayable";
		else
			throw "char: Impossible";
		std::cout << "char: '" << Character << "'\n";
	}
	catch(const char* e)
	{
		std::cerr << e << '\n';
	}
}

void ScalarConverter::convertToDoubleOrFloat(double Double, const std::string& toConvert)
{
	try
	{
		size_t p = toConvert.find('.');
		bool hasFractionalPart = ((p != std::string::npos) && toConvert[p + 1] != '\0');
		std::string str = toConvert.substr(p + 1);
		int setPrecision = hasFractionalPart ? str.length() : 1;
		if ((toConvert.find('f') != std::string::npos) && setPrecision != 1)
			setPrecision -= 1;
		std::cout << "float: " << std::fixed
		<< std::setprecision(setPrecision) << static_cast<float>(Double) << "f\n";
		std::cout << "double: " << std::fixed
		<< std::setprecision(setPrecision) << Double << "\n";
	}
	catch(const char* e)
	{
		std::cerr << e << '\n';
	}
}

void ScalarConverter::convert(const std::string& toConvert)
{
	try
	{
		if (toConvert.empty())
			throw "Impossible";
		ScalarConverter obj;
		double Double;
		char *pos = NULL;
		Double = strtod(toConvert.c_str(), &pos);
		if (isprint(toConvert[0]) && !isdigit(toConvert[0]) && toConvert[1] == '\0')
			Double = static_cast<double>(toConvert[0]);
		else if (!((pos[0] == 'f' && pos[1] == '\0') || pos[0] == '\0'))
			throw "Impossible";
		obj.convertToChar(Double);
		obj.convertToInt(Double, toConvert);
		obj.convertToDoubleOrFloat(Double, toConvert);
	}
	catch(const char* e)
	{
		std::cout << "int: " << e << '\n';
		std::cout << "char: " << e << '\n';
		std::cout << "float: " << e << '\n';
		std::cout << "double: " << e << '\n';
	}
}
