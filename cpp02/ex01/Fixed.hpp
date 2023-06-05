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
			Fixed(Fixed const & cpy);
			
			Fixed(int value const);
			
			Fixed & operator=(Fixed const & rhs);
			Fixed & operator<<(os,);
			int getRawBits(void) const;
			void setRawBits(int const raw);
			float toFloat() const;
			int toInt() const;
	private:
			int _value;
			static const int _fractionalBits;
};