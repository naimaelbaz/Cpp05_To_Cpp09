/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:59:25 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/15 10:45:26 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& ob);
	ScalarConverter &operator=(const ScalarConverter& ob);
	~ScalarConverter();

	void convertToInt(double Double, const std::string& toConvert);
	void convertToChar(double Double);
	void convertToDoubleOrFloat(double Double, const std::string& toConvert);
public:
	static void convert(const std::string& toConvert);
};

#endif