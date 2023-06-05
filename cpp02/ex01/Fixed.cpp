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

Fixed::Fixed(): _value(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const int value) {
	std::cout << "Int Constructor called" << std::endl;
	_value = value << _fractionalBits;
}

Fixed::Fixed(float value) {
	std::cout << "Float Constructor called" << std::endl;
	_value = (int)roundf(value * (1 << _fractionalBits));
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed::Fixed(Fixed const &cpy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed &Fixed::operator=(Fixed const &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	_value = rhs.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj) {
	os << obj.toFloat();
	return os;
}

void Fixed::setRawBits(const int raw) { this->_value = raw; }

int	Fixed::getRawBits() const { return this->_value; }

float Fixed::toFloat() const {
	return (_value / (double)(1 << _fractionalBits));
}

int Fixed::toInt() const {
	return (_value >> _fractionalBits);
}