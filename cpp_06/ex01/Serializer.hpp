/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:34:53 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/14 14:47:52 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

struct Data;

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer& obj);
	Serializer &operator=(const Serializer& obj);
	~Serializer();
	
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

struct Data
{
	int a;
	int b;
	char c;
};


#endif