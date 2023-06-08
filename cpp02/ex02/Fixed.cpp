/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:31:25 by caboudar          #+#    #+#             */
/*   Updated: 2023/06/02 04:46:50 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed(): _value(0) {}

Fixed::Fixed(const int value) { _value = value << _fractionalBits; }

Fixed::Fixed(float value) { _value = (int)roundf(value * (1 << _fractionalBits)); }

Fixed::~Fixed() {}

Fixed::Fixed(Fixed const &cpy) { *this = cpy; }

Fixed &Fixed::operator=(Fixed const &rhs) {
	_value = rhs.getRawBits();
	return *this;
}

Fixed &Fixed::operator+(Fixed const &rhs) { 
	this->_value += rhs._value;
	return (*this);	
}

Fixed &Fixed::operator-(Fixed const &rhs) {
	this->_value -= rhs._value;
	return (*this);	
}

Fixed &Fixed::operator*(Fixed const &rhs) {
	this->_value = (this->toFloat() * rhs.toFloat() * (1 << this->_fractionalBits));
	return (*this);	
}

Fixed &Fixed::operator/(Fixed const &rhs) {
	this->_value /= rhs._value;
	return (*this);	
}

bool Fixed::operator>(Fixed const &rhs) { return this->_value > rhs._value; }
bool Fixed::operator>=(Fixed const &rhs) { return this->_value >= rhs._value; }
bool Fixed::operator<(Fixed const &rhs) { return this->_value < rhs._value; }
bool Fixed::operator<=(Fixed const &rhs) { return this->_value <= rhs._value; }
bool Fixed::operator==(Fixed const &rhs) { return this->_value == rhs._value; }
bool Fixed::operator!=(Fixed const &rhs) { return this->_value != rhs._value; }

Fixed &Fixed::operator++() {
	_value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	temp._value++;
	return *this;
}

Fixed &Fixed::operator--() {
	_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	temp._value--;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj) {
	os << obj.toFloat();
	return os;
}

void Fixed::setRawBits(const int raw) { this->_value = raw; }
int	Fixed::getRawBits() const { return this->_value; }


float Fixed::toFloat() const { return (_value / (double)(1 << _fractionalBits)); }
int Fixed::toInt() const { return _value >> _fractionalBits; }

Fixed &Fixed::min(Fixed &obj1, Fixed &obj2) { return obj1._value < obj2._value ? obj1 : obj2; }
Fixed &Fixed::max(Fixed &obj1, Fixed &obj2) { return obj1._value > obj2._value ? obj1 : obj2; }

const Fixed &Fixed::min(Fixed const &obj1, Fixed const &obj2) { return obj1._value < obj2._value ? obj1 : obj2; }
const Fixed &Fixed::max(Fixed const &obj1, Fixed const &obj2) { return obj1._value > obj2._value ? obj1 : obj2; }
