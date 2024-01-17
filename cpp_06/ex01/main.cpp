/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:44:48 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/14 14:48:01 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data ptr;

	ptr.a = 42;
	ptr.b = 13;
	ptr.c = 'n';
	uintptr_t var = Serializer::serialize(&ptr);
	std::cout << "the address of data is" <<reinterpret_cast<void*>(var)<<"\n";
	Data *data = Serializer::deserialize(var);
	std::cout << data->a << "\n";
	std::cout << data->b << "\n";
	std::cout << data->c << "\n";
}