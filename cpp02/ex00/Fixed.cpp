/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:31:25 by caboudar          #+#    #+#             */
/*   Updated: 2023/05/31 22:28:13 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed(): _value(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed::Fixed(Fixed const & cpy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed &	Fixed::operator=(Fixed const & rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	_value = rhs.getRawBits();
	return *this;
}

void Fixed::setRawBits(const int raw) { this->_value = raw; }

int	Fixed::getRawBits(void) const { 
	std::cout << "getRawBits member function called" << std::endl; 
	return _value;
}
