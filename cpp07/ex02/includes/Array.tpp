#pragma once
#include "Array.hpp"
#include <stdexcept>

template<typename T>
Array<T>::Array() : _array(new T[0]), _size(0) {}

template<typename T>
Array<T>::~Array() { delete[] this->_array; }

template<typename T>
Array<T>::Array(unsigned int size) : _array(new T[size]), _size(size) {}

template<typename T>
Array<T>::Array(const Array<T>& src) {
	this->_array = new T[src._size];
	this->_size = src._size;
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = src._array[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs) {
	this->_array = new T[rhs._size];
	this->_size = rhs._size;
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = rhs._array[i];
	return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= _size || index < 0) {
		throw OutOfRangeException();
	}
	return this->_array[index];
}

template<typename T>
unsigned int Array<T>::size() const { return _size; }

template<typename T>
const char* Array<T>::OutOfRangeException::what() const throw() {
	return "Array index out of range";
}