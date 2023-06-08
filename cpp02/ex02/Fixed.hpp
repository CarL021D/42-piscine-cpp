/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:26:43 by caboudar          #+#    #+#             */
/*   Updated: 2023/06/02 04:23:04 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed {

	public:
			Fixed();
			~Fixed();
			Fixed(Fixed const &cpy);
			
			Fixed(const int value);
			Fixed(const float value);

			Fixed &operator=(Fixed const &rhs);
			
			Fixed &operator+(Fixed const &rhs);
			Fixed &operator-(Fixed const &rhs);
			Fixed &operator*(Fixed const &rhs);
			Fixed &operator/(Fixed const &rhs);

			bool operator>(Fixed const &rhs);
			bool operator>=(Fixed const &rhs);
			bool operator<(Fixed const &rhs);
			bool operator<=(Fixed const &rhs);
			bool operator==(Fixed const &rhs);
			bool operator!=(Fixed const &rhs);

			Fixed &operator++();
			Fixed operator++(int);
			Fixed &operator--();
			Fixed operator--(int);

			int getRawBits() const;
			void setRawBits(const int raw);
			float toFloat() const;
			int toInt() const;
			static Fixed min(Fixed &nb1, Fixed &nb2);
			static Fixed min(Fixed const &nb1, Fixed const &nb2);
			static Fixed max(Fixed &nb1, Fixed &nb2);
			static Fixed max(Fixed const &nb1, Fixed const &nb2);
	private:
			int _value;
			static const int _fractionalBits;
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);