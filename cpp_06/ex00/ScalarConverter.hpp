/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:59:25 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/13 10:51:27 by nel-baz          ###   ########.fr       */
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

	void convertToInt(double Double, std::string toConvert);
	void convertToChar(double Double);
	void convertToDoubleOrFloat(double Double, std::string toConvert);
public:
	ScalarConverter &operator=(const ScalarConverter& ob);
	~ScalarConverter();

	static void convert(std::string toConvert);
};

#endif