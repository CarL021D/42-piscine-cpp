/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:26:43 by caboudar          #+#    #+#             */
/*   Updated: 2023/07/30 17:24:33 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>

class Fixed {

	public:
			Fixed();
			~Fixed();
			Fixed(Fixed const &src);
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
			Fixed &operator--();
			Fixed operator++(int);
			Fixed operator--(int);

			int		getRawBits() const;
			int 	toInt() const;
			void	setRawBits(const int raw);
			float	toFloat() const;

			static Fixed &min(Fixed &obj1, Fixed &obj2);
			static Fixed &max(Fixed &obj1, Fixed &obj2);
			static const Fixed &min(Fixed const &obj1, Fixed const &obj2);
			static const Fixed &max(Fixed const &obj1, Fixed const &obj2);
	private:
			int _value;
			static const int _fractionalBits;
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);