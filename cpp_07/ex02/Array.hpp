/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:12:42 by nel-baz           #+#    #+#             */
/*   Updated: 2024/01/17 17:25:55 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
private:
	T *array;
	unsigned int _size;
public:
	Array() : array(NULL), _size(0){
	}
	Array(unsigned int n) : _size(n){
		array = new T[n];
		for (unsigned int  i = 0; i < n; i++)
			array[i] = T();
	}
	Array(const Array& obj){
		array = NULL;
		*this = obj;
	}
	Array &operator=(const Array& obj){
		if (this == & obj)
			return (*this);
		if(this->array)
		{
			delete this->array;
			this->array = NULL;
		}
		array = new T[obj._size];
		for (unsigned int i = 0; i < obj._size; i++)
			this->array[i] = obj.array[i];
		this->_size = obj._size;
		return (*this);
	}
	~Array(){
		if (this->array)
			delete[] this->array;
	};
	T &operator[](unsigned int index){
		if (index >= _size)
			throw std::out_of_range("index out of range");
		return (array[index]);
	}
	const T &operator[](unsigned int index) const{
		if (index >= _size)
			throw std::out_of_range("index out of range");
		return (array[index]);
	}
	unsigned int size() const{
		return(_size);
	}
};

#endif