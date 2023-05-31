/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:26:43 by caboudar          #+#    #+#             */
/*   Updated: 2023/05/31 22:15:56 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed {

	public:
			Fixed();
			~Fixed();
			Fixed(Fixed const & cpy);
			Fixed & operator=(Fixed const & rhs);
			int getRawBits(void) const;
			void setRawBits(int const raw);
	private:
			int _value;
			static const int _fractionalBits;
};